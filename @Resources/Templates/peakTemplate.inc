; ============================================================
; Peak Tracking Template
; Records the lowest and highest value of one measure since the skin
; loaded (or since the last reset).
;
; WHY:
;   MinValue/MaxValue on a measure are fixed scaling bounds for meters,
;   not observed peaks, so [mCPU:MaxValue] always returns 100.
;   !ResetStats only resets Rainmeter's network counters.
;
; REQUIRED VARIABLES:
;   peakSource - Name of the measure to track (e.g. mCPU, mTemp)
;
; PROVIDES:
;   mPeakMin, mPeakMax - Use in tooltips as [mPeakMin:0] / [mPeakMax:0]
;                        (the meter needs DynamicVariables=1)
;   #peakResetAction#  - Bangs that restart tracking from the current value
;
; USAGE:
;   Include after the source measure is defined:
;     @include7="#@#Templates\peakTemplate.inc"
;   Then on the main text meter:
;     RightMouseUpAction=#peakResetAction#
; ============================================================

[Variables]
; While 1, both peak measures copy the current value instead of comparing
peakReset=0
peakResetAction=[!SetVariable peakReset 1][!UpdateMeasure mPeakMin][!UpdateMeasure mPeakMax][!SetVariable peakReset 0][!UpdateMeter mainText][!Redraw]

[mPeakMax]
Measure=Calc
; Starts at 0, so the first real sample always wins
Formula=#peakReset# ? #peakSource# : Max(#peakSource#, mPeakMax)
DynamicVariables=1

[mPeakMin]
Measure=Calc
; TODO: this starts at 0 and Min() never rises above it, so the minimum
; sticks at 0 until a reset. It needs a way to take the first real sample.
Formula=#peakReset# ? #peakSource# : Min(#peakSource#, mPeakMin)
DynamicVariables=1
