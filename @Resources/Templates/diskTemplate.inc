; ============================================================
; Disk Measures Template
; Variables required: diskDrive, diskUpdateDivider, diskIgnoreRemovable, diskTotalUpdateDivider, diskLabelUpdateDivider, diskTypeUpdateDivider

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

