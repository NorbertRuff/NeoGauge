[roundlineCommon]
Solid=1
AntiAlias=1
StartAngle=#pieStart#
RotationAngle=(6.28*#pieSize#)

[innerEdgeCommon]
W=(2*#radius#)
H=(2*#radius#)
LineStart=#innerRadius#
LineLength=(#innerRadius#*1.07)
LineColor=#innerRingColor#
Hidden=#hideInnerEdge#

[outerEdgeCommon]
X=r
Y=r
W=(2*#radius#)
H=(2*#radius#)
LineStart=(#radius#*0.96)
LineLength=#radius#
LineColor=#outerRingColor#
Hidden=#hideOuterEdge#

[pieBgCommon]
X=r
Y=r
W=(2*#radius#)
H=(2*#radius#)
LineStart=(#innerRadius#*1.07)
LineLength=(#radius#*0.96)
LineColor=#pieBgColor#
Hidden=#hidePieBg#

[pieCommon]
X=r
Y=r
W=(2*#radius#)
H=(2*#radius#)
LineLength=(#radius#*0.91)
LineStart=(#innerRadius#*1.14)
LineColor=#pieColor#

[dividerCommon]
Y=#radius#r
W=(#radius#*4)
H=(#radius#*0.10)
SolidColor=#outerRingColor#
Hidden=#hideDivider#

[mainTextCommon]
AntiAlias=1
StringCase=Normal
FontFace=#mainFont#
FontSize=(#radius#*0.65)
FontColor=#textMainColor#
StringStyle=#fontStyle#
SolidColor=0,0,0,1

[subTextCommon]
AntiAlias=1
ClipStringW=(#radius#*4)
ClipStringH=(#subTwoLines# = 1 ? (#radius#) : (#radius#*0.5))
ClipString=2
FontFace=#subFont#
FontSize=(#radius#*0.35)
FontColor=#textSubColor#
StringStyle=#fontStyle#
Hidden=#hideSubText#

[iconCommon]
AntiAlias=1
Y=r
W=(#radius#*0.5)
PreserveAspectRatio=1
ImageTint=#textSubColor#
Path="#@#Images"
Hidden=1
Group=buttons
