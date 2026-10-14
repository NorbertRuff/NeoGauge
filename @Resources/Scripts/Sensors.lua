-- Sensors.lua: HWiNFO sensor data for the config tool's "sensors" page
--
-- Loaded by the [mSensors] Script measure in ConfigPages\sensors.inc, so it
-- costs nothing while the page is closed. Initialize() reads every sensor once:
--   mSensorList  Registry ValueList of HKCU\SOFTWARE\HWiNFO64\VSB (value names)
--   mSensorRead  Registry measure re-pointed at SensorN / LabelN / ValueN
--
-- Globals (also read by the probe tests):
--   SLOTS    the gauge slots the page edits, in display order
--   sensors  sensors[N] = { device, label, value, unit, name }
--   order    sorted array of the indexes N HWiNFO reports (gaps are normal)

-- key: variable in Settings.txt holding "ValueN"; label: variable with the
-- display name; raw: variable holding "ValueRawN" (fans only)
SLOTS = {
	{ key = 'cpuTemp1', title = 'CPU temp', unit = 'temp', label = 'cpuTemp1Label' },
	{ key = 'cpuTemp2', title = 'CPU second line', unit = 'temp' },
	{ key = 'dimm1Temp', title = 'RAM temp', unit = 'temp', label = 'dimm1Label' },
	{ key = 'gpuTemp', title = 'GPU temp', unit = 'temp', label = 'gpuTempLabel' },
	{ key = 'gpuRpm', title = 'GPU fan', unit = 'rpm' },
	{ key = 'pumpTemp', title = 'Pump temp', unit = 'temp', label = 'pumpLabel' },
	{ key = 'pumpRpm', title = 'Pump RPM', unit = 'rpm' },
	{ key = 'fan1rpm', title = 'Fan 1', unit = 'rpm', label = 'fan1Label', raw = 'fan1RawRpm' },
	{ key = 'fan2rpm', title = 'Fan 2', unit = 'rpm', label = 'fan2Label', raw = 'fan2RawRpm' },
	{ key = 'fan3rpm', title = 'Fan 3', unit = 'rpm', label = 'fan3Label', raw = 'fan3RawRpm' },
	{ key = 'fan4rpm', title = 'Fan 4', unit = 'rpm', label = 'fan4Label', raw = 'fan4RawRpm' },
	{ key = 'disk1Temp', title = 'Disk temp', unit = 'temp', label = 'disk1Label' },
}

local NO_DATA_NOTE = "HWiNFO isn't reporting sensors. In HWiNFO: Settings > HWiNFO Gadget > "
	.. "Enable reporting to Gadget, then tick each sensor's 'Report value in Gadget'."

sensors = {}
order = {}

local function trim(text)
	return (tostring(text):gsub('^%s+', ''):gsub('%s+$', ''))
end

-- The value of a Registry measure re-pointed at the named registry value
local function readRegistry(valueName)
	SKIN:Bang('!SetOption', 'mSensorRead', 'RegValue', valueName)
	SKIN:Bang('!UpdateMeasure', 'mSensorRead')
	return SKIN:GetMeasure('mSensorRead'):GetStringValue()
end

local ROWS = 16          -- list row meters (rowLabel1..16)
local curSlot = 1        -- selected slot, an index into SLOTS
local page = 1           -- list page, 1-based
local shown = {}         -- shown[r] = sensor index on list row r (nil when empty)

