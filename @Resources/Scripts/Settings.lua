-- Settings.lua: logic for Config.ini
--
-- Pages mark their choices with meter names, and Initialize() colors them:
--   opt_<variable>_<value>  highlighted when the variable has that value
--                           (dots in the value become underscores)
--   tog_<variable>          bright when on, dim when off (see TOGGLES)

-- Variables whose current value picks an opt_ meter. The ones with a custom
-- meter fall back to it when no preset matches.
local OPTIONS = {
	{ var = 'page' },
	{ var = 'component' },
	{ var = 'orient' },
	{ var = 'fontStyle' },
	{ var = 'size', custom = true },
	{ var = 'scale', custom = true },
	{ var = 'trashMax' },
	{ var = 'timeRoundline' },
	{ var = 'fxEaseMs' },
	{ var = 'fxGlow' },
	{ var = 'fxGlowStrength' },
}

-- Effects page presets (fx* in Settings.txt)
local FX_PRESETS = {
	off = { fxSmooth = 0, fxGlow = 0, fxPeak = 0, fxAfterglow = 0, fxComet = 0, fxRoundCaps = 0 },
	light = { fxSmooth = 1, fxGlow = 0, fxPeak = 0, fxAfterglow = 0, fxComet = 0, fxRoundCaps = 0 },
	balanced = { fxSmooth = 1, fxGlow = 2, fxPeak = 1, fxAfterglow = 1, fxComet = 0, fxRoundCaps = 0 },
	everything = { fxSmooth = 1, fxGlow = 2, fxPeak = 1, fxAfterglow = 1, fxComet = 1, fxRoundCaps = 1 },
}

-- tog_ meters: the value that counts as "on"
local TOGGLES = {
	hideInnerEdge = '0',
	hideOuterEdge = '0',
	hidePieBg = '0',
	hideDivider = '0',
	hideSubText = '0',
	trashAutoEmpty = '1',
	fxSmooth = '1',
	fxPeak = '1',
	fxAfterglow = '1',
	fxComet = '1',
	fxRoundCaps = '1',
}

local USED_BY = {
	cpu = 'CPU',
	ram = 'RAM, swap',
	io = 'drive activity',
	disk = 'disks 1-5',
	fan = 'CPU / GPU / RAM / disk / pump temperatures, fans 1-4',
	networkDown = 'download, uptime',
	networkUp = 'upload',
	wifi = 'wifi',
	battery = 'battery',
	default = 'CPU cores, clock, volume, recycle bin, background bars',
}

local COLOR_VARS = { 'pieColor', 'innerRingColor', 'pieBgColor' }

function Initialize()
	local s = tonumber(SKIN:GetVariable('scale', '1')) or 1
	accent = SKIN:GetVariable('pageColor')
	dim = SKIN:GetVariable('dimColor')

	resources = SKIN:ReplaceVariables('#@#')
	settingsFile = resources .. 'Settings.txt'
	appFile = resources .. 'Apparence\\' .. SKIN:GetVariable('component', 'default') .. '.txt'

	-- InputText can't evaluate formulas, so hand it ready-made pixel sizes
	-- (FontSize is in points, which take more pixels than the box height suggests)
	SKIN:Bang('!SetVariable', 'inFont', math.floor(8 * s + 0.5))
	SKIN:Bang('!SetVariable', 'inW', math.floor(180 * s + 0.5))
	SKIN:Bang('!SetVariable', 'inH', math.floor(24 * s + 0.5))

	highlightOptions()
	paintToggles()

	local page = SKIN:GetVariable('page')
	if page == 'appearance' then
		setAlphaBars()
		setText('usedBy', 'used by: ' .. (USED_BY[SKIN:GetVariable('component')] or '?'))
	elseif page == 'system' then
		setText('uploadMax', string.format('%.1f', bytesToMegabits(SKIN:GetVariable('uploadMax'))))
		setText('downloadMax', string.format('%.1f', bytesToMegabits(SKIN:GetVariable('downloadMax'))))
	end
end

-- ------------------------------------------------------------------
-- Highlighting

function setText(meter, text)
	if SKIN:GetMeter(meter) then
		SKIN:Bang('!SetOption', meter, 'Text', text)
	end
end

function setColor(meter, color)
	if SKIN:GetMeter(meter) then
		SKIN:Bang('!SetOption', meter, 'FontColor', color)
	end
end

function meterKey(value)
	return (tostring(value):gsub('^%s+', ''):gsub('%s+$', ''):gsub('%.', '_'))
end

