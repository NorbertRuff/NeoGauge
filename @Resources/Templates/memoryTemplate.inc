; ============================================================
; Memory Template
; Displays memory usage percentage with free/total memory information
;
; REQUIRED VARIABLES:
;   memoryLabel - Display label (e.g., "Ram" for RAM, "swp" for swap/virtual memory)
;
; REQUIRED MEASURES (must be defined before including this template):
;   mUsedMemory  - Measure for used memory (percentage or bytes)
;   mFreeMemory  - Measure for free memory (bytes)
;   mTotalMemory - Measure for total memory (bytes)
;
; USAGE:
;   1. Define memory measures before including this template
;   2. Set memoryLabel variable
;   3. Include appearance file (e.g., @include2=#@#Apparence\ram.txt)
;   4. Include this template: @include6="#@#Templates\memoryTemplate.inc"
;
; NOTE:
;   Memory components can't use full templates due to Rainmeter's limitation
;   with measure type variables. This template only handles the display meters.
; ============================================================

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

