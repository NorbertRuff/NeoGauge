; ============================================================
; Sensors page: pick the HWiNFO sensor behind each temperature / fan gauge
; ============================================================
; Sensors.lua reads HWiNFO's registry values once when the page opens and
; paints every meter below (Rainmeter can't create meters at runtime, so the
; rows are fixed meters that Lua fills and hides). Layout at 100% scale:
; slots in the left column (x 140-456), sensors for the selected slot in the
; right column (x 482-806), rows 26 apart starting at y 56.

[Variables]
pageColor=70,214,190,230
bgW=820
bgH=600
; Text typed into the label box (Config.ini Command19), read by setLabelFromInput()
sensorLabelInput=

; ------------------------------------------------------------
; Data

; Names of every value under VSB (Sensor0, Label0, Value0, ...), one per line
[mSensorList]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
OutputType=ValueList
UpdateDivider=-1

; Sensors.lua re-points RegValue at SensorN / LabelN / ValueN and reads it
[mSensorRead]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value0
UpdateDivider=-1

[mSensors]
Measure=Script
ScriptFile=#@#Scripts\Sensors.lua
UpdateDivider=2

; ------------------------------------------------------------
; Styles

; Mouse wheel over the sensor list changes page
[sSensScroll]
MouseScrollUpAction=[!CommandMeasure mSensors "scroll(-1)"]
MouseScrollDownAction=[!CommandMeasure mSensors "scroll(1)"]

[sSensRight]
StringAlign=Right