function highlightOptions()
	for _, o in ipairs(OPTIONS) do
		local value = SKIN:GetVariable(o.var)
		if value then
			local name = 'opt_' .. o.var .. '_' .. meterKey(value)
			if SKIN:GetMeter(name) then
				setColor(name, accent)
			elseif o.custom then
				setColor('opt_' .. o.var .. '_custom', accent)
			end
		end
	end

	-- Margins are stored as a formula like (#radius#*0.3): match the factor
	local edging = SKIN:GetVariable('edging') or ''
	if edging == '0' then
		setColor('opt_edging_0', accent)
	else
		local factor = tonumber(edging:match('%*%s*([%d%.]+)%s*%)%s*$') or '')
		local name = factor and ('opt_edging_' .. math.floor(factor * 100 + 0.5))
		if name and SKIN:GetMeter(name) then
			setColor(name, accent)
		else
			setColor('opt_edging_custom', accent)
		end
	end

	-- Effects preset: highlight the one every fx switch matches, if any
	for name, preset in pairs(FX_PRESETS) do
		local match = true
		for var, value in pairs(preset) do
			-- fxGlow only has to be on/off to count (any glow mode fits a preset with glow)
			local current = tonumber(SKIN:GetVariable(var) or '') or -1
			if var == 'fxGlow' then
				if (current > 0) ~= (value > 0) then match = false end
			elseif current ~= value then
				match = false
			end
		end
		if match then setColor('opt_fxPreset_' .. name, accent) end
	end

	-- Clock presets are whole format strings
	local timeFormat = SKIN:GetVariable('timeFormat') or ''
	if timeFormat == '%#I:%M' then setColor('opt_timeFormat_12', accent) end
	if timeFormat == '%#H:%M' then setColor('opt_timeFormat_24', accent) end
end

function paintToggles()
	for var, onValue in pairs(TOGGLES) do
		local on = (SKIN:GetVariable(var) or '') == onValue
		setColor('tog_' .. var, on and accent or dim)
	end
end

-- ------------------------------------------------------------------
-- Actions called from the page meters

-- where: 'app' = current appearance file, 'settings' = Settings.txt
function toggle(var, where)
	local current = SKIN:GetVariable(var) or '0'
	local file = (where == 'settings') and settingsFile or appFile
	SKIN:Bang('!WriteKeyValue', 'Variables', var, current == '1' and '0' or '1', file)
	SKIN:Bang('!RefreshGroup', 'rsm')
end

function setFxPreset(name)
	local preset = FX_PRESETS[name]
	if not preset then return end
	for var, value in pairs(preset) do
		SKIN:Bang('!WriteKeyValue', 'Variables', var, value, settingsFile)
	end
	SKIN:Bang('!RefreshGroup', 'rsm')
end

function setColors(arc, rings, track)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'pieColor', arc, appFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'innerRingColor', rings, appFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'pieBgColor', track, appFile)
	SKIN:Bang('!RefreshGroup', 'rsm')
end

-- percent: where the opacity bar was clicked, 0-100
function changeAlpha(var, percent)
	local r, g, b = parseColor(SKIN:GetVariable(var))
	if not r then return end
	local alpha = math.floor(math.max(0, math.min(100, percent)) * 2.55 + 0.5)
	SKIN:Bang('!WriteKeyValue', 'Variables', var, string.format('%d,%d,%d,%d', r, g, b, alpha), appFile)
	SKIN:Bang('!RefreshGroup', 'rsm')
end

-- ------------------------------------------------------------------
-- Colors: "R,G,B[,A]" or hex "RRGGBB[AA]"

function parseColor(color)
	color = color or ''
	local r, g, b, a = color:match('^%s*(%d+)%s*,%s*(%d+)%s*,%s*(%d+)%s*,?%s*(%d*)')
	if r then
		return tonumber(r), tonumber(g), tonumber(b), tonumber(a) or 255
	end
	local hr, hg, hb, ha = color:match('^%s*(%x%x)(%x%x)(%x%x)(%x?%x?)')
	if hr then
		return tonumber(hr, 16), tonumber(hg, 16), tonumber(hb, 16), (ha ~= '' and tonumber(ha, 16)) or 255
	end
	return nil
end

function setAlphaBars()
	for i, var in ipairs(COLOR_VARS) do
		local bg = SKIN:GetMeter('c' .. i .. 'AlphaBg')
		local _, _, _, a = parseColor(SKIN:GetVariable(var))
		if bg and a then
			SKIN:Bang('!SetOption', 'c' .. i .. 'Alpha', 'W', math.floor(bg:GetW() * a / 255 + 0.5))
		end
	end
end

-- ------------------------------------------------------------------
-- Network speeds are stored in bytes/s but shown in Mb/s

function setNetworkSpeed(var, text)
	local mbps = tonumber(text)
	if not mbps or mbps <= 0 then return end
	SKIN:Bang('!WriteKeyValue', 'Variables', var, megabitsToBytes(mbps), settingsFile)
end

-- Decimal megabits (1 Mb = 1,000,000 bits), the unit internet plans use
function megabitsToBytes(mbits)
	return math.floor(mbits * 1000000 / 8)
end

function bytesToMegabits(bytes)
	return (tonumber(bytes) or 0) * 8 / 1000000
end
