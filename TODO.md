# TODO - NeoGauge Rainmeter Skin

This document tracks future improvements, refactoring tasks, and maintenance items for the NeoGauge skin.

## ✅ Done (2.0)

- [x] **Dynamic color coding**: yellow from 75 %, red from 90 %, now part of the shared ring (`Templates/ringTemplate.inc`), opt-out per gauge with `fxLevels=0`
- [x] **Peak value tracking**: `Templates/peakTemplate.inc` records real highs/lows (MinValue/MaxValue are only scaling bounds, and `!ResetStats` only resets network counters); right-click resets
- [x] **Ring effects** (replaces the TransformMatrix idea): smooth easing, glow (always / grows with load), peak-hold tick, afterglow, comet arc, round ends. Global, picked on the config tool's **effects** page; frames only run while a ring moves
- [x] **Config tool rebuilt**: info / appearance / effects / system / time pages, all values highlighted, everything scales with the display
- [x] **High-DPI support**: `scale` in `Settings.txt`, every size derives from it
- [x] **Fonts bundled** in `@Resources\Fonts` (Ubuntu Nerd Font + licence)
- [x] Real core frequency (needs UsageMonitor, see below), drive activity on real counters, wifi label quoting, recycle bin auto-empty made opt-in
- [x] **Performance**: measured 1.0 vs 2.0 (README, Performance section). Average CPU went from ~52 % to ~17 % of one core with balanced effects (~5 % with effects off). Changes:
  - Top process every 30 s, with a quick first reading
  - HWiNFO sensors every 2 s (its own refresh rate)
  - Static background bar
  - Uptime every 10 s
- [x] **Cleanup**: removed the weather (`woeid`, `unit`) and media player settings, `Scripts/Smurfier-Media.lua`, the disk RPM / motherboard / voltage sensor variables, `Apparence/temp.txt` and `Templates/memoryTemplate.inc`. Uptime has its own appearance file (`upTime.txt`, an "uptime" tab in the config tool)
- [x] **Peak minimum**: `[mPeakMin]` copies the source for the first 2 updates (Calc's `Counter`), so it starts from a real reading instead of 0
- [x] **HWiNFO sensor picker**: the config tool's **sensors** page lists HWiNFO's sensors by name (`Scripts/Sensors.lua`, Registry `OutputType=ValueList`), writes `ValueN` plus the sensor's name (`<key>Sensor`) to `Settings.txt`, and flags gauges whose sensor is missing (`!`) or moved (`~`, click to re-match)

## 🐛 Known issues

- [ ] **Pump temperature has no sensor**: `pumpTemp=Value18` points at a sensor HWiNFO no longer reports (the sensors page shows it with `!`), and `pumpRpm` reads the same sensor as fan 2. Pick the right ones on the sensors page

- [ ] **UsageMonitor crashes Rainmeter 4.5.28** on this PC. Until a fixed release:
  - CPU top process uses AdvancedCPU (slow: ~20 % of a core at a 3 s interval, now every 30 s)
  - Core gauges show the base clock (PerfMon can't read "Actual Frequency")
  - Drive activity uses PerfMon raw counters
  - The UsageMonitor versions are in comments next to each; switch back and retest once Rainmeter is updated

## ⚖️ Ground rules

- **Don't change the look or the animations without asking.** The current 2.0 look and the balanced effects are the intended design.
- **Don't make the skin drastically heavier.** Measure Rainmeter's CPU/RAM before and after any change and compare with the README's Performance numbers. A costly feature must be optional.

## 🚀 Feature Enhancements

- [ ] **Core gauges for every thread**: there are 4 core skins, the CPU has 16 threads
- [ ] **Configurable warning thresholds**: the 75 % / 90 % levels and their colors as settings
- [ ] **Icon improvements**
  - [ ] Status indicators (e.g., warning icon for high temp)
  - [ ] Better icon visibility (the PNG icons are small for 200 % scale)
- [ ] **Threshold alerts**
  - [ ] Optional sound alerts
  - [ ] Alert history/log

## 🧹 Cleanup

- [ ] Finish templating: memory, wifi, battery, bin, clock, volume still carry their own meters
- [ ] Replace the 2023 `NeoGauge_1.0.rmskin` with a fresh 2.0 package (or build it in a release)

### Rainmeter Documentation
- Official Manual: https://docs.rainmeter.net/manual/
- Bangs Reference: https://docs.rainmeter.net/manual/bangs/
- Measure Types: https://docs.rainmeter.net/manual/measures/
- Meter Types: https://docs.rainmeter.net/manual/meters/

When implementing improvements, refer to:
- [Calc Measures](https://docs.rainmeter.net/manual/measures/calc/)
- [Measure Options](https://docs.rainmeter.net/manual/measures/general-options/)
- [Meter Options](https://docs.rainmeter.net/manual/meters/general-options/)
- [Bangs Reference](https://docs.rainmeter.net/manual/bangs/)
- [ActionTimer plugin](https://docs.rainmeter.net/manual/plugins/actiontimer/)
- [UsageMonitor plugin](https://docs.rainmeter.net/manual/plugins/usagemonitor/)
- [@Include Workshop](https://www.deviantart.com/rainmeter/journal/Rainmeter-Workshop-include-224558279)

---
**Last Updated:** 2026-10-14 (evening)
**Maintainer:** Norbert Ruff
