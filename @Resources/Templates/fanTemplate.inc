; ============================================================
; Fan Template
; Displays fan RPM with optional temperature on hover
;
; REQUIRED VARIABLES:
;   fanRpmRegValue     - HWiNFO64 registry value for RPM display (e.g., "Value7", "Value8")
;   fanRpmRawRegValue  - HWiNFO64 raw registry value for RPM calculations (e.g., "ValueRaw7", "ValueRaw8")
;                        Find values by running: reg query HKEY_CURRENT_USER\SOFTWARE\HWiNFO64\VSB
;   fanLabel           - Display label for the fan (shown in subtext)
;   fanMaxRpm          - Maximum RPM for percentage calculation (e.g., 2500)
;
; OPTIONAL VARIABLES:
;   fanTempRegValue - HWiNFO64 registry value for temperature (if showing temp on hover)
;
; USAGE:
;   1. Set required variables before including this template
;   2. Include appearance file (e.g., @include2=#@#Apparence\fan.txt)
;   3. Include this template: @include6="#@#Templates\fanTemplate.inc"
;
; ERROR HANDLING:
;   - Handles missing/invalid registry values with Substitute
;   - Displays "N/A" for unavailable sensors
;   - Peak values tracked automatically with MinValue/MaxValue
; ============================================================

[mRpm]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#fanRpmRawRegValue#
; UpdateDivider=3 - Fan RPM can change quickly, update every 3 seconds (3000ms)
; Uncomment and adjust based on your needs
; NOTE: Uses raw value (ValueRaw7, etc.) for numeric calculations without commas or "RPM" text
; Track peak values automatically
MinValue=0
MaxValue=5000

[mRpmDisplay]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#fanRpmRegValue#
; This measure is for display only - shows "N/A" for invalid values
Substitute="Unknown":"N/A","-1":"N/A","":"N/A"

[mPercent]
Measure=Calc
; Calculate percentage: RPM / MaxRPM
; Roundline meter expects values 0-1 (as a fraction, like temp and network templates)
Formula=mRpm/#fanMaxRpm#
DynamicVariables=1

[mFanThreshold]
Measure=Calc
Formula=(mRpm/#fanMaxRpm#)*100
DynamicVariables=1
; Dynamic color coding based on fan RPM percentage
; < 75% = Original color (default)
; 75-90% = Yellow (high speed)
; >= 90% = Red (very high speed)
IfConditionMode=1
IfCondition=(mRpm/#fanMaxRpm#)*100 < 75
IfTrueAction=[!SetOption pie LineColor "#pieColor#"][!UpdateMeter pie]
IfCondition2=((mRpm/#fanMaxRpm#)*100 >= 75) && ((mRpm/#fanMaxRpm#)*100 < 90)
IfTrueAction2=[!SetOption pie LineColor "255,200,100,230"][!UpdateMeter pie]
IfCondition3=(mRpm/#fanMaxRpm#)*100 >= 90
IfTrueAction3=[!SetOption pie LineColor "255,100,100,230"][!UpdateMeter pie]

[Variables]
peakSource=mRpm
@include7="#@#Templates\peakTemplate.inc"

@include5="#@#sharedMeters.inc"

[pie]
Meter=ROUNDLINE
MeterStyle=roundlineCommon | pieCommon
MeasureName=mPercent
LineColor=#pieColor#

[divider]
Meter=IMAGE
MeterStyle=dividerStyle | dividerCommon

[mainText]
Meter=STRING
MeterStyle=mainTextStyle | mainTextCommon
MeasureName=mRpmDisplay
ClipStringW=(#radius#*4)
ClipStringH=(#radius#*1.6)
ClipString=1
Text="%1"
ToolTipText="Current: %1#CRLF#Min: [mPeakMin:0] RPM | Max: [mPeakMax:0] RPM#CRLF#Right-click to reset peaks"
RightMouseUpAction=#peakResetAction#
DynamicVariables=1

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
ClipString=2
ClipStringW=100
Text=#fanLabel#

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

