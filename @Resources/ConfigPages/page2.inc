[Variables]
bgH=470
dotY=55
highlightColor=89,186,255,230
;highlightColor=93,208,234,230

; ============================================================
; orientation setting

[orientHeader]
Meter=String
MeterStyle=headerText
X=130
Y=40
Text=Orientation
ToolTipText="All the Circuitous skins can be oriented with the circle on either the left or on the right"

[leftCircleBg]
Meter=Image
SolidColor=0,0,0,100
X=130
Y=r
W=80
H=40
LeftMouseUpAction=[!WriteKeyValue Variables orient left "#@#Appearance.txt"][!RefreshGroup circa2]

[rightCircleBg]
Meter=Image
MeterStyle=leftCircleBg
X=220
Y=r
LeftMouseUpAction=[!WriteKeyValue Variables orient right "#@#Appearance.txt"][!RefreshGroup circa2]

[leftLine]
Meter=IMAGE
SolidColor=#dimColor#
X=165
Y=60
W=40
H=1

[leftCircle]
Meter=Roundline
StartAngle=0
RotationAngle=6.28
LineLength=15
LineStart=14
AntiAlias=1
Solid=1
LineColor=#dimColor#
X=135
Y=45
W=30
H=30

[leftText]
Meter=String
MeterStyle=subText
Text=left
X=166
Y=61
StringAlign=LeftBottom
FontSize=9

[rightLine]
Meter=IMAGE
MeterStyle=leftLine
X=225

[rightCircle]
Meter=Roundline
MeterStyle=leftCircle
X=265

[rightText]
Meter=String
MeterStyle=subText
StringAlign=RightBottom
FontSize=9
Text=right
X=264
Y=61

; ============================================================
; skin size / radius

[sizeHeader]
Meter=String
MeterStyle=headerText
X=130
Y=115
Text=Circle Radius
ToolTipText="The radius of the circle meter in the skins (in pixels).  The size of the skin (width, height, and font sizes) are all automatically scaled to this value."

[r24]
Meter=String
MeterStyle=subText
X=r
Y=r
Text=24
LeftMouseUpAction=[!WriteKeyValue Variables radius 24 "#@#Appearance.txt"][!RefreshGroup circa2]

[r36]
Meter=String
MeterStyle=subText
X=5R
Text=36
LeftMouseUpAction=[!WriteKeyValue Variables radius 36 "#@#Appearance.txt"][!RefreshGroup circa2]

[r48]
Meter=String
MeterStyle=subText
X=5R
Text=48
LeftMouseUpAction=[!WriteKeyValue Variables radius 48 "#@#Appearance.txt"][!RefreshGroup circa2]

[r60]
Meter=String
MeterStyle=subText
X=5R
Text=60
LeftMouseUpAction=[!WriteKeyValue Variables radius 60 "#@#Appearance.txt"][!RefreshGroup circa2]

[rCustom]
Meter=String
MeterStyle=subText
X=300
Text=(custom)
LeftMouseUpAction=!CommandMeasure "mAppearanceInput" "ExecuteBatch 4"

; ============================================================
; Margins

[marginHeader]
Meter=String
MeterStyle=headerText
X=130
Y=170
Text=Margins
ToolTipText="This controls the whitespace around the skins as a percentage of the radius.  Custom values should be a decimal percentage between 0.0 and 1.0"

[marginNone]
Meter=String
MeterStyle=subText
X=r
Y=r
Text=(none)
LeftMouseUpAction=[!WriteKeyValue Variables edging "0" "#@#Appearance.txt"][!RefreshGroup circa2]

[margin10]
Meter=String
MeterStyle=subText
X=5R
Text=10%
LeftMouseUpAction=[!WriteKeyValue Variables edging "(#*radius*#*0.1)" "#@#Appearance.txt"][!RefreshGroup circa2]

[margin30]
Meter=String
MeterStyle=subText
X=5R
Text=30%
LeftMouseUpAction=[!WriteKeyValue Variables edging "(#*radius*#*0.3)" "#@#Appearance.txt"][!RefreshGroup circa2]

[marginCustom]
Meter=String
MeterStyle=subText
X=300
Text=(custom)
LeftMouseUpAction=!CommandMeasure "mAppearanceInput" "ExecuteBatch 5"

