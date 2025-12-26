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
ToolTipText="Core #coreNumber#: %1%#CRLF#Min: [mCoreLoad:MinValue]% | Max: [mCoreLoad:MaxValue]%#CRLF#Freq: [mCoreFreq:] MHz#CRLF#Right-click to reset peaks"
RightMouseUpAction=[!ResetStats mCoreLoad][!UpdateMeasure mCoreLoad][!UpdateMeter mainText][!Redraw]
DynamicVariables=1

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mCoreFreq
Text="freq: %1 MHz"
NumOfDecimals=0

