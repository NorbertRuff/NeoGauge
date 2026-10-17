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

[Variables]
peakSource=mNetwork
; Ring (ringTemplate.inc)
fxSource=mNetworkPercent
fxMax=1
fxLevels=1
@include7="#@#Templates\peakTemplate.inc"

@include5="#@#Templates\ringTemplate.inc"

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mNetworkPercent
MeasureName2=#networkIpMeasure#
Percentual=1
ToolTipText="#networkIpLabel#: %2#CRLF#Speed: [mNetwork:/1048576,2] MB/s#CRLF#Min: [mPeakMin:/1048576,2] MB/s | Max: [mPeakMax:/1048576,2] MB/s#CRLF#Right-click to reset peaks"
Text="#networkLabel# %1%"
RightMouseUpAction=#peakResetAction#
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
