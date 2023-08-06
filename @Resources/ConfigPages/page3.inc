[Variables]
bgH=300
dotY=80
highlightColor=183,234,93,230

; ============================================================
; Hard drive letters

[disksHeader]
Meter=String
MeterStyle=headerText
X=130
Y=40
Text=Hard Drives
ToolTipText="The drive letters of the hard drives/ partitions you wish to monitor with the 'Disks' skins"

[disk1]
Meter=String
MeterStyle=subText
X=r
Y=40
W=25
H=18
Text=#hd1#:\
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 1"
ToolTipText="click to set disk 1"

[disk2]
Meter=String
MeterStyle=subText
X=170
Text=#hd2#:\
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 2"
ToolTipText="click to set disk 2"

[disk3]
Meter=String
MeterStyle=subText
X=210
Text=#hd3#:\
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 3"
ToolTipText="click to set disk 3"

; ============================================================
; Recycle Bin Size

[binHeader]
Meter=String
MeterStyle=headerText
X=130
Y=95
Text=Recycle Bin Size
ToolTipText="Maximum desired size of the Windows Recycle Bin.  (The Recycle Bin skin will attempt to automatically empty the Recycle Bin if its size exceed this value)"

[bin512]
Meter=String
MeterStyle=subText
X=r
Y=r
Text=512 MB
LeftMouseUpAction=[!WriteKeyValue "Variables" "trashMax" "536870912" "#@#Settings.txt"][!Refresh "CircuitousTwo\Recycle Bin"][!Refresh #CURRENTCONFIG#]

[bin1]
Meter=String
MeterStyle=subText
X=5R
Text=1 GB
LeftMouseUpAction=[!WriteKeyValue "Variables" "trashMax" "1073741824" "#@#Settings.txt"][!Refresh "CircuitousTwo\Recycle Bin"][!Refresh #CURRENTCONFIG#]

[bin2]
Meter=String
MeterStyle=subText
X=5R
Text=2 GB
LeftMouseUpAction=[!WriteKeyValue "Variables" "trashMax" "2147483648" "#@#Settings.txt"][!Refresh "CircuitousTwo\Recycle Bin"][!Refresh #CURRENTCONFIG#]

[bin5]
Meter=String
MeterStyle=subText
X=5R
Text=5 GB
LeftMouseUpAction=[!WriteKeyValue "Variables" "trashMax" "5368709120" "#@#Settings.txt"][!Refresh "CircuitousTwo\Recycle Bin"][!Refresh #CURRENTCONFIG#]

; ============================================================
; Network Speeds

[netspeedHeader]
Meter=String
MeterStyle=headerText
X=130
Y=150
Text=Network Speeds
ToolTipText="Maximum speeds used in the Network skins."

[uploadMaxDisplay]
Meter=String
MeterStyle=subText
X=r
Y=r
Prefix="upload: "
Postfix=" Mb/s"
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 4"

[downloadMaxDisplay]
Meter=String
MeterStyle=subText
X=r
Y=R
Prefix="download: "
Postfix=" Mb/s"
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 5"

; ============================================================
; Media Player

[mediaplayerHeader]
Meter=String
MeterStyle=headerText
X=130
Y=225
Text=Media Player
LeftMouseUpAction=["http://docs.rainmeter.net/manual/plugins/nowplaying#playerlist"]
ToolTipText="Selects which media player should be interfaced by the NowPlaying skin.#CRLF#Click to go to the full list of supported media players"

[aimp]
Meter=String
MeterStyle=subText
Text=AIMP
LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "AIMP" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
ToolTipText=AIMP

[cad]
Meter=String
MeterStyle=subText
Text=CAD
LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "CAD" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
ToolTipText="foobar2000 (w/ plugin), J. River Media Center and Media Jukebox (w/ plugin), MusicBee, VLC (w/ plugin)"
X=2R

[iTunes]
Meter=String
MeterStyle=subText
Text=iTunes
LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "iTunes" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
ToolTipText=iTunes
X=2R

[wmp]
Meter=String
MeterStyle=subText
Text=WMP
LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "WMP" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
ToolTipText=Windows Media Player
X=2R

[mediaMonkey]
Meter=String
MeterStyle=subText
Text=MediaMonkey
LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "MediaMonkey" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
ToolTipText=MediaMonkey
X=130
Y=R

[Winamp]
Meter=String
MeterStyle=subText
Text=Winamp
LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "Winamp" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
ToolTipText=Winamp
X=2R

; [wlm]
; Meter=String
; MeterStyle=subText
; Text=WLM
; LeftMouseUpAction=[!WriteKeyValue "Variables" "mediaPlayer" "WLM" "#@#Settings.txt"][!Refresh "\CircuitousTwo\NowPlaying"][!Refresh #CURRENTCONFIG#]
; ToolTipText="Partial Support: Last.fm client, Media Player Classic, TTPLayer, OpenPandora, Zune"
; X=2R