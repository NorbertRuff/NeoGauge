[Variables]
bgH=250
dotY=130
highlightColor=250,100,100,230
;highlightColor=255,76,79,230

[woeidHeader]
Meter=String
MeterStyle=headerText
Text="Location Code"
Y=40
LeftMouseUpAction=["http://woeid.rosselliot.co.nz/"]
ToolTipText="click here to search for you woeid code online at #CRLF#http://woeid.rosselliot.co.nz/"

[woeidSet]
Meter=String
MeterStyle=subText
Text=#woeid#
Prefix="WOEID: "
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 8"

[unitHeader]
Meter=String
MeterStyle=headerText
Text="Metric/English"
Y=95
ToolTipText="toggle between English (f) or Metric (c) units"

[unitToggle]
Meter=String
MeterStyle=subText
Text=#unit#
Prefix="unit: "
LeftMouseUpAction=!CommandMeasure "mSettingsScript" "toggleWeatherUnit()"

[yahooCredit]
Meter=String
MeterStyle=subText
FontSize=10
Y=(#bgH#-45)
Text="weather data provided courtesy of#CRLF#Yahoo! Weather"