; ============================================================
; Temperature Template
; Variables required: tempRegValue, tempLabel, tempPercentFormula (optional, defaults to tempRegValue/100)
; Optional: tempRpmRegValue, tempRpmLabel, tempShowRpm (0 or 1)

[mTemp]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#tempRegValue#

[mPercent]
Measure=Calc
Formula=(mTemp/100)

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mPercent
LineColor=#pieColor#

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mTemp
ClipStringW=20
ClipStringH=40
ClipString=1
Text="%1"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mPercent
NumOfDecimals=2
ClipString=2
ClipStringW=80
Text=#tempLabel#

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

