; ============================================================
; Processor Core Template
; Variables required: coreNumber, perfMonInstance

[mCoreLoad]
Measure=CPU
Processor=#coreNumber#

[mCoreFreq]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=Processor Information
PerfMonCounter=Processor Frequency
PerfMonInstance=#perfMonInstance#
PerfMonDifference=0

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mCoreLoad

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mCoreLoad
Percentual=1
Text="c#coreNumber# %1%"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mCoreFreq
Text="freq: %1 MHz"
NumOfDecimals=0

