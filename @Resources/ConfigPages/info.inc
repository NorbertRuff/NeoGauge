; ============================================================
; Info page
; ============================================================

[Variables]
pageColor=254,210,70,230

[title]
Meter=String
MeterStyle=sText | sHeader
FontSize=(20*#s#)
Y=(16*#s#)
Text=NeoGauge

[version]
Meter=String
MeterStyle=sText | sNote
X=(8*#s#)R
Y=(10*#s#)r
FontSize=(10*#s#)
Text=v#componentVersion#

[author]
Meter=String
MeterStyle=sText | sNote
FontSize=(10*#s#)
X=(140*#s#)
Y=(52*#s#)
Text=Norbert Ruff  |  github.com/NorbertRuff
LeftMouseUpAction=["https://github.com/NorbertRuff"]

[creditsHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(96*#s#)
Text=Credits and inspiration

[credit1]
Meter=String
MeterStyle=sText | sFirst
Text=Flying Hyrax - Circoustwo
LeftMouseUpAction=["https://www.deviantart.com/flyinghyrax"]

[credit2]
Meter=String
MeterStyle=sText | sFirst
Text=Rainmeter developer team
LeftMouseUpAction=["https://github.com/rainmeter"]

[credit3]
Meter=String
MeterStyle=sText | sFirst
Text=Ubuntu Nerd Font (Ubuntu Font Licence)
LeftMouseUpAction=["https://www.nerdfonts.com"]

[licenseHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(200*#s#)
Text=License

[license]
Meter=String
MeterStyle=sText | sFirst
Text=Creative Commons Attribution-NonCommercial-ShareAlike 3.0
LeftMouseUpAction=["https://creativecommons.org/licenses/by-nc-sa/3.0/"]

[howHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(260*#s#)
Text=How settings work

[how]
Meter=String
MeterStyle=sText | sFirst | sNote
FontSize=(10*#s#)
W=(410*#s#)
ClipString=2
Text=Click any option to apply it right away; the current choice is highlighted. Values such as colors, fonts, drive letters and speeds open a text box when clicked: type and press Enter. "edit files" opens the underlying text files for anything not covered here.
