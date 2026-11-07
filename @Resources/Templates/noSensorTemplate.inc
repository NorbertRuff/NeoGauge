; ============================================================
; No-sensor check (included by tempTemplate and fanTemplate)
;
; When HWiNFO reports no value under the gauge's registry name, the Registry
; measure reads a bare "0" (a real value always has a unit, even "0 RPM").
; The gauge then shows N/A and "no sensor", and a left-click opens the config
; tool's sensors page with this gauge selected.
;
; REQUIRED VARIABLES:
;   noSensorSource - Registry measure the main text shows
;   noSensorLabel  - The normal sub text
;   gaugeSlot      - This gauge's row on the sensors page (SLOTS in Sensors.lua)
; ============================================================

[Variables]
openSensors=[!WriteKeyValue Variables page sensors "#@#ConfigState.inc"][!WriteKeyValue Variables sensorSlot #gaugeSlot# "#@#ConfigState.inc"][!ActivateConfig "#ROOTCONFIG#" "Config.ini"][!Refresh "#ROOTCONFIG#"]
; mainText's left-click: nothing, or #openSensors# while there's no sensor
noSensorClick=

; IfMatch on the Registry measure itself never sees the missing value, but a
; String measure copying it reads "0" (tested)
[mNoSensor]
Measure=String
String=[#noSensorSource#]
DynamicVariables=1
UpdateDivider=2
IfMatch=^0?$
IfMatchAction=[!SetVariable noSensorClick """#openSensors#"""][!SetOption mainText Text "N/A"][!SetOption subText Text "no sensor: click to pick"][!UpdateMeter mainText][!UpdateMeter subText][!Redraw]
IfNotMatchAction=[!SetVariable noSensorClick ""][!SetOption mainText Text "%1"][!SetOption subText Text "#noSensorLabel#"][!UpdateMeter mainText][!UpdateMeter subText][!Redraw]
