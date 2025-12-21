; ============================================================
; Memory Template
; Variables required: memoryLabel (Ram/swp)
; Note: Memory measures (mUsedMemory, mFreeMemory, mTotalMemory) must be defined before including this template

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mUsedMemory

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mUsedMemory
Percentual=1
Text="#memoryLabel# %1%"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mFreeMemory
MeasureName2=mTotalMemory
Text="%1B free"
AutoScale=1

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

