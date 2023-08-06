function Update()
	local measure = SKIN:GetMeasure('mWin7Audio'):GetValue()
	SKIN:Bang('!SetOption', 'mainText', 'Text', measure == -1 and 'muted' or 'vol ' .. measure .. '%')
	
	if measure >= 0 then
		oldValue = measure
		return measure / 100
	else
		return (oldValue or 0) / 100
	end
end -- Update

function Angle(x, y)
--	if math.sqrt(math.abs(x) ^ 2 + math.abs(y) ^ 2) <= 20 then
--		SKIN:Bang('!CommandMeasure', 'mWin7Audio', 'ToggleMute')
--		SKIN:Bang('!Update')
	if x == 0 and y == 0 then
		SendBang(0)
	elseif x == 0 and y > 0 then
		SendBang(math.pi / 2)
	elseif y == 0 and x > 0 then
		SendBang(math.pi)
	elseif x == 0 and y < 0 then
		SendBang(math.pi * 1.5)
	elseif x > 0 and y > 0 then
		SendBang(math.atan(y / x))
	elseif x < 0 and y > 0 then
		SendBang(math.atan(math.abs(x) / y) + math.pi / 2)
	elseif x < 0 and y < 0 then
		SendBang(math.atan(math.abs(y) / math.abs(x)) + math.pi)
	elseif x > 0 and y < 0 then
		SendBang(math.atan(x / math.abs(y)) + math.pi * 1.5)
	end
end -- Angle

function SendBang(rangle)
	SKIN:Bang('!CommandMeasure', 'mWin7Audio', 'SetVolume ' .. ((rangle / (2 * math.pi)) * 100))
	SKIN:Bang('!Update')
end -- SendBang