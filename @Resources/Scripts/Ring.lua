-- Ring.lua: one-time color setup for ringTemplate.inc
--
-- The ring's effects need the arc color as separate "R,G,B" and alpha values
-- (to fade the glow, comet and afterglow), plus lighter tints for the comet
-- head and peak tick. Rainmeter formulas can't take a color string apart,
-- so this splits #pieColor# once when the skin loads.

function Initialize()
	local r, g, b, a = parseColor(SKIN:GetVariable('pieColor'))
	if not r then
		r, g, b, a = 255, 255, 255, 200
	end

	local rgb = r .. ',' .. g .. ',' .. b
	local peak = towardWhite(r, g, b, 0.35)
	local head = towardWhite(r, g, b, 0.5)

	-- Base (below 75 %) colors, restored by [mFxLevel]
	SKIN:Bang('!SetVariable', 'fxBaseRGB', rgb)
	SKIN:Bang('!SetVariable', 'fxBaseA', a)
	SKIN:Bang('!SetVariable', 'fxBasePeakRGB', peak)
	SKIN:Bang('!SetVariable', 'fxBaseHeadRGB', head)

	-- Current colors, until the first reading picks a level
	SKIN:Bang('!SetVariable', 'fxRGB', rgb)
	SKIN:Bang('!SetVariable', 'fxA', a)
	SKIN:Bang('!SetVariable', 'fxPeakRGB', peak)
	SKIN:Bang('!SetVariable', 'fxHeadRGB', head)

	-- Warning colors (warnColor / alertColor in Settings.txt), split the same way
	setLevelColors('fxWarn', SKIN:GetVariable('warnColor'), 255, 200, 100, 230)
	setLevelColors('fxAlert', SKIN:GetVariable('alertColor'), 255, 100, 100, 230)
end

-- Sets <prefix>RGB, <prefix>A, <prefix>PeakRGB and <prefix>HeadRGB from a
-- color string, falling back to the given color when it can't be read
function setLevelColors(prefix, color, r0, g0, b0, a0)
	local r, g, b, a = parseColor(color)
	if not r then
		r, g, b, a = r0, g0, b0, a0
	end
	SKIN:Bang('!SetVariable', prefix .. 'RGB', r .. ',' .. g .. ',' .. b)
	SKIN:Bang('!SetVariable', prefix .. 'A', a)
	SKIN:Bang('!SetVariable', prefix .. 'PeakRGB', towardWhite(r, g, b, 0.35))
	SKIN:Bang('!SetVariable', prefix .. 'HeadRGB', towardWhite(r, g, b, 0.5))
end

-- "R,G,B[,A]" or hex "RRGGBB[AA]"; alpha defaults to 255
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

function towardWhite(r, g, b, f)
	local function mix(c) return math.floor(c + (255 - c) * f + 0.5) end
	return mix(r) .. ',' .. mix(g) .. ',' .. mix(b)
end