; One text row: clipped to its W, tall enough that rows leave no gaps to click through
[sSensRow]
H=(24*#s#)
ClipString=1

; ------------------------------------------------------------
; Headers and the shown-only-without-data note

[slotHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(20*#s#)
Hidden=1
Text=Gauges

[listHeader]
Meter=String
MeterStyle=sText | sHeader
X=(482*#s#)
Y=(20*#s#)
Hidden=1
Text=Sensors

; "2/3" when the list has more than 16 sensors
[listPage]
Meter=String
MeterStyle=sText | sNote | sSensRight
X=(806*#s#)
Y=(24*#s#)
Hidden=1
Text=

[sensorNote]
Meter=String
MeterStyle=sText | sNote
X=(140*#s#)
Y=(20*#s#)
W=((#bgW#-170)*#s#)
ClipString=2
Hidden=1
Text=

; ------------------------------------------------------------
; Slots (left): mark, slot name, HWiNFO label, live value

[slotMark1]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(56*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(1)"]

[slotName1]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(56*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(1)"]

[slotSensor1]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(58*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(1)"]

[slotValue1]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(56*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(1)"]

[slotMark2]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(82*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(2)"]

[slotName2]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(82*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(2)"]

[slotSensor2]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(84*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(2)"]

[slotValue2]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(82*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(2)"]

[slotMark3]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(108*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(3)"]

[slotName3]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(108*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(3)"]

[slotSensor3]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(110*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(3)"]

[slotValue3]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(3)"]

[slotMark4]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(134*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(4)"]

[slotName4]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(134*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(4)"]

[slotSensor4]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(136*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(4)"]

[slotValue4]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(134*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(4)"]

[slotMark5]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(160*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(5)"]

[slotName5]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(160*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(5)"]

[slotSensor5]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(162*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(5)"]

[slotValue5]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(160*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(5)"]

[slotMark6]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(186*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(6)"]

[slotName6]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(186*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(6)"]

[slotSensor6]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(188*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(6)"]

[slotValue6]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(186*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(6)"]

[slotMark7]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(212*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(7)"]

[slotName7]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(212*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(7)"]

[slotSensor7]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(214*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(7)"]

[slotValue7]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(212*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(7)"]

[slotMark8]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(238*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(8)"]

[slotName8]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(238*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(8)"]

[slotSensor8]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(240*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(8)"]

[slotValue8]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(238*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(8)"]

[slotMark9]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(264*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(9)"]

[slotName9]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(264*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(9)"]

[slotSensor9]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(266*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(9)"]

[slotValue9]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(264*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(9)"]

[slotMark10]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(290*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(10)"]

[slotName10]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(290*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(10)"]

[slotSensor10]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(292*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(10)"]

[slotValue10]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(290*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(10)"]

[slotMark11]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(316*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(11)"]

[slotName11]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(316*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(11)"]

[slotSensor11]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(318*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(11)"]

[slotValue11]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(316*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(11)"]

[slotMark12]
Meter=String
MeterStyle=sText | sSensRow
X=(140*#s#)
Y=(342*#s#)
W=(14*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "markClick(12)"]

[slotName12]
Meter=String
MeterStyle=sText | sSensRow
X=(156*#s#)
Y=(342*#s#)
W=(118*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(12)"]

[slotSensor12]
Meter=String
MeterStyle=sText | sNote | sSensRow
X=(276*#s#)
Y=(344*#s#)
W=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(12)"]

[slotValue12]
Meter=String
MeterStyle=sText | sSensRight
X=(456*#s#)
Y=(342*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "selectSlot(12)"]

; ------------------------------------------------------------
; Selected slot's display label (shown only for slots that have a label)

[labelHeader]
Meter=String
MeterStyle=sText | sNote
X=(140*#s#)
Y=(380*#s#)
Hidden=1
Text=Label shown on the gauge

[labelText]
Meter=String
MeterStyle=sText
X=(140*#s#)
Y=(398*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 19"]

; ------------------------------------------------------------
; Sensors of the selected slot's unit (right): label, device, live value

[rowLabel1]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(56*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(1)"]

[rowDevice1]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(58*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(1)"]

[rowValue1]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(56*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(1)"]

[rowLabel2]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(82*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(2)"]

[rowDevice2]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(84*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(2)"]

[rowValue2]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(82*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(2)"]

[rowLabel3]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(108*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(3)"]

[rowDevice3]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(110*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(3)"]

[rowValue3]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(108*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(3)"]

[rowLabel4]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(134*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(4)"]

[rowDevice4]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(136*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(4)"]

[rowValue4]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(134*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(4)"]

[rowLabel5]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(160*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(5)"]

[rowDevice5]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(162*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(5)"]

[rowValue5]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(160*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(5)"]

[rowLabel6]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(186*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(6)"]

[rowDevice6]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(188*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(6)"]

[rowValue6]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(186*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(6)"]

[rowLabel7]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(212*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(7)"]

[rowDevice7]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(214*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(7)"]

[rowValue7]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(212*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(7)"]

[rowLabel8]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(238*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(8)"]

[rowDevice8]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(240*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(8)"]

[rowValue8]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(238*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(8)"]

[rowLabel9]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(264*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(9)"]

[rowDevice9]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(266*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(9)"]

[rowValue9]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(264*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(9)"]

[rowLabel10]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(290*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(10)"]

[rowDevice10]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(292*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(10)"]

[rowValue10]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(290*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(10)"]

[rowLabel11]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(316*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(11)"]

[rowDevice11]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(318*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(11)"]

[rowValue11]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(316*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(11)"]

[rowLabel12]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(342*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(12)"]

[rowDevice12]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(344*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(12)"]

[rowValue12]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(342*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(12)"]

[rowLabel13]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(368*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(13)"]

[rowDevice13]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(370*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(13)"]

[rowValue13]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(368*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(13)"]

[rowLabel14]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(394*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(14)"]

[rowDevice14]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(396*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(14)"]

[rowValue14]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(394*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(14)"]

[rowLabel15]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(420*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(15)"]

[rowDevice15]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(422*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(15)"]

[rowValue15]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(420*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(15)"]

[rowLabel16]
Meter=String
MeterStyle=sText | sSensRow | sSensScroll
X=(482*#s#)
Y=(446*#s#)
W=(150*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(16)"]

[rowDevice16]
Meter=String
MeterStyle=sText | sNote | sSensRow | sSensScroll
X=(636*#s#)
Y=(448*#s#)
W=(104*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(16)"]

[rowValue16]
Meter=String
MeterStyle=sText | sSensRight | sSensScroll
X=(806*#s#)
Y=(446*#s#)
Hidden=1
Text=
LeftMouseUpAction=[!CommandMeasure mSensors "pick(16)"]
