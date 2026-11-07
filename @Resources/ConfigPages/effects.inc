; ============================================================
; Effects page: ring animation and effects for every gauge
; (fx* variables in @Resources\Settings.txt, used by ringTemplate.inc)
; ============================================================

[Variables]
pageColor=200,140,255,230

[presetHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(20*#s#)
Text=Presets
ToolTipText=Sets all the options below at once

[opt_fxPreset_off]
Meter=String
MeterStyle=sText | sFirst
Text=off
ToolTipText=Rings jump once a second, like the original skin. Lightest.
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('off')"]

[opt_fxPreset_light]
Meter=String
MeterStyle=sText | sNext
Text=light
ToolTipText=Smooth motion only
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('light')"]

[opt_fxPreset_balanced]
Meter=String
MeterStyle=sText | sNext
Text=balanced
ToolTipText=Smooth motion, glow under load, peak hold and afterglow
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('balanced')"]

[opt_fxPreset_everything]
Meter=String
MeterStyle=sText | sNext
Text=everything
ToolTipText=Everything, including the comet arc and round ends. Heaviest.
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('everything')"]

[costNote]
Meter=String
MeterStyle=sText | sNote
X=(140*#s#)
Y=(4*#s#)R
W=(420*#s#)
ClipString=2
Text=A gauge only animates while its ring is moving (20 frames a second), then goes idle. Busy gauges such as CPU and network animate most.

; ------------------------------------------------------------

[motionHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(116*#s#)
Text=Motion

[tog_fxSmooth]
Meter=String
MeterStyle=sText | sFirst
Text=smooth
ToolTipText=The ring glides to each new reading instead of jumping
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxSmooth', 'settings')"]

[speedLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=speed

[opt_fxEaseMs_150]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=fast
LeftMouseUpAction=[!WriteKeyValue Variables fxEaseMs 150 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxEaseMs_280]
Meter=String
MeterStyle=sText | sNext
Text=normal
LeftMouseUpAction=[!WriteKeyValue Variables fxEaseMs 280 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxEaseMs_500]
Meter=String
MeterStyle=sText | sNext
Text=slow
LeftMouseUpAction=[!WriteKeyValue Variables fxEaseMs 500 "#@#Settings.txt"][!RefreshGroup rsm]

; ------------------------------------------------------------

[glowHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(172*#s#)
Text=Glow
ToolTipText=A soft halo in the arc's own color

[opt_fxGlow_0]
Meter=String
MeterStyle=sText | sFirst
Text=off
LeftMouseUpAction=[!WriteKeyValue Variables fxGlow 0 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlow_1]
Meter=String
MeterStyle=sText | sNext
Text=always
LeftMouseUpAction=[!WriteKeyValue Variables fxGlow 1 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlow_2]
Meter=String
MeterStyle=sText | sNext
Text=grows with load
ToolTipText=None below 55 %, full at 90 %
LeftMouseUpAction=[!WriteKeyValue Variables fxGlow 2 "#@#Settings.txt"][!RefreshGroup rsm]

[strengthLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=strength

[opt_fxGlowStrength_0_4]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=subtle
LeftMouseUpAction=[!WriteKeyValue Variables fxGlowStrength 0.4 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlowStrength_0_6]
Meter=String
MeterStyle=sText | sNext
Text=medium
LeftMouseUpAction=[!WriteKeyValue Variables fxGlowStrength 0.6 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlowStrength_0_9]
Meter=String
MeterStyle=sText | sNext
Text=strong
LeftMouseUpAction=[!WriteKeyValue Variables fxGlowStrength 0.9 "#@#Settings.txt"][!RefreshGroup rsm]

; ------------------------------------------------------------

[extrasHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(228*#s#)
Text=Extras
ToolTipText=Click to switch each one on or off

[tog_fxPeak]
Meter=String
MeterStyle=sText | sFirst
Text=peak hold
ToolTipText=A tick marks the recent high for 3 s, then slides back
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxPeak', 'settings')"]

[tog_fxAfterglow]
Meter=String
MeterStyle=sText | sNext
Text=afterglow
ToolTipText=When a value drops, the old arc fades out instead of vanishing
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxAfterglow', 'settings')"]

[tog_fxComet]
Meter=String
MeterStyle=sText | sNext
Text=comet
ToolTipText=The arc brightens toward a glowing tip. The heaviest effect.
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxComet', 'settings')"]

[tog_fxRoundCaps]
Meter=String
MeterStyle=sText | sNext
Text=round ends
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxRoundCaps', 'settings')"]

; ------------------------------------------------------------
; Warning levels and colors (warnLevel / alertLevel / warnColor / alertColor
; in Settings.txt), shared by every ring that shows them and the threads grid

[warnHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(284*#s#)
Text=Warnings
ToolTipText=When a ring turns yellow and red (not battery, wifi, volume or clock). Temperature and fan gauges use their own levels below.

[warnLabel]
Meter=String
MeterStyle=sText | sFirst | sNote
FontSize=(10*#s#)
Text=yellow from

[opt_warnLevel_60]
Meter=String
MeterStyle=sText | sNext
Text=60
LeftMouseUpAction=[!WriteKeyValue Variables warnLevel 60 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_warnLevel_70]
Meter=String
MeterStyle=sText | sNext
Text=70
LeftMouseUpAction=[!WriteKeyValue Variables warnLevel 70 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_warnLevel_75]
Meter=String
MeterStyle=sText | sNext
Text=75
LeftMouseUpAction=[!WriteKeyValue Variables warnLevel 75 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_warnLevel_80]
Meter=String
MeterStyle=sText | sNext
Text=80 %
LeftMouseUpAction=[!WriteKeyValue Variables warnLevel 80 "#@#Settings.txt"][!RefreshGroup rsm]

[alertLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(28*#s#)R
Text=red from

[opt_alertLevel_85]
Meter=String
MeterStyle=sText | sNext
Text=85
LeftMouseUpAction=[!WriteKeyValue Variables alertLevel 85 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_alertLevel_90]
Meter=String
MeterStyle=sText | sNext
Text=90
LeftMouseUpAction=[!WriteKeyValue Variables alertLevel 90 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_alertLevel_95]
Meter=String
MeterStyle=sText | sNext
Text=95 %
LeftMouseUpAction=[!WriteKeyValue Variables alertLevel 95 "#@#Settings.txt"][!RefreshGroup rsm]

; Colors: click the swatch or the text to type a new R,G,B,A

[warnSwatch]
Meter=Image
X=(140*#s#)
Y=(342*#s#)
W=(18*#s#)
H=(18*#s#)
SolidColor=#warnColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 20"]

[warnText]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(10*#s#)R
Y=(340*#s#)
Text=#warnColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 20"]

[alertSwatch]
Meter=Image
X=(360*#s#)
Y=(342*#s#)
W=(18*#s#)
H=(18*#s#)
SolidColor=#alertColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 21"]

[alertText]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(10*#s#)R
Y=(340*#s#)
Text=#alertColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 21"]

; ------------------------------------------------------------
; Own levels for the temperature and fan gauges (chipTempWarn ... fanAlert in
; Settings.txt). Click a number to type a new one (mInput commands 22-31).

[ownHeader]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(140*#s#)
Y=(376*#s#)
Text=own levels
ToolTipText=These gauges use their own levels instead of the % ones above

[ownWarnHeader]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(300*#s#)
Y=r
Text=yellow

[ownAlertHeader]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(360*#s#)
Y=r
Text=red

[chipTempLabel]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(140*#s#)
Y=(398*#s#)
Text=CPU, GPU
ToolTipText=CPU and GPU temperature

[chipTempWarn]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#warnColor#
X=(300*#s#)
Y=r
Text=#chipTempWarn#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 22"]

[chipTempAlert]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#alertColor#
X=(360*#s#)
Y=r
Text=#chipTempAlert#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 23"]

[chipTempUnit]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(420*#s#)
Y=r
Text=degrees

[ramTempLabel]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(140*#s#)
Y=(422*#s#)
Text=RAM
ToolTipText=RAM (DIMM) temperature

[ramTempWarn]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#warnColor#
X=(300*#s#)
Y=r
Text=#ramTempWarn#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 24"]

[ramTempAlert]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#alertColor#
X=(360*#s#)
Y=r
Text=#ramTempAlert#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 25"]

[ramTempUnit]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(420*#s#)
Y=r
Text=degrees

[driveTempLabel]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(140*#s#)
Y=(446*#s#)
Text=drives
ToolTipText=Drive temperature. Hard disks like to stay under 50

[driveTempWarn]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#warnColor#
X=(300*#s#)
Y=r
Text=#driveTempWarn#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 26"]

[driveTempAlert]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#alertColor#
X=(360*#s#)
Y=r
Text=#driveTempAlert#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 27"]

[driveTempUnit]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(420*#s#)
Y=r
Text=degrees

[coolantTempLabel]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(140*#s#)
Y=(470*#s#)
Text=coolant
ToolTipText=Pump gauge: liquid cooler coolant temperature

[coolantTempWarn]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#warnColor#
X=(300*#s#)
Y=r
Text=#coolantTempWarn#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 28"]

[coolantTempAlert]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#alertColor#
X=(360*#s#)
Y=r
Text=#coolantTempAlert#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 29"]

[coolantTempUnit]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(420*#s#)
Y=r
Text=degrees

[fanLabel]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
X=(140*#s#)
Y=(494*#s#)
Text=fans
ToolTipText=Fans 1-4, in % of the max rpm on the system page. A busy fan is not a fault

[fanWarn]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#warnColor#
X=(300*#s#)
Y=r
Text=#fanWarn#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 30"]

[fanAlert]
Meter=String
MeterStyle=sText
FontSize=(10*#s#)
FontColor=#alertColor#
X=(360*#s#)
Y=r
Text=#fanAlert#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 31"]

[fanUnit]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(420*#s#)
Y=r
Text=% of max rpm

