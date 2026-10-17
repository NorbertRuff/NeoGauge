; ============================================================
; Ring Template
; The gauge circle: rings, the value arc, warning colors and the effects
; chosen on the config tool's "effects" page (fx* in Settings.txt).
; Replaces sharedMeters.inc + a [pie] meter + a threshold measure.
;
; REQUIRED VARIABLES (in the skin's or template's [Variables]):
;   fxSource - Measure that holds the value
;   fxMax    - Value that fills the ring: 100 for percentages, 1 for 0-1
;   fxLevels - 1 = yellow from 75 %, red from 90 %; 0 = always pieColor
;              (battery, wifi, volume, clock)
;
; USAGE:
;   Include after the fxSource measure, before [divider]:
;     @include5="#@#Templates\ringTemplate.inc"
;
; HOW THE ANIMATION STAYS CHEAP:
;   Readings still update once a second. When a reading changes, [mFxAnim]
;   plays frames (#fxFrameMs# ms apart) that update only the effect measures
;   and the meters of the effects that are switched on. [mFxSettled] stops
;   the frames as soon as nothing is moving, so gauges whose value holds
;   still (disks, temperatures) cost nothing between readings.
;   Meter groups carry the effect's on/off flag (fxc1 = comet on), and a
;   frame only updates the "...1" groups.
; ============================================================

[Variables]
; Animation frame interval (ms): 50 = 20 fps
fxFrameMs=50
; Current colors; Ring.lua and [mFxLevel] keep these up to date
fxRGB=255,255,255
fxA=200
fxPeakRGB=255,255,255
fxHeadRGB=255,255,255

[mFxScript]
Measure=Script
ScriptFile=#@#Scripts\Ring.lua

[mFxFull]
Measure=Calc
Formula=1
MinValue=0
MaxValue=1

; The reading as 0-100; a new reading starts the animation
[mFxTarget]
Measure=Calc
Formula=Clamp(#fxSource# / #fxMax# * 100, 0, 100)
MinValue=0
MaxValue=100
OnChangeAction=[!CommandMeasure mFxAnim "Stop 1"][!CommandMeasure mFxAnim "Execute 1"]

; What the ring shows: eases toward the reading (each frame closes a share of
; the gap), or jumps straight to it when fxSmooth=0 or the gap is under 0.3 %
; (too small to see, not worth any frames)
[mFxValue]
Measure=Calc
Formula=(#fxSmooth# = 0) || (Abs(mFxTarget - mFxValue) < 0.3) ? mFxTarget : mFxValue + (mFxTarget - mFxValue) * (1 - Exp(-#fxFrameMs# / #fxEaseMs#))
MinValue=0
MaxValue=100
Group=fx

; Afterglow: rises with the ring, falls slowly (~0.9 s)
[mFxGhost]
Measure=Calc
Formula=(#fxAfterglow# = 0) || (mFxValue >= mFxGhost) || (mFxGhost - mFxValue < 0.05) ? mFxValue : mFxGhost + (mFxValue - mFxGhost) * (1 - Exp(-#fxFrameMs# / 900))
MinValue=0
MaxValue=100
Group=fx

; Peak tick, timed with the clock so frames can stop while it holds:
; [mFxPeakAt] is when the current peak was set; after 3 s it falls 12 %/s,
; never below the reading. [mFxPeakFalling] restarts the frames for the fall.
[mFxNow]
Measure=Time
Group=fx

[mFxPeakAt]
Measure=Calc
Formula=mFxTarget >= mFxPeak ? mFxNow : mFxPeakAt
Group=fx

[mFxPeak]
Measure=Calc
Formula=(#fxPeak# = 0) || (mFxTarget >= mFxPeak) ? mFxTarget : ((mFxNow - mFxPeakAt) >= 3 ? Max(mFxTarget, mFxPeak - 12 * #fxFrameMs# / 1000) : mFxPeak)
MinValue=0
MaxValue=100
Group=fx

[mFxPeakFalling]
Measure=Calc
Formula=(mFxPeak - mFxTarget >= 0.05) && ((mFxNow - mFxPeakAt) >= 3)
OnChangeAction=[!CommandMeasure mFxAnim "Stop 1"][!CommandMeasure mFxAnim "Execute 1"]

; Nothing left to animate: stop the frames until the next new reading
[mFxSettled]
Measure=Calc
Formula=(mFxValue = mFxTarget) && (mFxGhost - mFxValue < 0.05) && (mFxPeakFalling = 0)
Group=fx
IfCondition=mFxSettled = 1
IfTrueAction=[!CommandMeasure mFxAnim "Stop 1"]
IfConditionMode=1

; Glow strength 0-1: off, constant, or growing from 55 % to 90 %
[mFxGlow]
Measure=Calc
Formula=#fxGlow# = 0 ? 0 : (#fxGlow# = 1 ? #fxGlowStrength# : #fxGlowStrength# * Clamp((mFxValue - 55) / 35, 0, 1))
Group=fx

; Warning colors follow the ring, so it turns yellow/red as it sweeps past
[mFxLevel]
Measure=Calc
DynamicVariables=1
Formula=#fxLevels# = 0 ? 0 : (mFxValue >= 90 ? 2 : (mFxValue >= 75 ? 1 : 0))
Group=fx
IfCondition=mFxLevel = 0
IfTrueAction=[!SetVariable fxRGB "[#fxBaseRGB]"][!SetVariable fxA "[#fxBaseA]"][!SetVariable fxHeadRGB "[#fxBaseHeadRGB]"]
IfCondition2=mFxLevel = 1
IfTrueAction2=[!SetVariable fxRGB "255,200,100"][!SetVariable fxA "230"][!SetVariable fxHeadRGB "255,228,178"]
IfCondition3=mFxLevel = 2
IfTrueAction3=[!SetVariable fxRGB "255,100,100"][!SetVariable fxA "230"][!SetVariable fxHeadRGB "255,178,178"]

[mFxPeakLevel]
Measure=Calc
DynamicVariables=1
Formula=#fxLevels# = 0 ? 0 : (mFxPeak >= 90 ? 2 : (mFxPeak >= 75 ? 1 : 0))
Group=fx
IfCondition=mFxPeakLevel = 0
IfTrueAction=[!SetVariable fxPeakRGB "[#fxBasePeakRGB]"]
IfCondition2=mFxPeakLevel = 1
IfTrueAction2=[!SetVariable fxPeakRGB "255,219,154"]
IfCondition3=mFxPeakLevel = 2
IfTrueAction3=[!SetVariable fxPeakRGB "255,154,154"]

; Up to 100 frames (5 s at 50 ms);
; [mFxSettled] usually stops them much sooner
[mFxAnim]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat Frame, #fxFrameMs#, 100
Frame=[!UpdateMeasureGroup fx][!UpdateMeterGroup fxm][!UpdateMeterGroup fxg1][!UpdateMeterGroup fxg2][!UpdateMeterGroup fxa1][!UpdateMeterGroup fxc1][!UpdateMeterGroup fxp1][!UpdateMeterGroup fxr1][!Redraw]

@include5a="#@#sharedMeters.inc"

; ------------------------------------------------------------
; Meters. All share the circle's box (X=r Y=r), back to front.
; Groups: fxm = main arc, fxg<glow mode>, fxa<afterglow>, fxc<comet>,
; fxp<peak>, fxr<round caps>; a frame updates only the switched-on ones.

[fxStyle]
X=r
Y=r
W=(2*#radius#)
H=(2*#radius#)
Solid=1
AntiAlias=1
StartAngle=#pieStart#
RotationAngle=(6.28*#pieSize#)
LineStart=(#innerRadius#*1.14)
LineLength=(#radius#*0.91)
DynamicVariables=1

[fxGhost]
Meter=Roundline
MeterStyle=fxStyle
Group=fxa#fxAfterglow#
MeasureName=mFxGhost
LineColor=#fxRGB#,(#fxA#*0.28)
Hidden=(1 - #fxAfterglow#)

; Glow: the same arc three more times, wider and fainter (no blur in Rainmeter)
[fxGlow3]
Meter=Roundline
MeterStyle=fxStyle
Group=fxg#fxGlow#
MeasureName=mFxValue
LineStart=(#innerRadius#*1.14 - #radius#*0.21)
LineLength=(#radius#*0.91 + #radius#*0.21)
LineColor=#fxRGB#,(#fxA#*0.07*[mFxGlow])
Hidden=(#fxGlow# = 0)

[fxGlow2]
Meter=Roundline
MeterStyle=fxStyle
Group=fxg#fxGlow#
MeasureName=mFxValue
LineStart=(#innerRadius#*1.14 - #radius#*0.12)
LineLength=(#radius#*0.91 + #radius#*0.12)
LineColor=#fxRGB#,(#fxA#*0.16*[mFxGlow])
Hidden=(#fxGlow# = 0)

[fxGlow1]
Meter=Roundline
MeterStyle=fxStyle
Group=fxg#fxGlow#
MeasureName=mFxValue
LineStart=(#innerRadius#*1.14 - #radius#*0.05)
LineLength=(#radius#*0.91 + #radius#*0.05)
LineColor=#fxRGB#,(#fxA#*0.30*[mFxGlow])
Hidden=(#fxGlow# = 0)

; The value arc (replaced by the comet pieces when fxComet=1)
[fxPie]
Meter=Roundline
MeterStyle=fxStyle
Group=fxm
MeasureName=mFxValue
LineColor=#fxRGB#,#fxA#
Hidden=#fxComet#

; Comet: the arc in 7 pieces, fainter toward the start
[fxSegStyle]
Group=fxc#fxComet#
MeasureName=mFxFull
RotationAngle=(6.28*#pieSize#*[mFxValue]/700 + 0.01)
Hidden=(1 - #fxComet#)

[fxSeg0]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*0/7)
LineColor=#fxRGB#,(#fxA#*0.217)

[fxSeg1]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*1/7)
LineColor=#fxRGB#,(#fxA#*0.290)

[fxSeg2]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*2/7)
LineColor=#fxRGB#,(#fxA#*0.391)

[fxSeg3]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*3/7)
LineColor=#fxRGB#,(#fxA#*0.515)

[fxSeg4]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*4/7)
LineColor=#fxRGB#,(#fxA#*0.658)

[fxSeg5]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*5/7)
LineColor=#fxRGB#,(#fxA#*0.821)

[fxSeg6]
Meter=Roundline
MeterStyle=fxStyle | fxSegStyle
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxValue]/100*6/7)
LineColor=#fxRGB#,#fxA#

; Round caps at both ends of the arc (Roundline ends are always square)
[fxCaps]
Meter=Shape
X=r
Y=r
Group=fxr#fxRoundCaps#
DynamicVariables=1
Shape=Ellipse (#radius# + (#innerRadius#*1.14 + #radius#*0.91)/2*Cos(#pieStart#)),(#radius# + (#innerRadius#*1.14 + #radius#*0.91)/2*Sin(#pieStart#)),((#radius#*0.91 - #innerRadius#*1.14)/2) | Fill Color #fxRGB#,#fxA# | StrokeWidth 0
Shape2=Ellipse (#radius# + (#innerRadius#*1.14 + #radius#*0.91)/2*Cos(#pieStart# + 6.28*#pieSize#*[mFxValue]/100)),(#radius# + (#innerRadius#*1.14 + #radius#*0.91)/2*Sin(#pieStart# + 6.28*#pieSize#*[mFxValue]/100)),((#radius#*0.91 - #innerRadius#*1.14)/2) | Fill Color #fxRGB#,#fxA# | StrokeWidth 0
Hidden=((1 - #fxRoundCaps#) || ([mFxValue] < 0.5))

; Comet head: a bright dot at the tip
[fxHead]
Meter=Shape
X=r
Y=r
Group=fxc#fxComet#
DynamicVariables=1
Shape=Ellipse (#radius# + (#innerRadius#*1.14 + #radius#*0.91)/2*Cos(#pieStart# + 6.28*#pieSize#*[mFxValue]/100)),(#radius# + (#innerRadius#*1.14 + #radius#*0.91)/2*Sin(#pieStart# + 6.28*#pieSize#*[mFxValue]/100)),((#radius#*0.91 - #innerRadius#*1.14)*0.62) | Fill Color #fxHeadRGB#,255 | StrokeWidth 0
Hidden=((1 - #fxComet#) || ([mFxValue] < 0.5))

; Peak tick across the track, in the color of the level it marks
[fxPeakTick]
Meter=Roundline
MeterStyle=fxStyle
Group=fxp#fxPeak#
MeasureName=mFxFull
StartAngle=(#pieStart# + 6.28*#pieSize#*[mFxPeak]/100 - 0.025)
RotationAngle=0.05
LineStart=(#innerRadius#*1.07 - #radius#*0.07)
LineLength=(#radius#*0.96 + #radius#*0.07)
LineColor=#fxPeakRGB#,255
Hidden=(1 - #fxPeak#)
