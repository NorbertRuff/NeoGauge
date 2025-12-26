; ============================================================
; Network Template
; Displays network upload/download speed with IP address in tooltip
;
; REQUIRED VARIABLES:
;   networkMaxVar   - Maximum speed in bytes/second for percentage calculation
;                     (e.g., uploadMax or downloadMax from Settings.txt)
;   networkLabel    - Display label (e.g., "up" for upload, "dn" for download)
;   networkIpMeasure - Measure name for IP address (e.g., "mWanIp" or "mLanIp")
;   networkIpLabel  - Label for IP type (e.g., "wan" or "lan")
;
; REQUIRED MEASURE (must be defined before including this template):
;   mNetwork - Network measure (NetIn or NetOut) for speed in bytes/second
;
; USAGE:
;   1. Define network measure (mNetwork) before including this template
;   2. Set required variables
;   3. Include appearance file (e.g., @include2=#@#Apparence\networkDown.txt)
;   4. Include this template: @include6="#@#Templates\networkTemplate.inc"
;
; UPDATE FREQUENCY:
;   Network measures should use UpdateDivider=1 for real-time updates
;   IP address measures can use UpdateDivider=3600+ (updates hourly or less)
;
; NOTE:
;   Network template requires measure definition before include due to Rainmeter limitation
; ============================================================

[mNetworkPercent]
Measure=Calc
Formula=(mNetwork/#networkMaxVar#)

[mNetworkThreshold]
Measure=Calc
Formula=(mNetwork/#networkMaxVar#)*100
DynamicVariables=1
; Dynamic color coding based on network usage
; < 75% = Original color (default)
; 75-90% = Yellow (high usage)
; >= 90% = Red (near max capacity)
IfConditionMode=1
IfCondition=(mNetwork/#networkMaxVar#)*100 < 75
IfTrueAction=[!SetOption pie LineColor "#pieColor#"][!UpdateMeter pie]
IfCondition2=((mNetwork/#networkMaxVar#)*100 >= 75) && ((mNetwork/#networkMaxVar#)*100 < 90)
IfTrueAction2=[!SetOption pie LineColor "255,200,100,230"][!UpdateMeter pie]
IfCondition3=(mNetwork/#networkMaxVar#)*100 >= 90
IfTrueAction3=[!SetOption pie LineColor "255,100,100,230"][!UpdateMeter pie]

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
ToolTipText="#networkIpLabel#: %2#CRLF#Speed: [mNetwork:]B/s#CRLF#Min: [mNetwork:MinValue]B/s | Max: [mNetwork:MaxValue]B/s#CRLF#Right-click to reset peaks"
Text="#networkLabel# %1%"
RightMouseUpAction=[!ResetStats mNetwork][!UpdateMeasure mNetwork][!UpdateMeter mainText][!Redraw]
DynamicVariables=1

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

