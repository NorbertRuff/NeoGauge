# TODO - NeoGauge Rainmeter Skin

This document tracks future improvements, refactoring tasks, and maintenance items for the NeoGauge skin.

## 🚀 Feature Enhancements

### High Priority (Rainmeter Features)
- [x] **Dynamic Color Coding Using Calc Measures**
  - [x] Implement Calc measures that change colors based on values
  - [x] All components: Original color (< 75%), Yellow (75-90%), Red (> 90%)
  - [x] Applies to: CPU, Cores, Temperature, Memory, Disk, Fan, Network
  - [x] **Disk color coding** - Fixed by calculating percentage from bytes: (UsedBytes/TotalBytes)*100
  - [x] Use IfCondition with IfConditionMode=1 to set colors dynamically
  - [x] Reference: [Rainmeter Calc Measures](https://docs.rainmeter.net/manual/measures/calc/)

- [x] **Peak Value Tracking**
  - [x] Use MinValue/MaxValue on measures to track peaks automatically
  - [x] Display peak values in tooltips or as optional text
  - [x] Add reset peak functionality (right-click to reset)
  - [x] Reference: [Rainmeter MinValue/MaxValue](https://docs.rainmeter.net/manual/measures/general-options/#MinValueMaxValue)

- [ ] **TransformMatrix Animations**
  - [ ] Add smooth animations using TransformMatrix
  - [ ] Pulse effects on high usage
  - [ ] Icon scaling/rotation animations
  - [ ] Reference: [Rainmeter TransformMatrix](https://docs.rainmeter.net/manual/meters/general-options/#TransformMatrix)

- [ ] **Icon Improvements**
  - [ ] Animated icons for active components
  - [ ] Status indicators (e.g., warning icon for high temp)
  - [ ] Better icon visibility with subtle glow effects

- [ ] **Threshold Alerts**
  - [ ] Visual alerts (color change, pulse) when thresholds exceeded
  - [ ] Optional sound alerts
  - [ ] Configurable thresholds per component
  - [ ] Alert history/log

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
- [@Include Workshop](https://www.deviantart.com/rainmeter/journal/Rainmeter-Workshop-include-224558279)

---
**Last Updated:** 2025-12-26
**Maintainer:** Norbert Ruff