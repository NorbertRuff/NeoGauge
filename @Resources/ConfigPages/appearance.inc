; ============================================================
; Appearance page
; Edits one appearance file (#appFile#, picked with the tabs at the top).
; Settings.lua highlights the current value of every opt_<variable>_<value>
; meter, sizes the opacity bars and fills in usedBy.
; ============================================================

[Variables]
pageColor=89,186,255,230

; ------------------------------------------------------------
; Which appearance file

[opt_component_cpu]
Meter=String
MeterStyle=sText
X=(140*#s#)
Y=(20*#s#)
Text=cpu
LeftMouseUpAction=[!WriteKeyValue Variables component cpu "#stateFile#"][!Refresh]

[opt_component_threads]
Meter=String
MeterStyle=sText | sNext
Text=threads
LeftMouseUpAction=[!WriteKeyValue Variables component threads "#stateFile#"][!Refresh]

[opt_component_ram]
Meter=String
MeterStyle=sText | sNext
Text=ram
LeftMouseUpAction=[!WriteKeyValue Variables component ram "#stateFile#"][!Refresh]

[opt_component_io]
Meter=String
MeterStyle=sText | sNext
Text=I/O
LeftMouseUpAction=[!WriteKeyValue Variables component io "#stateFile#"][!Refresh]

[opt_component_disk]
Meter=String
MeterStyle=sText | sNext
Text=disks
LeftMouseUpAction=[!WriteKeyValue Variables component disk "#stateFile#"][!Refresh]

[opt_component_fan]
Meter=String
MeterStyle=sText | sNext
Text=temps & fans
LeftMouseUpAction=[!WriteKeyValue Variables component fan "#stateFile#"][!Refresh]

[opt_component_networkDown]
Meter=String
MeterStyle=sText
X=(140*#s#)
Y=(4*#s#)R
Text=download
LeftMouseUpAction=[!WriteKeyValue Variables component networkDown "#stateFile#"][!Refresh]

[opt_component_networkUp]
Meter=String
MeterStyle=sText | sNext
Text=upload
LeftMouseUpAction=[!WriteKeyValue Variables component networkUp "#stateFile#"][!Refresh]

[opt_component_wifi]
Meter=String
MeterStyle=sText | sNext
Text=wifi
LeftMouseUpAction=[!WriteKeyValue Variables component wifi "#stateFile#"][!Refresh]

[opt_component_battery]
Meter=String
MeterStyle=sText | sNext
Text=battery
LeftMouseUpAction=[!WriteKeyValue Variables component battery "#stateFile#"][!Refresh]

[opt_component_upTime]
Meter=String
MeterStyle=sText | sNext
Text=uptime
LeftMouseUpAction=[!WriteKeyValue Variables component upTime "#stateFile#"][!Refresh]

[opt_component_default]
Meter=String
MeterStyle=sText | sNext
Text=other
LeftMouseUpAction=[!WriteKeyValue Variables component default "#stateFile#"][!Refresh]

[usedBy]
Meter=String
MeterStyle=sText | sNote
X=(140*#s#)
Y=(6*#s#)R
W=(420*#s#)
ClipString=1
Text=

; ------------------------------------------------------------
; Orientation and font style (two columns)

[orientHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(96*#s#)
Text=Orientation
ToolTipText=Circle on the left or on the right of the text

[opt_orient_left]
Meter=String
MeterStyle=sText | sFirst
Text=left
LeftMouseUpAction=[!WriteKeyValue Variables orient left "#appFile#"][!RefreshGroup rsm]

[opt_orient_right]
Meter=String
MeterStyle=sText | sNext
Text=right
LeftMouseUpAction=[!WriteKeyValue Variables orient right "#appFile#"][!RefreshGroup rsm]

; Threads tab only: the grid has no left/right orientation, so Settings.lua
; shows this Layout row in the Orientation row's place
[layoutHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(96*#s#)
Text=Layout
ToolTipText=Rings per row in the CPU threads grid
Hidden=1

[opt_threadCols_4]
Meter=String
MeterStyle=sText | sFirst
Text=4 x 4
LeftMouseUpAction=[!WriteKeyValue Variables threadCols 4 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_threadCols_8]
Meter=String
MeterStyle=sText | sNext
Text=2 x 8
LeftMouseUpAction=[!WriteKeyValue Variables threadCols 8 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_threadCols_16]
Meter=String
MeterStyle=sText | sNext
Text=1 x 16
LeftMouseUpAction=[!WriteKeyValue Variables threadCols 16 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[fontStyleHeader]
Meter=String
MeterStyle=sText | sHeader
X=(360*#s#)
Y=(96*#s#)
Text=Font style

[opt_fontStyle_Normal]
Meter=String
MeterStyle=sText | sFirst
X=(360*#s#)
Text=normal
LeftMouseUpAction=[!WriteKeyValue Variables fontStyle Normal "#appFile#"][!RefreshGroup rsm]

[opt_fontStyle_Bold]
Meter=String
MeterStyle=sText | sNext
StringStyle=Bold
Text=bold
LeftMouseUpAction=[!WriteKeyValue Variables fontStyle Bold "#appFile#"][!RefreshGroup rsm]

[opt_fontStyle_Italic]
Meter=String
MeterStyle=sText | sNext
StringStyle=Italic
Text=italic
LeftMouseUpAction=[!WriteKeyValue Variables fontStyle Italic "#appFile#"][!RefreshGroup rsm]

; ------------------------------------------------------------
; Size

[sizeHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(142*#s#)
Text=Size
ToolTipText=Circle radius at 100% display scale. Width, height and fonts all follow it.

; Size presets are spaced with left Padding instead of X=(14*#s#)R, so a hidden
; preset takes no room: the threads tab hides 24-48 and shows 10-22 (Settings.lua)
[sSizeNext]
X=0R
Y=r
Padding=(14*#s#),0,0,0

[opt_size_24]
Meter=String
MeterStyle=sText | sFirst
Text=24
LeftMouseUpAction=[!WriteKeyValue Variables size 24 "#appFile#"][!RefreshGroup rsm]

[opt_size_28]
Meter=String
MeterStyle=sText | sSizeNext
Text=28
LeftMouseUpAction=[!WriteKeyValue Variables size 28 "#appFile#"][!RefreshGroup rsm]

[opt_size_32]
Meter=String
MeterStyle=sText | sSizeNext
Text=32
LeftMouseUpAction=[!WriteKeyValue Variables size 32 "#appFile#"][!RefreshGroup rsm]

[opt_size_36]
Meter=String
MeterStyle=sText | sSizeNext
Text=36
LeftMouseUpAction=[!WriteKeyValue Variables size 36 "#appFile#"][!RefreshGroup rsm]

[opt_size_48]
Meter=String
MeterStyle=sText | sSizeNext
Text=48
LeftMouseUpAction=[!WriteKeyValue Variables size 48 "#appFile#"][!RefreshGroup rsm]

[opt_size_10]
Meter=String
MeterStyle=sText
X=0R
Y=r
Text=10
LeftMouseUpAction=[!WriteKeyValue Variables size 10 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_size_12]
Meter=String
MeterStyle=sText | sSizeNext
Text=12
LeftMouseUpAction=[!WriteKeyValue Variables size 12 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_size_14]
Meter=String
MeterStyle=sText | sSizeNext
Text=14
LeftMouseUpAction=[!WriteKeyValue Variables size 14 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_size_18]
Meter=String
MeterStyle=sText | sSizeNext
Text=18
LeftMouseUpAction=[!WriteKeyValue Variables size 18 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_size_22]
Meter=String
MeterStyle=sText | sSizeNext
Text=22
LeftMouseUpAction=[!WriteKeyValue Variables size 22 "#appFile#"][!RefreshGroup rsm]
Hidden=1

[opt_size_custom]
Meter=String
MeterStyle=sText | sSizeNext
Text=custom: #size#
ToolTipText=Type any radius
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 4"]

; ------------------------------------------------------------
; Margins

[edgingHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(188*#s#)
Text=Margins
ToolTipText=Empty space around the gauge, as a share of the radius

[opt_edging_0]
Meter=String
MeterStyle=sText | sFirst
Text=none
LeftMouseUpAction=[!WriteKeyValue Variables edging 0 "#appFile#"][!RefreshGroup rsm]

[opt_edging_10]
Meter=String
MeterStyle=sText | sNext
Text=10%
LeftMouseUpAction=[!WriteKeyValue Variables edging "(#*radius*#*0.1)" "#appFile#"][!RefreshGroup rsm]

[opt_edging_20]
Meter=String
MeterStyle=sText | sNext
Text=20%
LeftMouseUpAction=[!WriteKeyValue Variables edging "(#*radius*#*0.2)" "#appFile#"][!RefreshGroup rsm]

[opt_edging_30]
Meter=String
MeterStyle=sText | sNext
Text=30%
LeftMouseUpAction=[!WriteKeyValue Variables edging "(#*radius*#*0.3)" "#appFile#"][!RefreshGroup rsm]

[opt_edging_custom]
Meter=String
MeterStyle=sText | sNext
Text=custom
ToolTipText=Type a share of the radius, e.g. 0.15
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 5"]

; ------------------------------------------------------------
; Colors: swatch, name, value (click to type), opacity bar (click to set)

[colorHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(234*#s#)
Text=Colors
ToolTipText=Colors are R,G,B,A (0-255). Text colors follow the arc and ring colors.

[sSwatch]
X=(140*#s#)
W=(18*#s#)
H=(18*#s#)

[sColorName]
X=(168*#s#)
FontFace=Segoe UI
FontSize=(10*#s#)
FontColor=#dimColor#

[sColorText]
X=(240*#s#)
FontSize=(10*#s#)

[sAlphaBg]
X=(400*#s#)
W=(140*#s#)
H=(5*#s#)
SolidColor=#lineColor#
ToolTipText=Opacity: click along the bar

[sAlpha]
X=r
Y=r
W=0
H=(5*#s#)
SolidColor=#textColor#

[c1Swatch]
Meter=Image
MeterStyle=sSwatch
Y=(260*#s#)
SolidColor=#pieColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 1"]

[c1Name]
Meter=String
MeterStyle=sText | sColorName
Y=(260*#s#)
Text=arc

[c1Text]
Meter=String
MeterStyle=sText | sColorText
Y=(260*#s#)
Text=#pieColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 1"]

[c1AlphaBg]
Meter=Image
MeterStyle=sAlphaBg
Y=(267*#s#)
LeftMouseUpAction=[!CommandMeasure mScript "changeAlpha('pieColor', $MouseX:%$)"]

[c1Alpha]
Meter=Image
MeterStyle=sAlpha

[c2Swatch]
Meter=Image
MeterStyle=sSwatch
Y=(286*#s#)
SolidColor=#innerRingColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 2"]

[c2Name]
Meter=String
MeterStyle=sText | sColorName
Y=(286*#s#)
Text=rings

[c2Text]
Meter=String
MeterStyle=sText | sColorText
Y=(286*#s#)
Text=#innerRingColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 2"]

[c2AlphaBg]
Meter=Image
MeterStyle=sAlphaBg
Y=(293*#s#)
LeftMouseUpAction=[!CommandMeasure mScript "changeAlpha('innerRingColor', $MouseX:%$)"]

[c2Alpha]
Meter=Image
MeterStyle=sAlpha

[c3Swatch]
Meter=Image
MeterStyle=sSwatch
Y=(312*#s#)
SolidColor=#pieBgColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 3"]

[c3Name]
Meter=String
MeterStyle=sText | sColorName
Y=(312*#s#)
Text=arc track

[c3Text]
Meter=String
MeterStyle=sText | sColorText
Y=(312*#s#)
Text=#pieBgColor#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 3"]

[c3AlphaBg]
Meter=Image
MeterStyle=sAlphaBg
Y=(319*#s#)
LeftMouseUpAction=[!CommandMeasure mScript "changeAlpha('pieBgColor', $MouseX:%$)"]

[c3Alpha]
Meter=Image
MeterStyle=sAlpha

; ------------------------------------------------------------
; Presets: arc, rings, track

[presetsHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(350*#s#)
Text=Presets

[sPreset]
X=(4*#s#)R
Y=r
W=(36*#s#)
H=(14*#s#)

[preset1]
Meter=Image
MeterStyle=sPreset
X=(140*#s#)
Y=(4*#s#)R
SolidColor=250,250,250,230
LeftMouseUpAction=[!CommandMeasure mScript "setColors('250,250,250,230', '250,250,250,155', '100,100,100,51')"]

[preset2]
Meter=Image
MeterStyle=sPreset
SolidColor=252,212,75,230
LeftMouseUpAction=[!CommandMeasure mScript "setColors('252,212,75,230', '250,250,250,155', '100,100,100,51')"]

[preset3]
Meter=Image
MeterStyle=sPreset
SolidColor=182,200,80,230
LeftMouseUpAction=[!CommandMeasure mScript "setColors('182,200,80,230', '250,250,250,155', '100,100,100,51')"]

[preset4]
Meter=Image
MeterStyle=sPreset
SolidColor=89,186,255,230
LeftMouseUpAction=[!CommandMeasure mScript "setColors('89,186,255,230', '250,250,250,155', '100,100,100,51')"]

[preset5]
Meter=Image
MeterStyle=sPreset
SolidColor=250,100,100,230
LeftMouseUpAction=[!CommandMeasure mScript "setColors('250,100,100,230', '250,250,250,155', '100,100,100,51')"]

[preset6]
Meter=Image
MeterStyle=sPreset
SolidColor=10,200,200,200
LeftMouseUpAction=[!CommandMeasure mScript "setColors('10,200,200,200', '5,188,200,180', '100,100,100,51')"]

[preset7]
Meter=Image
MeterStyle=sPreset
SolidColor=204,100,8,209
LeftMouseUpAction=[!CommandMeasure mScript "setColors('204,100,8,209', '20,20,20,127', '100,100,100,43')"]

[preset8]
Meter=Image
MeterStyle=sPreset
SolidColor=99,130,55,234
LeftMouseUpAction=[!CommandMeasure mScript "setColors('99,130,55,234', '20,20,20,153', '100,100,100,43')"]

[preset9]
Meter=Image
MeterStyle=sPreset
SolidColor=57,76,128,211
LeftMouseUpAction=[!CommandMeasure mScript "setColors('57,76,128,211', '20,20,20,186', '100,100,100,43')"]

[preset10]
Meter=Image
MeterStyle=sPreset
SolidColor=117,53,46,234
LeftMouseUpAction=[!CommandMeasure mScript "setColors('117,53,46,234', '20,20,20,204', '100,100,100,76')"]

; ------------------------------------------------------------
; Show / hide parts (Settings.lua dims the hidden ones)

[showHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(398*#s#)
Text=Show
ToolTipText=Click a part to show or hide it

[tog_hideInnerEdge]
Meter=String
MeterStyle=sText | sFirst
Text=inner ring
LeftMouseUpAction=[!CommandMeasure mScript "toggle('hideInnerEdge', 'app')"]

[tog_hideOuterEdge]
Meter=String
MeterStyle=sText | sNext
Text=outer ring
LeftMouseUpAction=[!CommandMeasure mScript "toggle('hideOuterEdge', 'app')"]

[tog_hidePieBg]
Meter=String
MeterStyle=sText | sNext
Text=arc track
LeftMouseUpAction=[!CommandMeasure mScript "toggle('hidePieBg', 'app')"]

[tog_hideDivider]
Meter=String
MeterStyle=sText | sNext
Text=divider
LeftMouseUpAction=[!CommandMeasure mScript "toggle('hideDivider', 'app')"]

[tog_hideSubText]
Meter=String
MeterStyle=sText | sNext
Text=second line
LeftMouseUpAction=[!CommandMeasure mScript "toggle('hideSubText', 'app')"]

; ------------------------------------------------------------
; Icon (disks, download and upload tabs only; Settings.lua shows the row
; and tints the current one). Images live in @Resources\Icons.

[iconHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(446*#s#)
Text=Icon
Hidden=1

[sIcon]
X=(12*#s#)R
Y=r
W=(24*#s#)
H=(24*#s#)
PreserveAspectRatio=1
ImageTint=#dimColor#
SolidColor=0,0,0,1
Hidden=1

[ico_disk_classic]
Meter=Image
MeterStyle=sIcon
X=(140*#s#)
Y=(470*#s#)
ImageName=#@#Icons\disk-classic.png
ToolTipText=classic
LeftMouseUpAction=[!WriteKeyValue Variables icon classic "#appFile#"][!RefreshGroup rsm]

[ico_disk_harddisk]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\disk-harddisk.png
ToolTipText=hard disk
LeftMouseUpAction=[!WriteKeyValue Variables icon harddisk "#appFile#"][!RefreshGroup rsm]

[ico_disk_hdd]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\disk-hdd.png
ToolTipText=drive
LeftMouseUpAction=[!WriteKeyValue Variables icon hdd "#appFile#"][!RefreshGroup rsm]

[ico_disk_database]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\disk-database.png
ToolTipText=database
LeftMouseUpAction=[!WriteKeyValue Variables icon database "#appFile#"][!RefreshGroup rsm]

[ico_disk_server]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\disk-server.png
ToolTipText=server
LeftMouseUpAction=[!WriteKeyValue Variables icon server "#appFile#"][!RefreshGroup rsm]

; Network: one choice writes both files, so download and upload always match
[ico_net_classic]
Meter=Image
MeterStyle=sIcon
X=(140*#s#)
Y=(470*#s#)
ImageName=#@#Icons\down-classic.png
ToolTipText=classic (download and upload)
LeftMouseUpAction=[!WriteKeyValue Variables icon classic "#@#Apparence\networkDown.txt"][!WriteKeyValue Variables icon classic "#@#Apparence\networkUp.txt"][!RefreshGroup rsm]

[ico_net_bold]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\down-bold.png
ToolTipText=bold arrows (download and upload)
LeftMouseUpAction=[!WriteKeyValue Variables icon bold "#@#Apparence\networkDown.txt"][!WriteKeyValue Variables icon bold "#@#Apparence\networkUp.txt"][!RefreshGroup rsm]

[ico_net_tray]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\down-tray.png
ToolTipText=tray (download and upload)
LeftMouseUpAction=[!WriteKeyValue Variables icon tray "#@#Apparence\networkDown.txt"][!WriteKeyValue Variables icon tray "#@#Apparence\networkUp.txt"][!RefreshGroup rsm]

[ico_net_circle]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\down-circle.png
ToolTipText=circle (download and upload)
LeftMouseUpAction=[!WriteKeyValue Variables icon circle "#@#Apparence\networkDown.txt"][!WriteKeyValue Variables icon circle "#@#Apparence\networkUp.txt"][!RefreshGroup rsm]

[ico_net_network]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\down-network.png
ToolTipText=network (download and upload)
LeftMouseUpAction=[!WriteKeyValue Variables icon network "#@#Apparence\networkDown.txt"][!WriteKeyValue Variables icon network "#@#Apparence\networkUp.txt"][!RefreshGroup rsm]

[ico_net_cloud]
Meter=Image
MeterStyle=sIcon
ImageName=#@#Icons\down-cloud.png
ToolTipText=cloud (download and upload)
LeftMouseUpAction=[!WriteKeyValue Variables icon cloud "#@#Apparence\networkDown.txt"][!WriteKeyValue Variables icon cloud "#@#Apparence\networkUp.txt"][!RefreshGroup rsm]
