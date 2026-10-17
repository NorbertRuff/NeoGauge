-- ThreadGrid.lua: one-shot setup for Processor\threads
--
-- Reads the logical processor count once, hides the rings (and disables the
-- CPU measures) above it, labels the header and sizes the background.
-- Nothing runs after load.

local MAX = 16
local count = MAX

function Initialize()
	SKIN:Bang('!UpdateMeasure', 'mThreadCount')
	local m = SKIN:GetMeasure('mThreadCount')
	local n = m and tonumber(m:GetStringValue())
	if n and n >= 1 then
		count = math.min(math.floor(n), MAX)
	end

	for i = count + 1, MAX do
		-- A hidden meter's X/Y still counts toward the window size, so park
		-- it at the origin as well
		SKIN:Bang('!SetOptionGroup', 't' .. i, 'X', '0')
		SKIN:Bang('!SetOptionGroup', 't' .. i, 'Y', '0')
		SKIN:Bang('!HideMeterGroup', 't' .. i)
		SKIN:Bang('!DisableMeasure', 'mThread' .. i)
	end

	SKIN:Bang('!SetOption', 'subText', 'Text', count .. ' threads')

	-- Background and divider cover the visible rings only, so the skin
	-- shrinks with them (e.g. 8 threads in the 1 x 16 layout)
	local cols = math.min(SKIN:ParseFormula(SKIN:GetVariable('tCols')) or 4, count)
	local rows = math.ceil(count / cols)
	local gridW = '(#edging#+' .. (cols - 1) .. '*#tPitchX#+2*#radius#)'
	SKIN:Bang('!SetOption', 'Bg', 'W', '(' .. gridW .. '+#edging#)')
	SKIN:Bang('!SetOption', 'Bg', 'H', '(#tTop#+' .. rows .. '*#tPitchY#)')
	SKIN:Bang('!SetOption', 'divider', 'W', '(' .. gridW .. '-#edging#)')
	SKIN:Bang('!UpdateMeter', 'Bg')
	SKIN:Bang('!UpdateMeter', 'divider')
end

function Update()
	return count
end

-- Test helper for tools/Probe.ps1 (inline Lua only calls named functions)
function visible()
	return count
end