; ============================================================
; font

[fontHeader]
Meter=String
MeterStyle=headerText
X=130
Y=225
Text=Font
ToolTipText="You can change the font used in the skins as well as its attributes.  Note that since font sizes vary and will scale differently, using a font different from the default may require some advanced tweaking"

[font]
Meter=String
MeterStyle=subText
FontFace=#mainFont#
X=r
Y=r
Text=#mainFont#
LeftMouseUpAction=!CommandMeasure "mAppearanceInput" "ExecuteBatch 6"
ToolTipText="click to set the name of the font used in the skins."

[normal]
Meter=String
MeterStyle=subText
X=300
Text=N
LeftMouseUpAction=[!WriteKeyValue "Variables" "fontStyle" "Normal" "#@#Appearance.txt"][!RefreshGroup circa2]
ToolTipText=Normal/none

[bold]
Meter=String
MeterStyle=subText
StringStyle=Bold
X=5R
Text=B
LeftMouseUpAction=[!WriteKeyValue "Variables" "fontStyle" "Bold" "#@#Appearance.txt"][!RefreshGroup circa2]
ToolTipText=Bold

[italic]
Meter=String
MeterStyle=subText
StringStyle=Italic
X=5R
Text=I
LeftMouseUpAction=[!WriteKeyValue "Variables" "fontStyle" "Italic" "#@#Appearance.txt"][!RefreshGroup circa2]
ToolTipText=Italic

[boldItalic]
Meter=String
MeterStyle=subText
StringStyle=BoldItalic
X=5R
Text=BI
LeftMouseUpAction=[!WriteKeyValue "Variables" "fontStyle" "BoldItalic" "#@#Appearance.txt"][!RefreshGroup circa2]
ToolTipText=Bold + Italic

; ============================================================
; color and transparency

[colorHeader]
Meter=String
MeterStyle=headerText
X=130
Y=280
Text=Colors
ToolTipText="Audjusts the three colors used in the skins.  Clicking a colored square will allow you to edit it using the RainRGB color picker.  The bar above the text controls the transparency of that color.  Clicking the text itself will allow the color code to be set manually."

