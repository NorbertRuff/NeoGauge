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

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mUsedDisk

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mUsedDisk
MeasureName2=mDiskLabel
Percentual=1
Text="#diskDrive#:\ %1%"
LeftMouseUpAction=["#diskDrive#:"]
ToolTipText=%2

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

