; ============================================================
; Disk Template
; Displays disk usage percentage with free/total space information
;
; REQUIRED VARIABLES:
;   diskDrive              - Drive letter (e.g., "C", "D") without colon
;   diskUpdateDivider      - Update frequency for used/free space (recommended: 5-10)
;   diskIgnoreRemovable    - Ignore removable drives: 0=no, 1=yes
;   diskTotalUpdateDivider - Update frequency for total space (recommended: 30-60, changes rarely)
;   diskLabelUpdateDivider - Update frequency for disk label (recommended: 60+, changes rarely)
;   diskTypeUpdateDivider  - Update frequency for disk type (recommended: 60+, changes rarely)
;
; USAGE:
;   1. Set required variables before including this template
;   2. Include appearance file (e.g., @include2=#@#Apparence\disk.txt)
;   3. Include this template: @include6="#@#Templates\diskTemplate.inc"
;
; UPDATE FREQUENCY GUIDELINES:
;   - Used/Free space: UpdateDivider=5-10 (changes moderately)
;   - Total space: UpdateDivider=30-60 (changes rarely, only on resize)
;   - Label/Type: UpdateDivider=60+ (changes only when drive changes)
;
; ERROR HANDLING:
;   - Handles removable drives gracefully
;   - Shows "(removed)" when drive is disconnected
; ============================================================

[mUsedDisk]
Measure=FreeDiskSpace
Drive=#diskDrive#:
IgnoreRemovable=#diskIgnoreRemovable#
UpdateDivider=#diskUpdateDivider#
InvertMeasure=1

[mFreeDisk]
Measure=FreeDiskSpace
Drive=#diskDrive#:
IgnoreRemovable=#diskIgnoreRemovable#
UpdateDivider=#diskUpdateDivider#

[mTotalDisk]
Measure=FreeDiskSpace
Drive=#diskDrive#:
IgnoreRemovable=#diskIgnoreRemovable#
UpdateDivider=#diskTotalUpdateDivider#
Total=1

[mDiskPercent]
Measure=Calc
Formula=(mUsedDisk / mTotalDisk) * 100
; This calculates the actual percentage from bytes
; Track peak values automatically
MinValue=0
MaxValue=100

[mDiskLabel]
Measure=FreeDiskSpace
Drive=#diskDrive#:
IgnoreRemovable=0
UpdateDivider=#diskLabelUpdateDivider#
Label=1

[mDiskType]
Measure=FreeDiskSpace
Drive=#diskDrive#:
IgnoreRemovable=0
UpdateDivider=#diskTypeUpdateDivider#
Type=1
IfBelowAction=[!SetVariable "textA" "(removed)"][!SetVariable "textB" "(removed)"]
IfBelowValue=3
IfAboveAction=[!SetVariable "textA" "%1B free"][!SetVariable "textB" "%2B total"]
IfAboveValue=1

[mDiskThreshold]
Measure=Calc
Formula=mDiskPercent
DynamicVariables=1
; Dynamic color coding based on disk usage percentage
; < 75% = Original color (default)
; 75-90% = Yellow (warning - low space)
; >= 90% = Red (critical - very low space)
IfConditionMode=1
IfCondition=mDiskPercent < 75
IfTrueAction=[!SetOption pie LineColor "#pieColor#"][!UpdateMeter pie][!Redraw]
IfCondition2=(mDiskPercent >= 75) && (mDiskPercent < 90)
IfTrueAction2=[!SetOption pie LineColor "255,200,100,230"][!UpdateMeter pie][!Redraw]
IfCondition3=mDiskPercent >= 90
IfTrueAction3=[!SetOption pie LineColor "255,100,100,230"][!UpdateMeter pie][!Redraw]

[Variables]
peakSource=mDiskPercent
@include7="#@#Templates\peakTemplate.inc"

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mDiskPercent

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mDiskPercent
MeasureName2=mDiskLabel
Text="#diskDrive#:\ %1%"
LeftMouseUpAction=["#diskDrive#:"]
ToolTipText="%2 (#diskDrive#:)#CRLF#Used: %1%#CRLF#Min: [mPeakMin:1]% | Max: [mPeakMax:1]%#CRLF#Right-click to reset peaks"
RightMouseUpAction=#peakResetAction#
DynamicVariables=1

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mFreeDisk
MeasureName2=mTotalDisk
Text=#textA#
AutoScale=1
DynamicVariables=1

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

