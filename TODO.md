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

## 🐛 Known issues

- [ ] **Peak minimum starts at 0**: in `peakTemplate.inc`, `[mPeakMin]` needs a way to take the first real sample (the `TODO` there); until then the tooltip's minimum reads 0 until a right-click reset
- [ ] **UsageMonitor crashes Rainmeter 4.5.28** on this PC. Until a fixed release:
  - CPU top process uses AdvancedCPU (slow: ~20 % of a core at a 3 s interval, now every 10 s)
  - Core gauges show the base clock (PerfMon can't read "Actual Frequency")
  - Drive activity uses PerfMon raw counters
  - The UsageMonitor versions are in comments next to each; switch back and retest once Rainmeter is updated

## 🚀 Feature Enhancements

- [ ] **HWiNFO sensor picker**: a config page that lists the sensors by label (Registry measure `OutputType`, Rainmeter 4.5.10+) instead of typing `ValueN`, so gauges survive HWiNFO reordering its sensors
- [ ] **Core gauges for every thread**: there are 4 core skins, the CPU has 16 threads
- [ ] **Configurable warning thresholds**: the 75 % / 90 % levels and their colors as settings
- [ ] **Icon improvements**
  - [ ] Status indicators (e.g., warning icon for high temp)
  - [ ] Better icon visibility (the PNG icons are small for 200 % scale)
- [ ] **Threshold alerts**
  - [ ] Optional sound alerts
  - [ ] Alert history/log

## 🧹 Cleanup

- [ ] Remove settings with no skin behind them: `woeid`, `unit` (weather, Yahoo's API is gone), `mediaPlayer` and `Scripts/Smurfier-Media.lua` (no NowPlaying skin), unused sensor variables in `Settings.txt`
- [ ] Remove unused files: `Apparence/temp.txt`, `Apparence/upTime.txt`, `Templates/memoryTemplate.inc` (RAM/swap don't use it)
- [ ] Uptime gauge: no ring, borrows the download appearance; give it its own
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
**Last Updated:** 2026-10-14
**Maintainer:** Norbert Ruff
