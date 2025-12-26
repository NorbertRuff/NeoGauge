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
ClipStringW=20
ClipStringH=40
ClipString=1
Text="%1"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
ClipString=2
ClipStringW=80
Text=#fanLabel#

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

