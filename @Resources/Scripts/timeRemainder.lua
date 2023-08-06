function Initialize()
	-- hour, half, day, week, month, year
	unit = tonumber(SKIN:GetVariable('timeRoundline', 1))
	
	if (unit > 6 or unit < 0) then
		print('invalid time skin roundline setting')
		unit = 1
	end
	
	daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	
end

function Update()
	currentTime = os.date("!*t")
	
	if unit == 0 then
		return 60
	
	elseif unit == 1 then
		return 3600
	
	elseif unit == 2 then
		return 43200
	
	elseif unit == 3 then
		return 86400
	
	elseif unit == 4 then
		return 604800
	
	elseif unit == 5 then
		if isLeapYear(currentTime.year) then 
			daysInMonth[2] = 29
		end
		return (86400 * daysInMonth[currentTime.month])
	
	elseif unit == 6 then
		if isLeapYear(currentTime.year) then 
			return (86400 * 366)
		else 
			return (86400 * 365) 
		end
	
	else
		print('wth?')
		return 0
	end
	
end

function isLeapYear(year)
	return (year % 4 == 0) and ((year % 100 ~= 0) or (year % 400 == 0))
end