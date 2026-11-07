<#
.SYNOPSIS
  Builds dist\NeoGauge_<version>.rmskin from the working tree.

.DESCRIPTION
  Packs every file git tracks or would track (so new files count before they are
  committed), minus the dev-only ones, into the .rmskin layout Rainmeter's Skin
  Installer reads: a zip with RMSKIN.ini and Skins\NeoGauge\..., followed by a
  16-byte footer (int64 zip length, flags byte 0, "RMSKIN\0"). The format comes
  from Rainmeter's Library\DialogPackage.cpp / DialogInstall.cpp.

  VariableFiles lists Settings.txt and every appearance file: on an update the
  installer copies the user's old values into them for keys both versions have.
  ConfigState.inc (git-ignored window state) is written fresh with defaults.

.PARAMETER Version
  Defaults to componentVersion in Config.ini.
#>
param([string]$Version)

$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.IO.Compression, System.IO.Compression.FileSystem

$root = Split-Path -Parent $PSScriptRoot
Push-Location $root
try {
    if (-not $Version) {
        $Version = (Select-String -Path 'Config.ini' -Pattern '^componentVersion=(.+)$').Matches[0].Groups[1].Value.Trim()
    }

    # Dev-only files that stay out of the package
    $exclude = '^(tools/|Debug/|blob/|@Resources/Images/|NeoGauge_.*\.rmskin$|TODO\.md$|\.gitignore$)'
    $files = git ls-files --cached --others --exclude-standard |
        Where-Object { $_ -notmatch $exclude -and (Test-Path -LiteralPath $_ -PathType Leaf) } |
        Sort-Object -Unique

    $variableFiles = @('@Resources/Settings.txt') +
        ($files | Where-Object { $_ -match '^@Resources/Apparence/[^/]+\.txt$' })
    foreach ($v in $variableFiles) {
        if ($files -notcontains $v) { throw "Variable file not in package: $v" }
    }

    $rmskinIni = @(
        '[rmskin]'
        'Name=NeoGauge'
        'Author=NorbertRuff'
        "Version=$Version"
        'LoadType=Skin'
        'Load=NeoGauge\Config.ini'
        'VariableFiles=' + (($variableFiles | ForEach-Object { 'NeoGauge\' + ($_ -replace '/', '\') }) -join ' | ')
        'MinimumRainmeter=4.5.18.3727'
        'MinimumWindows=6.1'
    ) -join "`r`n"

    $state = "[Variables]`r`npage=info`r`ncomponent=cpu`r`nsensorSlot=1`r`n"

    New-Item -ItemType Directory -Force dist | Out-Null
    $out = Join-Path $root "dist\NeoGauge_$Version.rmskin"
    if (Test-Path $out) { Remove-Item $out }

    $stream = [IO.File]::Open($out, 'CreateNew')
    $zip = New-Object IO.Compression.ZipArchive($stream, [IO.Compression.ZipArchiveMode]::Create, $true)
    function Add-Text($name, $text) {
        $w = New-Object IO.StreamWriter($zip.CreateEntry($name).Open(), (New-Object Text.UTF8Encoding($false)))
        $w.Write($text); $w.Dispose()
    }
    Add-Text 'RMSKIN.ini' $rmskinIni
    foreach ($f in $files) {
        [IO.Compression.ZipFileExtensions]::CreateEntryFromFile($zip, (Join-Path $root $f), "Skins/NeoGauge/$f", 'Optimal') | Out-Null
    }
    Add-Text 'Skins/NeoGauge/@Resources/ConfigState.inc' $state
    $zip.Dispose()

    # Footer: zip length, flags, key
    $zipLength = $stream.Length
    $footer = [BitConverter]::GetBytes([long]$zipLength) + [byte[]](0) + [Text.Encoding]::ASCII.GetBytes("RMSKIN`0")
    $stream.Seek(0, 'End') | Out-Null
    $stream.Write($footer, 0, $footer.Length)
    $stream.Dispose()

    $hash = (Get-FileHash $out -Algorithm SHA256).Hash
    '{0}  {1:N0} KB, {2} files' -f $out, ((Get-Item $out).Length / 1KB), ($files.Count + 1)
    "SHA256 $hash"
}
finally {
    Pop-Location
}
