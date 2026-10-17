; ============================================================
; System page: values in @Resources\Settings.txt shared by all skins
; ============================================================

[Variables]
pageColor=183,234,93,230

; ------------------------------------------------------------
; Display scale

[scaleHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(20*#s#)
Text=Display scale
ToolTipText=Match your Windows display scale (Settings > Display > Scale).

[opt_scale_1]
Meter=String
MeterStyle=sText | sFirst
Text=100%
LeftMouseUpAction=[!WriteKeyValue Variables scale 1 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_scale_1_25]
Meter=String
MeterStyle=sText | sNext
Text=125%
LeftMouseUpAction=[!WriteKeyValue Variables scale 1.25 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_scale_1_5]
Meter=String
MeterStyle=sText | sNext
Text=150%
LeftMouseUpAction=[!WriteKeyValue Variables scale 1.5 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_scale_2]
Meter=String
MeterStyle=sText | sNext
Text=200%
LeftMouseUpAction=[!WriteKeyValue Variables scale 2 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_scale_custom]
Meter=String
MeterStyle=sText | sNext
Text=custom: #scale#
ToolTipText=Type a multiplier, e.g. 1.75
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 15"]

[scaleNote]
Meter=String
MeterStyle=sText | sNote
X=(140*#s#)
Y=(4*#s#)R
Text=Above 100% this needs Rainmeter.exe > Properties > Compatibility >#CRLF#Change high DPI settings > Override: Application. Otherwise Windows blurs the skins.

; ------------------------------------------------------------
; Fonts

[fontHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(104*#s#)
Text=Fonts
ToolTipText=Any installed font, or one in @Resources\Fonts. Click a name to type a new one.

[mainFontLabel]
Meter=String
MeterStyle=sText | sFirst | sNote
FontSize=(10*#s#)
Text=main

[mainFont]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=#mainFont#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 16"]

[subFontLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=small text

[subFont]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
FontFace=#subFont#
Text=#subFont#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 17"]

; ------------------------------------------------------------
; Drives

[drivesHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(160*#s#)
Text=Drives
ToolTipText=Drive letters shown by the Disks skins 1-5. Click one to change it.

[hd1]
Meter=String
MeterStyle=sText | sFirst
Text=#hd1#:\
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 6"]

[hd2]
Meter=String
MeterStyle=sText | sNext
Text=#hd2#:\
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 7"]

[hd3]
Meter=String
MeterStyle=sText | sNext
Text=#hd3#:\
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 8"]

[hd4]
Meter=String
MeterStyle=sText | sNext
Text=#hd4#:\
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 9"]

[hd5]
Meter=String
MeterStyle=sText | sNext
Text=#hd5#:\
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 10"]

; ------------------------------------------------------------
; Network (Settings.lua fills in the Mb/s values)

[netHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(216*#s#)
Text=Connection speed
ToolTipText=Your line's top speed in megabits per second; the network gauges show traffic as a share of it.

[uploadLabel]
Meter=String
MeterStyle=sText | sFirst | sNote
FontSize=(10*#s#)
Text=upload

[uploadMax]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Postfix=" Mb/s"
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 11"]

[downloadLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=download

[downloadMax]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Postfix=" Mb/s"
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 12"]

; ------------------------------------------------------------
; Fans

[fanHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(272*#s#)
Text=Fan top speed
ToolTipText=RPM that fills the fan gauges to 100%

[fanMaxRpm]
Meter=String
MeterStyle=sText | sFirst
Text=#fanMaxRpm#
Postfix=" RPM"
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 18"]

; ------------------------------------------------------------
; Recycle Bin

[binHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(328*#s#)
Text=Recycle Bin
ToolTipText=The bin gauge shows its size as a share of this maximum.

[opt_trashMax_536870912]
Meter=String
MeterStyle=sText | sFirst
Text=512 MB
LeftMouseUpAction=[!WriteKeyValue Variables trashMax 536870912 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_trashMax_1073741824]
Meter=String
MeterStyle=sText | sNext
Text=1 GB
LeftMouseUpAction=[!WriteKeyValue Variables trashMax 1073741824 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_trashMax_2147483648]
Meter=String
MeterStyle=sText | sNext
Text=2 GB
LeftMouseUpAction=[!WriteKeyValue Variables trashMax 2147483648 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_trashMax_5368709120]
Meter=String
MeterStyle=sText | sNext
Text=5 GB
LeftMouseUpAction=[!WriteKeyValue Variables trashMax 5368709120 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_trashMax_10737418240]
Meter=String
MeterStyle=sText | sNext
Text=10 GB
LeftMouseUpAction=[!WriteKeyValue Variables trashMax 10737418240 "#@#Settings.txt"][!RefreshGroup rsm]

[tog_trashAutoEmpty]
Meter=String
MeterStyle=sText | sFirst
Text=empty automatically when full
ToolTipText=Permanently deletes the bin's contents, without asking, once it grows past the maximum
LeftMouseUpAction=[!CommandMeasure mScript "toggle('trashAutoEmpty', 'settings')"]
