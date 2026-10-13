; ============================================================
; Processor Core Template
; Displays individual CPU core load percentage and frequency
;
; REQUIRED VARIABLES:
;   coreNumber      - Logical processor number, 1-based (1 = first core;
;                     the CPU measure treats 0 as the average of all cores)
;   perfMonInstance - "Processor Information" instance of the same core,
;                     "<group>,<index>" with a 0-based index (core 1 = "0,0")
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
MinValue=0
MaxValue=100

; "Processor Frequency" only reports the rated base clock, which never moves.
; The live clock is the "Actual Frequency" counter, but PerfMon can't read it
; (it needs a second base counter), and UsageMonitor, which can, crashes
; Rainmeter 4.5.28 on this PC. Once that is fixed, switch back to:
;   Plugin=UsageMonitor / Category=Processor Information /
;   Counter=Actual Frequency / Name=#perfMonInstance#
[mCoreFreqRaw]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=Processor Information
PerfMonCounter=Processor Frequency
PerfMonInstance=#perfMonInstance#
PerfMonDifference=0

; Plugin measures can carry a string value that a String meter would print
; instead of the number. A Calc has no string value.
[mCoreFreq]
Measure=Calc
Formula=mCoreFreqRaw

[mCoreThreshold]
Measure=Calc
Formula=mCoreLoad
DynamicVariables=1
; Dynamic color coding based on CPU load
; < 75% = Original color (default)
; 75-90% = Yellow (warning)
; >= 90% = Red (critical)
IfConditionMode=1
IfCondition=mCoreLoad < 75
IfTrueAction=[!SetOption pie LineColor "#pieColor#"][!UpdateMeter pie]
IfCondition2=(mCoreLoad >= 75) && (mCoreLoad < 90)
IfTrueAction2=[!SetOption pie LineColor "255,200,100,230"][!UpdateMeter pie]
IfCondition3=mCoreLoad >= 90
IfTrueAction3=[!SetOption pie LineColor "255,100,100,230"][!UpdateMeter pie]

[Variables]
peakSource=mCoreLoad
@include7="#@#Templates\peakTemplate.inc"

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
ToolTipText="Core #coreNumber#: %1%#CRLF#Min: [mPeakMin:0]% | Max: [mPeakMax:0]%#CRLF#Freq: [mCoreFreq:0] MHz#CRLF#Right-click to reset peaks"
RightMouseUpAction=#peakResetAction#
DynamicVariables=1

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mCoreFreq
Text="freq: %1 MHz"
NumOfDecimals=0