function Initialize()
	loadSensors()
	curSlot = math.max(1, math.min(#SLOTS, tonumber(SKIN:GetVariable('sensorSlot', '1')) or 1))
	paint()
end

-- Every 2 s: re-read ValueN for the 12 slots and the visible list rows only
-- (at most 28 registry reads), then repaint. paint() sends a bang only for
-- what changed. With no HWiNFO data it looks for the value list again, so the
-- page fills in once HWiNFO starts.
function Update()
	if #order == 0 then
		loadSensors()
		if #order > 0 then paint() end
		return 0
	end

	local seen = {}
	local function refresh(n)
		if n and sensors[n] and not seen[n] then
			seen[n] = true
			sensors[n].value = trim(readRegistry('Value' .. n))
		end
	end
	for i = 1, #SLOTS do refresh(slotIndex(i)) end
	for r = 1, ROWS do refresh(shown[r]) end
	paint()
	return 0
end

-- ------------------------------------------------------------------
-- Reading HWiNFO

-- Sorted indexes N from the value names "SensorN", one per line
function parseIndexes(listText)
	local list = {}
	for line in tostring(listText or ''):gmatch('[^\r\n]+') do
		local n = trim(line):match('^Sensor(%d+)$')
		if n then list[#list + 1] = tonumber(n) end
	end
	table.sort(list)
	return list
end

-- 'temp' (ends in a degree sign + C/F), 'rpm', or 'other' (volts, watts, ...).
-- The degree sign is non-ASCII, so match "any byte that isn't a letter, digit
-- or space" before the C/F instead of writing it.
function unitClass(valueText)
	local text = trim(valueText or '')
	if text:match('RPM$') then return 'rpm' end
	if text:match('[^%w%s]C$') or text:match('[^%w%s]F$') then return 'temp' end
	return 'other'
end

-- "device|label" without characters Rainmeter reads as variable syntax
function cleanName(device, label)
	local function clean(text)
		return trim((tostring(text or ''):gsub('[#%[%]"]', '')))
	end
	return clean(device) .. '|' .. clean(label)
end

function readSensor(n)
	local s = sensors[n]
	if not s then return end
	s.value = trim(readRegistry('Value' .. n))
	s.unit = unitClass(s.value)
end

function loadSensors()
	sensors = {}
	SKIN:Bang('!UpdateMeasure', 'mSensorList')
	order = parseIndexes(SKIN:GetMeasure('mSensorList'):GetStringValue())
	for _, n in ipairs(order) do
		local device = trim(readRegistry('Sensor' .. n))
		local label = trim(readRegistry('Label' .. n))
		sensors[n] = { device = device, label = label, name = cleanName(device, label) }
		readSensor(n)
	end
end

-- ------------------------------------------------------------------
-- Slots

-- N of the slot's "ValueN" variable, or nil when it isn't one
function slotIndex(i)
	local slot = SLOTS[i]
	if not slot then return nil end
	local n = SKIN:GetVariable(slot.key, ''):match('^%s*Value(%d+)%s*$')
	return n and tonumber(n)
end

local function findByName(name)
	for _, n in ipairs(order) do
		if sensors[n].name == name then return n end
	end
end

-- 'ok' | 'missing' | 'moved', and the index now carrying the stored name (if any)
function slotStatus(i)
	local slot = SLOTS[i]
	if not slot then return 'missing', nil end

	local stored = trim((SKIN:GetVariable(slot.key .. 'Sensor', ''):gsub('[#%[%]"]', '')))
	local n = slotIndex(i)
	local s = n and sensors[n]

	local rematch = (stored ~= '') and findByName(stored) or nil
	if rematch == n then rematch = nil end

	if not s then return 'missing', rematch end
	if stored ~= '' and s.name ~= stored then return 'moved', rematch end
	return 'ok', nil
end

-- Probe tests can only call functions ([&mSensors:fn(args)] doesn't evaluate
-- expressions like #order), so these two expose the data
function count()
	return #order
end

function unitOf(n)
	local s = sensors[n]
	return s and s.unit or 'none'
end

-- "N|label|value|status" for the probe tests
function describe(i)
	local n = slotIndex(i)
	if not n then return '-|-|-|missing' end
	local s = sensors[n]
	if not s then return n .. '|-|-|missing' end
	return n .. '|' .. s.label .. '|' .. s.value .. '|' .. slotStatus(i)
end

-- ------------------------------------------------------------------
-- Painting
--
-- paint() makes every meter of the page match the data. The page's meters are
-- fixed (Rainmeter can't create them at runtime), so unused rows are hidden.
-- It is safe to call as often as needed: each change is remembered in `cache`
-- and a bang goes out only when a value differs from the last one sent.

local MARK_MISSING = '255,100,100,230'
local MARK_MOVED = '255,200,100,230'

local cache = {}
local touched = {}   -- meters whose text/colour changed, for !UpdateMeter
local dirty = false

-- Text for a meter: brackets and quotes would read as Rainmeter syntax
local function display(text)
	return (tostring(text or ''):gsub('[%[%]"]', ''))
end

local function setOption(meter, option, value)
	local key = meter .. '|' .. option
	if cache[key] == value then return end
	cache[key] = value
	SKIN:Bang('!SetOption', meter, option, value)
	touched[meter] = true
	dirty = true
end

local function setHidden(meter, hide)
	local key = meter .. '|hidden'
	if cache[key] == hide then return end
	cache[key] = hide
	SKIN:Bang(hide and '!HideMeter' or '!ShowMeter', meter)
	dirty = true
end

local function setVariable(name, value)
	local key = '$' .. name
	if cache[key] == value then return end
	cache[key] = value
	SKIN:Bang('!SetVariable', name, value)
end

local function flush()
	for meter in pairs(touched) do SKIN:Bang('!UpdateMeter', meter) end
	touched = {}
	if dirty then
		SKIN:Bang('!Redraw')
		dirty = false
	end
end

local function color(name)
	return SKIN:GetVariable(name, '255,255,255,230')
end

-- Sensors whose unit class matches the selected slot, in `order`. Volts, watts
-- and the like ('other') are never listed.
function listRows()
	local class = SLOTS[curSlot].unit
	local list = {}
	if class == 'temp' or class == 'rpm' then
		for _, n in ipairs(order) do
			if sensors[n].unit == class then list[#list + 1] = n end
		end
	end
	return list
end

local function pageCount(total)
	return math.max(1, math.ceil(total / ROWS))
end

local function paintSlots(hasData)
	local accent, normal = color('pageColor'), color('textColor')
	for i, slot in ipairs(SLOTS) do
		local selected = (i == curSlot)
		for _, prefix in ipairs({ 'slotMark', 'slotName', 'slotSensor', 'slotValue' }) do
			setHidden(prefix .. i, not hasData)
		end
		if hasData then
			local status, rematchN = slotStatus(i)
			local n = slotIndex(i)
			local s = n and sensors[n]

			setOption('slotName' .. i, 'Text', slot.title)
			setOption('slotName' .. i, 'FontColor', selected and accent or normal)
			setOption('slotSensor' .. i, 'Text', s and display(s.label) or 'not found')
			setOption('slotValue' .. i, 'Text', s and display(s.value) or '')

			-- The mark's click re-matches when the stored name has a new index
			local mark, markColor = '', normal
			if status == 'missing' then
				mark, markColor = '!', MARK_MISSING
			elseif status == 'moved' then
				mark, markColor = '~', MARK_MOVED
			end
			setOption('slotMark' .. i, 'Text', mark)
			setOption('slotMark' .. i, 'FontColor', markColor)
			setOption('slotMark' .. i, 'ToolTipText', rematchN and 'Sensor moved: click to re-match' or '')
		end
	end
end

local function paintList(hasData)
	local rowsAll = listRows()
	local pages = pageCount(#rowsAll)
	if page > pages then page = pages end
	if page < 1 then page = 1 end

	local class = SLOTS[curSlot].unit
	setHidden('listHeader', not hasData)
	setHidden('listPage', not hasData)
	setOption('listHeader', 'Text', class == 'rpm' and 'Fan sensors' or class == 'temp' and 'Temperature sensors' or 'Sensors')
	setOption('listPage', 'Text', pages > 1 and (page .. '/' .. pages) or '')

	local accent, normal, dim = color('pageColor'), color('textColor'), color('dimColor')
	local current = slotIndex(curSlot)
	for r = 1, ROWS do
		local n = hasData and rowsAll[(page - 1) * ROWS + r] or nil
		local s = n and sensors[n]
		shown[r] = n

		local empty = hasData and #rowsAll == 0 and r == 1
		setHidden('rowLabel' .. r, not (s or empty))
		setHidden('rowDevice' .. r, not s)
		setHidden('rowValue' .. r, not s)

		if s then
			local c = (n == current) and accent or normal
			setOption('rowLabel' .. r, 'Text', display(s.label))
			setOption('rowLabel' .. r, 'FontColor', c)
			setOption('rowLabel' .. r, 'ToolTipText', display(s.device) .. ' - ' .. display(s.label))
			setOption('rowDevice' .. r, 'Text', display(s.device))
			setOption('rowValue' .. r, 'Text', display(s.value))
			setOption('rowValue' .. r, 'FontColor', c)
		elseif empty then
			setOption('rowLabel' .. r, 'Text', 'no matching sensors')
			setOption('rowLabel' .. r, 'FontColor', dim)
			setOption('rowLabel' .. r, 'ToolTipText', '')
		end
	end
end

-- The selected slot's display label (only slots with a label variable have one)
local function paintLabel(hasData)
	local slot = SLOTS[curSlot]
	local label = slot.label and SKIN:GetVariable(slot.label, '') or ''
	local editable = hasData and slot.label ~= nil

	setHidden('labelHeader', not editable)
	setHidden('labelText', not editable)
	if editable then
		setOption('labelText', 'Text', label ~= '' and display(label) or '-')
	end
	setVariable('sensorLabelText', (label:gsub('"', '')))
end

function paint()
	local hasData = #order > 0

	setHidden('sensorNote', hasData)
	setOption('sensorNote', 'Text', hasData and '' or NO_DATA_NOTE)
	setHidden('slotHeader', not hasData)

	paintSlots(hasData)
	paintList(hasData)
	paintLabel(hasData)
	flush()
end

-- ------------------------------------------------------------------
-- Actions

-- Remember the selection in Config.ini without refreshing the skin
function selectSlot(i)
	i = tonumber(i)
	if not i or not SLOTS[i] then return end
	curSlot = i
	page = 1
	SKIN:Bang('!WriteKeyValue', 'Variables', 'sensorSlot', tostring(i),
		SKIN:ReplaceVariables('#CURRENTPATH##CURRENTFILE#'))
	paint()
end

-- dir: 1 = next page, -1 = previous; stays within the pages that exist.
-- Returns the page so inline probes can call it.
function scroll(dir)
	local pages = pageCount(#listRows())
	page = math.max(1, math.min(pages, page + (tonumber(dir) or 0)))
	paint()
	return page
end

-- ------------------------------------------------------------------
-- Writing Settings.txt
--
-- Each write is followed by !RefreshGroup rsm so the gauges pick it up (and the
-- config window repaints from the new values).

local function settingsFile()
	return SKIN:ReplaceVariables('#@#Settings.txt')
end

local function write(key, value)
	SKIN:Bang('!WriteKeyValue', 'Variables', key, value, settingsFile())
end

-- Point slot i at sensor n: the ValueN variable(s) plus the name the check compares
local function assign(i, n)
	local slot, s = SLOTS[i], sensors[n]
	if not slot or not s then return end
	write(slot.key, 'Value' .. n)
	if slot.raw then write(slot.raw, 'ValueRaw' .. n) end
	write(slot.key .. 'Sensor', s.name)
	SKIN:Bang('!RefreshGroup', 'rsm')
end

-- Click on list row `row` (1..16 of the current page): the selected slot reads that sensor
function pick(row)
	row = tonumber(row)
	if not row then return end
	local n = listRows()[(page - 1) * ROWS + row]
	if n then assign(curSlot, n) end
end

-- Slot i follows its stored sensor name to the index now carrying it
function rematch(i)
	i = tonumber(i)
	if not i or not SLOTS[i] then return end
	local _, n = slotStatus(i)
	if n then assign(i, n) end
end

-- Click on a slot's status mark: re-match when possible, else just select the slot
function markClick(i)
	i = tonumber(i)
	if not i or not SLOTS[i] then return end
	local _, n = slotStatus(i)
	if n then rematch(i) else selectSlot(i) end
end

-- The selected slot's display label. Quotes are removed (they would break the
-- written value); anything else, # included, is kept. Slots without a label
-- variable, and empty text, are ignored (nothing is written).
function setLabel(text)
	local slot = SLOTS[curSlot]
	if not slot or not slot.label then return end
	text = trim((tostring(text or ''):gsub('"', '')))
	if text == '' then return end
	write(slot.label, text)
	SKIN:Bang('!RefreshGroup', 'rsm')
end

-- Entry point of the label text box: Config.ini's Command19 stores the typed
-- text in sensorLabelInput first, so apostrophes and backslashes never pass
-- through a Lua string literal.
function setLabelFromInput()
	setLabel(SKIN:GetVariable('sensorLabelInput', ''))
end

-- Probe tests (see count() above)
function nameOf(n)
	local s = sensors[tonumber(n)]
	return s and s.name or 'none'
end

-- Tooltip currently set on slot i's status mark
function tipOf(i)
	return SKIN:GetMeter('slotMark' .. tostring(i)):GetOption('ToolTipText', '')
end

function rowCount()
	return #listRows()
end

function pageNo()
	return page
end
