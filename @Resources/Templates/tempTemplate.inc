; ============================================================
; Temperature Template
; 
; REQUIRED VARIABLES:
;   tempRegValue    - HWiNFO64 registry value name (e.g., "Value1", "Value13")
;                     Find values by running: reg query HKEY_CURRENT_USER\SOFTWARE\HWiNFO64\VSB
;   tempLabel       - Display label for the sensor (shown in subtext)
;   tempWarn / tempAlert - Yellow / red level in degrees, one of the groups in
;                     Settings.txt (e.g. #chipTempWarn# / #chipTempAlert#)
;   gaugeSlot       - Row on the config tool's sensors page (SLOTS in Sensors.lua);
;                     a gauge without a sensor opens it on click
;
; The ring is full at 100 degrees.
;
; USAGE:
;   1. Set required variables before including this template
;   2. Include appearance file (e.g., @include2=#@#Apparence\fan.txt)
;   3. Include this template: @include6="#@#Templates\tempTemplate.inc"
;
; ERROR HANDLING:
;   - Handles missing/invalid registry values with Substitute
;   - Displays "N/A" for unavailable sensors
;   - Peaks come from peakTemplate.inc (right-click resets)
; ============================================================

[mTemp]
Measure=Registry
; HWiNFO refreshes its sensors about every 2 s, so reading faster only repeats values
UpdateDivider=2
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#tempRegValue#
; Track peak values automatically
MinValue=0
MaxValue=100
; Handle missing or invalid sensor values gracefully
Substitute="Unknown":"N/A","-1":"N/A","":"N/A"

[mPercent]
Measure=Calc
Formula=(mTemp/100)

[Variables]
peakSource=mTemp
; Ring (ringTemplate.inc)
fxSource=mPercent
fxMax=1
fxLevels=1
; The ring is in degrees (temp / 100 of fxMax=1), so the levels are too
fxWarn=#tempWarn#
fxAlert=#tempAlert#
noSensorSource=mTemp
noSensorLabel=#tempLabel#
@include7="#@#Templates\peakTemplate.inc"
@include8="#@#Templates\noSensorTemplate.inc"

@include5="#@#Templates\ringTemplate.inc"

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mTemp
ClipStringW=(#radius#*4)
ClipStringH=(#radius#*1.6)
ClipString=1
Text="%1"
ToolTipText="Current: %1°C#CRLF#Min: [mPeakMin:0]°C | Max: [mPeakMax:0]°C#CRLF#Right-click to reset peaks"
RightMouseUpAction=#peakResetAction#
LeftMouseUpAction=#noSensorClick#
DynamicVariables=1

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mPercent
NumOfDecimals=2
ClipString=2
ClipStringW=(#radius#*4)
Text=#tempLabel#

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#
