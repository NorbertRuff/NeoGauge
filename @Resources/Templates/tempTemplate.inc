; ============================================================
; Temperature Template
; 
; REQUIRED VARIABLES:
;   tempRegValue    - HWiNFO64 registry value name (e.g., "Value1", "Value13")
;                     Find values by running: reg query HKEY_CURRENT_USER\SOFTWARE\HWiNFO64\VSB
;   tempLabel       - Display label for the sensor (shown in subtext)
;
; OPTIONAL VARIABLES:
;   tempPercentFormula - Formula for percentage calculation (defaults to mTemp/100)
;   tempRpmRegValue    - RPM registry value if showing RPM on hover
;   tempRpmLabel       - Label for RPM display
;   tempShowRpm         - Set to 1 to show RPM, 0 to hide (default: 0)
;
; USAGE:
;   1. Set required variables before including this template
;   2. Include appearance file (e.g., @include2=#@#Apparence\fan.txt)
;   3. Include this template: @include6="#@#Templates\tempTemplate.inc"
;
; ERROR HANDLING:
;   - Handles missing/invalid registry values with Substitute
;   - Displays "N/A" for unavailable sensors
;   - Peak values tracked automatically with MinValue/MaxValue
; ============================================================

[mTemp]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#tempRegValue#
; UpdateDivider=5 - Temperature changes slowly, update every 5 seconds (5000ms)
; Uncomment and adjust based on your needs (lower = more frequent updates)
; Track peak values automatically
MinValue=0
MaxValue=100
; Handle missing or invalid sensor values gracefully
Substitute="Unknown":"N/A","-1":"N/A","":"N/A"

[mPercent]
Measure=Calc
Formula=(mTemp/100)

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
MeasureName=mTemp
ClipStringW=20
ClipStringH=40
ClipString=1
Text="%1"

[subText]
Meter=STRING
MeterStyle=subTextStyle | subTextCommon
MeasureName=mPercent
NumOfDecimals=2
ClipString=2
ClipStringW=80
Text=#tempLabel#

[Icon]
Meter=Image
MeterStyle=iconStyle
ImageName=icon.png
ImageTint=#colorIcon#

