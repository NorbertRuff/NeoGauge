# TODO - NeoGauge

The backlog: what's next, ideas for later, and what 2.0 finished. Each item has its size (S/M/L) and its expected cost against the README's Performance numbers. "~0" means no new redraws.

## ⚖️ Ground rules

- **Don't change the look or the animations without asking.** The current 2.0 look and the balanced effects are the intended design. Visual ideas below are opt-in and off by default.
- **Don't make the skin drastically heavier.** Measure Rainmeter's CPU/RAM before and after any change and compare with the README's Performance numbers. A costly feature must be optional.

## 🐛 Known issues

- [ ] **Pump has no coolant temperature**: `pumpTemp=Value18` points at a sensor HWiNFO no longer reports (`!` on the sensors page). The H100i pump's RPM is the board's CPU fan header (`pumpRpm=Value7`, which Fan 1 reads too). For coolant temperature, HWiNFO has to read the H100i over USB (iCUE may block it); otherwise the Pump gauge stays unloaded
- [ ] **UsageMonitor crashes Rainmeter 4.5.28** on this PC. Until a fixed release:
  - CPU top process uses AdvancedCPU, every 30 s (~20 % of a core at 3 s)
  - Core gauges show the base clock (PerfMon can't read "Actual Frequency")
  - Drive activity uses PerfMon raw counters

  The UsageMonitor versions are in comments next to each; retest after every Rainmeter update.
- [ ] **Removable drives may show "(removed)"** (unverified): `diskTemplate.inc` `[mDiskType]` matches both its IfBelow and IfAbove for Type 2

## 🎯 Next

- [ ] **°F temperatures** (S, ~0): the temp ring and its levels assume °C (full at 100). Add `tempMax` and a unit for HWiNFO set to °F
- [ ] **More from HWiNFO** (M, ~0): the live CPU clock (fixes the base-clock issue without UsageMonitor), plus GPU load, CPU/GPU power and VRAM, through one generic sensor template. Each sensor has to be ticked in HWiNFO first
- [ ] **Icons** (S, ~0)
  - [x] Disk and download/upload icons are picked on the appearance page: classic plus 4 disk and 5 arrow styles at 96 px, in `@Resources\Icons` (licences in `credits.txt`). Default stays classic
  - [ ] Make the other icons sharp: the 32 px PNGs are drawn at 48 px at 200 %, so re-export them at 96 px
  - [ ] Optional: the icon tint follows the warning colour
- [ ] **Publish 2.0** (S): test-install `dist\NeoGauge_2.0.rmskin` on a clean Windows (Sandbox), merge PR #1, tag `v2.0`, attach the package to the GitHub release, remove `NeoGauge_1.0.rmskin` from the repo

## 💡 Later: visual ideas (opt-in, off by default)

- [ ] **Smooth warning colour** (S, ~0): the arc blends gradually from its colour to yellow to red instead of jumping
- [ ] **Dial ticks and warning zones** (S, static): fine ticks every 10 % on the track, and the warning stretch faintly tinted
- [ ] **Min/max range band** (S, 1 Hz): a faint band on the track from the session low to the session high, reset with the peaks
- [ ] **Global themes** (S–M, 0): one click recolours every gauge group, including a "Windows accent" theme
- [ ] **Start-up sweep** (S–M, one-off): the rings sweep to 100 % and settle when Rainmeter starts
- [ ] Smaller ones:
  - Second thin inner arc (e.g. CPU package temp, upload inside download)
  - Clock as a real dial
  - Critical pulse (a few beats, then stop)
  - Text shadow or a dark backdrop disc for busy wallpapers
  - Hover highlight
  - Needle style
  - Night dim
  - Counting numbers (measure first: text redraws every frame)
  - History dots around the edge (heaviest; measure first)

## 💡 Later: other features

- [ ] **Ping gauge** (S–M, ~0): latency against a max, with the built-in PingPlugin every 5–10 s
- [ ] **Network adapter and daily traffic** (S, ~0): `Interface=0` sums every adapter, so VPN or Hyper-V traffic can count twice. Add an adapter setting, and today's total in the tooltip
- [ ] **Sustained alert sound** (S–M, ~0): play once when a gauge stays in the red for N seconds, then cool down
- [ ] **Average in the peak tooltip** (S, ~0): about a 1-minute average next to Min/Max
- [ ] **Gauge manager** (M, 0): load/unload gauges, lock positions and click-through, from the config tool
- [ ] **Per-drive read/write** in each disk's tooltip (M, small): probe the Hungarian counter names first

## 🧹 Cleanup

- [ ] **Stale text**:
  - Skin `Information=` strings still say "Settings.ini skin" and "Shared Memory support" (it's Gadget reporting)
  - `Config.ini` info line doesn't mention the effects page
- [ ] **Small fixes**:
  - `[mCoreFreqRaw]` gets `UpdateDivider=-1` (the base clock never changes)
  - `upload.ini` `SysInfoData=0` becomes `Best` (silences a log note)
- [ ] **Unused**:
  - `@Resources/Images/` (old media-player icons, CC BY-ND)
  - the `[pieCommon]` style
  - the unread `Settings.txt` variables (`dimm2-4*`, `disk2-5*`, `cpuTemp2Label`) and `memoryUpdateDivider`; ask before removing, they're personal
- [ ] **Templating**: `ram.ini` and `swap.ini` are near-copies, worth a memory template. Wifi, bin, clock, volume, uptime, drive activity and battery are one-offs; template them only when touched

## 🚫 Not doing

- **Game mode**: not wanted
- **Alert history log**
- **Segmented "LED" ring** (needs 20+ meters per frame)
- **Real blur glow** (Rainmeter has none)
- **GPU load via PerfMon** (no `_Total`; use HWiNFO)
- **Per-process RAM lists** (AdvancedCPU-class cost)

## ✅ Done (2.0)

- **Ring effects** (`Templates/ringTemplate.inc`): easing, glow, peak-hold tick, afterglow, comet, round ends. Global, set on the config tool's effects page; frames only run while a ring moves
- **Warning colours**: yellow from 75 %, red from 90 % by default, part of the shared ring and the threads grid; levels and colours set on the effects page (`warnLevel` / `alertLevel` / `warnColor` / `alertColor`); `fxLevels=0` turns them off. Temperatures and fans have their own levels in their own unit (`chipTemp*`, `ramTemp*`, `driveTemp*`, `coolantTemp*`, `fan*`)
- **Peak tracking** (`Templates/peakTemplate.inc`): real highs and lows, right-click resets; the minimum starts from a real reading
- **Config tool rebuilt**: info, appearance, effects, system, sensors and time pages; everything scales with the display
- **HWiNFO sensor picker**: the sensors page picks sensors by name and flags missing (`!`) or moved (`~`) ones
- **Easier HWiNFO setup**: auto-assign by name (`AUTO` in `Sensors.lua`; working gauges are kept), a Setup checklist (HWiNFO running, sensors reported, gauges with a sensor), gauges without a sensor say so and open the sensors page on click (`noSensorTemplate.inc`), and a `reg export` backup tip in the README
- **2.0 release package**: `tools\Package.ps1` builds the `.rmskin` (Settings.txt and the appearance files are kept on update; `radius` moved to Settings.txt so 1.0's fixed values can't come back), the config window state moved to the untracked `ConfigState.inc`, every skin is version 2.0, and the README install step points at the GitHub release
- **CPU threads grid** (`Processor\threads`): every thread (up to 16) as small rings with the warning colours; layout and size on the appearance page's threads tab. ~2 MB RAM, no measurable CPU
- **High-DPI support** (`scale` in `Settings.txt`) and the bundled Ubuntu Nerd Font
- **Performance**: ~52 % → ~17 % of a core with balanced effects (~5 % with effects off). Top process every 30 s, HWiNFO every 2 s, static bar, uptime every 10 s. Details in the README
- **Fixes and cleanup**: drive activity on real counters, wifi label quoting, recycle-bin auto-empty made opt-in; removed the weather, media player, unused sensor variables and dead templates; uptime got its own appearance file

---
Rainmeter docs: [manual](https://docs.rainmeter.net/manual/) · [bangs](https://docs.rainmeter.net/manual/bangs/) · [ActionTimer](https://docs.rainmeter.net/manual/plugins/actiontimer/) · [UsageMonitor](https://docs.rainmeter.net/manual/plugins/usagemonitor/) · [@include workshop](https://www.deviantart.com/rainmeter/journal/Rainmeter-Workshop-include-224558279)
