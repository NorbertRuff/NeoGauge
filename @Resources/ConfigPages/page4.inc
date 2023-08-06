[Variables]
bgH=250
dotY=105
highlightColor=255,172,53,230

; ============================================================
; Roundline remainder setting

[roundlineHeader]
Meter=String
MeterStyle=headerText
X=130
Y=40
Text=Time Roundline
ToolTipText="The roundline meter will be displayed as a percentage of one of these periods of time"

[roundMin]
Meter=String
MeterStyle=subText
Text=Minute
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "0" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]

[roundHour]
Meter=String
MeterStyle=subText
Text=Hour
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "1" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]
X=5R

[round12]
Meter=String
MeterStyle=subText
Text=Half-day
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "2" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]
X=5R

[round24]
Meter=String
MeterStyle=subText
Text=Day
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "3" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]
X=130
Y=R

[roundWeek]
Meter=String
MeterStyle=subText
Text=Week
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "4" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]
X=5R

[roundMonth]
Meter=String
MeterStyle=subText
Text=Month
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "5" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]
X=5R

; [roundYear]
; Meter=String
; MeterStyle=subText
; Text=Year
; LeftMouseUpAction=[!WriteKeyValue "Variables" "timeRoundline" "6" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]
; X=5R

; ============================================================
; Time Format

[timeformHeader]
Meter=String
MeterStyle=headerText
Text=Time Format
Y=115
ToolTipText="The format for displaying the main time skin text.#CRLF#Click to go to the Rainmeter Docs for a full list of available format codes"
LeftMouseUpAction=["http://docs.rainmeter.net/manual/measures/time#FormatCodes"]


[tf12hr]
Meter=String
MeterStyle=subText
Text="12-hour"
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeFormat" "%#I:%M" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]

[tf24hr]
Meter=String
MeterStyle=subText
X=5R
Text="24-hour"
LeftMouseUpAction=[!WriteKeyValue "Variables" "timeFormat" "%#H:%M" "#@#Settings.txt"][!Refresh "CircuitousTwo\Time"][!Refresh #CURRENTCONFIG#]

[tfCustom]
Meter=String
MeterStyle=subText
X=130
Y=133
Prefix="code: "
Text=#timeFormat#
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 6"

; ============================================================
; Date format

[dateformHeader]
Meter=String
MeterStyle=headerText
Text=Date Format
Y=190
ToolTipText="The format for displaying the secondary time skin text.#CRLF#Click to go to the Rainmeter Docs for a full list of available format codes"
LeftMouseUpAction=["http://docs.rainmeter.net/manual/measures/time#FormatCodes"]

[dfCustom]
Meter=String
MeterStyle=subText
Prefix="code: "
Text=#dateFormat#
LeftMouseUpAction=!CommandMeasure "mSettingsInput" "ExecuteBatch 7"