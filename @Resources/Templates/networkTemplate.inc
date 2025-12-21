; ============================================================
; Network Template
; Variables required: networkMaxVar, networkLabel (up/dn), networkIpMeasure (mWanIp/mLanIp), networkIpLabel (wan/lan)
; Note: Network measure must be defined before including this template as mNetwork

[mNetworkPercent]
Measure=Calc
Formula=(mNetwork/#networkMaxVar#)

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mNetworkPercent

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mNetworkPercent
MeasureName2=#networkIpMeasure#
Percentual=1
ToolTipText="#networkIpLabel#: %2"
Text="#networkLabel# %1%"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mNetwork
Text="%1 B/s"
AutoScale=1

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