[1ColorBG]
Meter=IMAGE
SolidColor=0,0,0,100
X=130
Y=280
W=25
H=25
Group=p1 | allPages
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "#*dimColor*#"][!Redraw #CURRENTCONFIG#]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "0,0,0,80"][!Redraw #CURRENTCONFIG#]

[1ColorSqr]
Meter=IMAGE
SolidColor=#pieColor#
Group=p1 | allPages
X=2r
Y=2r
W=21
H=21
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=pieColor" "FileName=#@#Appearance.txt"]
ToolTipText="Edit the primary color in RainRGB"

[2ColorBG]
Meter=IMAGE
MeterStyle=1ColorBG
Y=315

[2ColorSqr]
Meter=IMAGE
MeterStyle=1ColorSqr
SolidColor=#innerRingColor#
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=innerRingColor" "FileName=#@#Appearance.txt"]
ToolTipText="Edit the secondary color in RainRGB"

[3ColorBG]
Meter=IMAGE
MeterStyle=1ColorBG
Y=350

[3ColorSqr]
Meter=IMAGE
MeterStyle=1ColorSqr
SolidColor=#pieBgColor#
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=pieBgColor" "FileName=#@#Appearance.txt"]
ToolTipText="Edit the circle background color in RainRGB"

[1ColorAlphaBg]
Meter=Image
SolidColor=#dimColor#
Group=p1 | allPages
X=160
Y=282
W=120
H=4
LeftMouseUpAction=[!CommandMeasure "mSettingsScript" "changeAlpha('pieColor',$MouseX:%$)"][!RefreshGroup circa2]
ToolTipText="Set the transparency of the primary color"

[1ColorAlpha]
Meter=IMAGE
SolidColor=#textColor#
Group=p1 | allPages
X=r
Y=r
H=4
W=1

[2ColorAlphaBg]
Meter=Image
MeterStyle=1ColorAlphaBg
Y=317
LeftMouseUpAction=[!CommandMeasure "mSettingsScript" "changeAlpha('innerRingColor',$MouseX:%$)"][!RefreshGroup circa2]
ToolTipText="Set the transparency of the secondary color"

[2ColorAlpha]
Meter=IMAGE
MeterStyle=1ColorAlpha
W=1

[3ColorAlphaBg]
Meter=Image
MeterStyle=1ColorAlphaBg
Y=352
LeftMouseUpAction=[!CommandMeasure "mSettingsScript" "changeAlpha('pieBgColor',$MouseX:%$)"][!RefreshGroup circa2]
ToolTipText="Set the transparency of the circle background color"

[3ColorAlpha]
Meter=IMAGE
MeterStyle=1ColorAlpha
W=1

[1ColorString]
Meter=String
FontFace=Sansation
FontColor=#textColor#
FontSize=10
SolidColor=0,0,0,1
AntiAlias=1
Group=p1 | allPages
Text=#pieColor#
X=160
Y=290
LeftMouseUpAction=!CommandMeasure "mAppearanceInput" "ExecuteBatch 1"

[2ColorString]
Meter=String
MeterStyle=1ColorString
Text=#innerRingColor#
Y=325
LeftMouseUpAction=!CommandMeasure "mAppearanceInput" "ExecuteBatch 2"

[3ColorString]
Meter=String
MeterStyle=1ColorString
Text=#pieBgColor#
Y=360
LeftMouseUpAction=!CommandMeasure "mAppearanceInput" "ExecuteBatch 3"

; ============================================================
; color presets

[presetsHeader]
Meter=String
MeterStyle=headerText
X=130
Y=415
Text=Color Presets

[presetsBg]
Meter=Image
SolidColor=#dimColor#
X=r
Y=r
W=162
H=26

[white]
Meter=Image
SolidColor=250,250,250,230
X=132
Y=417
W=30
H=10
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "250,250,250,230" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "250,250,250,155" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,51" "#@#Appearance.txt"][!RefreshGroup circa2]

[yellow]
Meter=Image
SolidColor=252,212,75,230
MeterStyle=white
X=2R
Y=r
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "252,212,75,230" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "250,250,250,155" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,51" "#@#Appearance.txt"][!RefreshGroup circa2]

[green]
Meter=Image
SolidColor=182,200,80,230
MeterStyle=white
X=2R
Y=r
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "182,200,80,230" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "250,250,250,155" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,51" "#@#Appearance.txt"][!RefreshGroup circa2]

[blue]
Meter=Image
SolidColor=89,186,255,230
MeterStyle=white
X=2R
Y=r
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "89,186,255,230" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "250,250,250,155" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,51" "#@#Appearance.txt"][!RefreshGroup circa2]

[red]
Meter=Image
SolidColor=250,100,100,230
MeterStyle=white
X=2R
Y=r
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "250,100,100,230" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "250,250,250,155" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,51" "#@#Appearance.txt"][!RefreshGroup circa2]

[black]
Meter=Image
SolidColor=10,10,10,180
X=132
Y=429
W=30
H=10
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "10,10,10,180" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "48,48,48,175" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,80" "#@#Appearance.txt"][!RefreshGroup circa2]

[dyellow]
Meter=Image
MeterStyle=black
SolidColor=204,100,8,209
X=2R
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "204,100,8,209" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "20,20,20,127" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,43" "#@#Appearance.txt"][!RefreshGroup circa2]

[dgreen]
Meter=Image
MeterStyle=black
SolidColor=99,130,55,234
X=2R
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "99,130,55,234" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "20,20,20,153" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,43" "#@#Appearance.txt"][!RefreshGroup circa2]

[dblue]
Meter=Image
MeterStyle=black
SolidColor=57,76,128,211
X=2R
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "57,76,128,211" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "20,20,20,186" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,43" "#@#Appearance.txt"][!RefreshGroup circa2]

[dred]
Meter=Image
MeterStyle=black
SolidColor=117,53,46,234
X=2R
LeftMouseUpAction=[!WriteKeyValue "Variables" "pieColor" "117,53,46,234" "#@#Appearance.txt"][!WriteKeyValue "Variables" "innerRingColor" "20,20,20,204" "#@#Appearance.txt"][!WriteKeyValue "Variables" "pieBgColor" "100,100,100,76" "#@#Appearance.txt"][!RefreshGroup circa2]
