; ============================================================
; Time page: settings for the Time skin (clock.ini)
; ============================================================

[Variables]
pageColor=255,172,53,230

[roundlineHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(20*#s#)
Text=Ring shows progress through the
ToolTipText=The clock's ring fills up over this period

[opt_timeRoundline_0]
Meter=String
MeterStyle=sText | sFirst
Text=minute
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 0 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeRoundline_1]
Meter=String
MeterStyle=sText | sNext
Text=hour
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 1 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeRoundline_2]
Meter=String
MeterStyle=sText | sNext
Text=half day
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 2 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeRoundline_3]
Meter=String
MeterStyle=sText | sNext
Text=day
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 3 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeRoundline_4]
Meter=String
MeterStyle=sText | sNext
Text=week
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 4 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeRoundline_5]
Meter=String
MeterStyle=sText | sNext
Text=month
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 5 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeRoundline_6]
Meter=String
MeterStyle=sText | sNext
Text=year
LeftMouseUpAction=[!WriteKeyValue Variables timeRoundline 6 "#@#Settings.txt"][!RefreshGroup rsm]

[timeFormatHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(76*#s#)
Text=Time format
ToolTipText=Click the code to type your own. Click the header for the list of codes.
LeftMouseUpAction=["https://docs.rainmeter.net/manual/measures/time/#FormatCodes"]

[opt_timeFormat_12]
Meter=String
MeterStyle=sText | sFirst
Text=12-hour
LeftMouseUpAction=[!WriteKeyValue Variables timeFormat "%#I:%M" "#@#Settings.txt"][!RefreshGroup rsm]

[opt_timeFormat_24]
Meter=String
MeterStyle=sText | sNext
Text=24-hour
LeftMouseUpAction=[!WriteKeyValue Variables timeFormat "%#H:%M" "#@#Settings.txt"][!RefreshGroup rsm]

[timeFormatLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=code

[timeFormat]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=#timeFormat#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 13"]

[dateFormatHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(132*#s#)
Text=Date format
ToolTipText=Click the code to type your own. Click the header for the list of codes.
LeftMouseUpAction=["https://docs.rainmeter.net/manual/measures/time/#FormatCodes"]

[dateFormatLabel]
Meter=String
MeterStyle=sText | sFirst | sNote
FontSize=(10*#s#)
Text=code

[dateFormat]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=#dateFormat#
LeftMouseUpAction=[!CommandMeasure mInput "ExecuteBatch 14"]
