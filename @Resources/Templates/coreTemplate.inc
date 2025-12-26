; ============================================================
; Processor Core Template
; Displays individual CPU core load percentage and frequency
;
; REQUIRED VARIABLES:
;   coreNumber      - CPU core number (0-based, e.g., 0 for first core, 1 for second)
;   perfMonInstance - Performance Monitor instance name for frequency
;                     Usually matches core number (e.g., "0" for core 0)
;
; USAGE:
;   1. Set required variables before including this template
;   2. Include appearance file (e.g., @include2=#@#Apparence\cpu.txt)
;   3. Include this template: @include6="#@#Templates\coreTemplate.inc"
;
; UPDATE FREQUENCY:
;   CPU load changes quickly - use UpdateDivider=1-3 for real-time updates
;   Frequency changes less frequently - can use UpdateDivider=5-10
; ============================================================

[mCoreLoad]
Measure=CPU
Processor=#coreNumber#
; UpdateDivider=1 - CPU load changes quickly, update every second for real-time display
; Track peak values automatically
MinValue=0
MaxValue=100

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
; UpdateDivider=5 - Frequency changes less frequently, update every 5 seconds
; Handle missing frequency data gracefully
Substitute="Unknown":"N/A","-1":"N/A","":"N/A"

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

