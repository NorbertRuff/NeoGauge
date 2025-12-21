; ============================================================
; Fan Template (shows RPM with temperature on hover)
; Variables required: fanRpmRegValue, fanLabel, fanMaxRpm
; Optional: fanTempRegValue (if not set, won't show temp on hover)

[mRpm]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#fanRpmRegValue#

[mPercent]
Measure=Calc
Formula=(mRpm/#fanMaxRpm#)

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
MeasureName=mRpm
ClipStringW=20
ClipStringH=40
ClipString=1
Text="%1"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
ClipString=2
ClipStringW=80
Text=#fanLabel#

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

