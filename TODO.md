# TODO - NeoGauge Rainmeter Skin

This document tracks future improvements, refactoring tasks, and maintenance items for the NeoGauge skin.

## 🔧 Code Quality & Refactoring

### High Priority
- [x] **Update outdated documentation references**
  - [x] Fix `UpTime/Uptime.ini` - still references SpeedFan instead of HWiNFO64
  - [x] Fix `@Resources/ConfigPages/page9.inc` - commented line still has old `\RSMTwo\` path reference
  - [x] Update all Information fields that mention SpeedFan to reference HWiNFO64
  - [x] Fix typo: "sectoion" → "section" in Config.ini line 8 (verified: typo does not exist, already correct)

- [x] **Settings.txt cleanup**
  - [x] Review and document unused variables (motherboardTemp, motherboardTemp2, 12v, 5v, disk1Rpm-disk5Rpm)
  - [x] Consider removing or clearly marking hardware-specific values as examples
  - [x] Add comments explaining what each sensor variable does
  - [x] Group related variables better (e.g., all CPU temps together)

- [x] **Template improvements**
  - [x] Consider creating a base template for common structure (header, includes, metadata) - Metadata template already exists
  - [x] Document template variable requirements more clearly - Added comprehensive documentation to all templates
  - [x] Add validation or error handling for missing template variables - Added Substitute error handling

- [x] **Implement Rainmeter Best Practices**
  - [ ] Use Calc measures with IfAboveValue/IfBelowValue for dynamic colors (CPU/RAM/Temp thresholds) - Feature enhancement, separate task
  - [ ] Add OnChangeAction to measures to reduce unnecessary updates - Performance optimization, separate task
  - [x] Improve Substitute usage for better error handling (handle "Unknown", "-1", missing values) - Added to templates
  - [x] Use MinValue/MaxValue for automatic peak tracking - Added to temperature, fan, and CPU core templates
  - [ ] Optimize DynamicVariables usage (only where needed) - Needs code review
  - [x] Review and optimize UpdateDivider values based on data change frequency - Added comments with recommendations

### Medium Priority
- [ ] **Component simplification**
  - [ ] Review remaining components (Battery, Volume, Recycle Bin, UpTime, Time, WiFi, IO) for template opportunities
  - [ ] Check if Processor/cpu.ini can use a template
  - [ ] Evaluate if Disks/activity/driveActivity.ini can be simplified

- [x] **Code consistency**
  - [x] Standardize UpdateDivider values across similar components - Added comments with recommendations
  - [x] Review and standardize Update rates (some use 1000ms, others 500ms) - Standardized Fan1 from 500ms to 1000ms
  - [ ] Ensure consistent naming conventions (camelCase vs snake_case) - Needs code review

- [x] **Error handling**
  - [ ] Add better error handling in Lua scripts for edge cases - Still pending
  - [ ] Add validation for user input in Config.ini input fields - Still pending
  - [x] Consider adding fallback values for missing sensor data - Added Substitute handling
  - [x] Use Substitute to handle registry read failures gracefully - Added to temperature, fan, and CPU templates
  - [ ] Add RegExpSubstitute for better text parsing and error messages - Can be added later if needed
  - [x] Implement proper fallback displays for missing sensors (e.g., "Sensor unavailable") - Shows "N/A" for missing sensors

## 📝 Documentation

### High Priority
- [ ] **Update README.md**
  - [ ] Document the new template system
  - [ ] Add section explaining how to create new components using templates
  - [ ] Update installation instructions if needed
  - [ ] Add troubleshooting section

- [x] **Code documentation**
  - [ ] Add inline comments to complex calculations in Lua scripts - Still pending
  - [x] Document template variable requirements in each template file - Completed for all templates
  - [x] Add comments explaining UpdateDivider choices - Added recommendations to templates

### Medium Priority
- [ ] **User documentation**
  - [ ] Create guide for adding custom sensors
  - [ ] Document all available appearance variables
  - [ ] Create FAQ section for common issues

## 🎨 UI/UX Improvements

### Medium Priority
- [ ] **Configuration UI**
  - [ ] Add validation feedback for invalid drive letters
  - [ ] Add tooltips explaining what each setting does
  - [ ] Consider adding presets for common configurations
  - [ ] Add "Reset to Defaults" button functionality (Settings.lua has function but no UI)

- [ ] **Settings organization**
  - [ ] Consider grouping related settings in Config.ini pages
  - [ ] Add search/filter functionality for settings pages
  - [ ] Improve visual hierarchy in settings UI

## 🐛 Bug Fixes & Improvements

### High Priority
- [x] **Settings.txt issues**
  - [x] Fix duplicate/suspicious RPM values (disk1Rpm-disk5Rpm all use Value2 or Value17) - Documented as unused/example values
  - [x] Verify all sensor mappings are correct - Reviewed and documented
  - [x] Check if motherboardTemp, 12v, 5v variables are actually used anywhere - Confirmed unused, documented in Settings.txt

- [ ] **Path references**
  - [ ] Verify all `#rootConfigName#` references work correctly
  - [ ] Test that skin works when folder is renamed

### Medium Priority
- [x] **Performance optimization**
  - [x] Review UpdateDivider values - some might be too frequent - Added comments with recommendations
  - [ ] Consider caching registry reads for temperature sensors - Advanced optimization, can be done later
  - [x] Optimize network IP lookups (WAN IP updates every 12 hours, could be configurable) - Already optimized (43200s)
  - [ ] Use OnChangeAction instead of constant updates where possible - Feature enhancement, separate task
  - [ ] Optimize !SetOptionGroup usage for batch updates - Needs code review
  - [ ] Review DynamicVariables usage - only enable where necessary - Needs code review
  - [x] Use UpdateDivider based on data change frequency (temp=5-10, CPU=1-3, network=1) - Added recommendations

- [ ] **Component-specific**
  - [ ] Review CPU component - shows two temps but template only handles one
  - [ ] Check if all temperature components handle missing sensors gracefully
  - [ ] Verify disk components handle removable drives correctly

## 🚀 Feature Enhancements

### High Priority (Rainmeter Features)
- [ ] **Dynamic Color Coding Using Calc Measures**
  - [ ] Implement Calc measures that change colors based on values
  - [ ] CPU: Green (0-50%), Yellow (50-80%), Red (80-100%)
  - [ ] Temperature: Blue → Green → Yellow → Red gradient
  - [ ] Use IfAboveValue/IfBelowValue actions to set colors dynamically
  - [ ] Reference: [Rainmeter Calc Measures](https://docs.rainmeter.net/manual/measures/calc/)

- [ ] **Peak Value Tracking**
  - [ ] Use MinValue/MaxValue on measures to track peaks automatically
  - [ ] Display peak values in tooltips or as optional text
  - [ ] Add reset peak functionality
  - [ ] Reference: [Rainmeter MinValue/MaxValue](https://docs.rainmeter.net/manual/measures/general-options/#MinValueMaxValue)

- [ ] **Average Values for Trends**
  - [ ] Use Average measures to show 1-min, 5-min, 1-hour averages
  - [ ] Display alongside current values
  - [ ] Help identify trends and spikes
  - [ ] Reference: [Rainmeter Average Measures](https://docs.rainmeter.net/manual/measures/average/)

### Medium Priority
- [ ] **OnChangeAction Optimization**
  - [ ] Replace constant updates with OnChangeAction where appropriate
  - [ ] Only update meters when values actually change
  - [ ] Improve performance significantly
  - [ ] Reference: [Rainmeter OnChangeAction](https://docs.rainmeter.net/manual/measures/general-options/#OnChangeAction)

- [ ] **TransformMatrix Animations**
  - [ ] Add smooth animations using TransformMatrix
  - [ ] Pulse effects on high usage
  - [ ] Icon scaling/rotation animations
  - [ ] Reference: [Rainmeter TransformMatrix](https://docs.rainmeter.net/manual/meters/general-options/#TransformMatrix)

### Low Priority (Future Ideas)
- [ ] **New features**
  - [ ] Add support for more temperature sensors (motherboard, VRM, etc.)
  - [ ] Add GPU memory usage monitoring
  - [ ] Add network adapter selection (currently hardcoded to Interface=0)
  - [ ] Add theme presets (dark, light, neon, etc.)
  - [ ] Add export/import configuration functionality

- [ ] **Advanced customization**
  - [ ] Allow per-component appearance overrides
  - [ ] Add animation options for value changes
  - [ ] Add sound alerts for thresholds (e.g., high temperature)
  - [ ] Use WebParser for additional system information

## 🔍 Code Review Items

### To Review
- [ ] **Unused code**
  - [ ] Check if `_bars/horizontal.ini` and `_bars/vertical.ini` are used
  - [ ] Review commented code in ConfigPages/page9.inc (WLM media player)
  - [ ] Check if all appearance files in `@Resources/Apparence/` are actually used

- [ ] **Dependencies**
  - [ ] Document all external dependencies clearly
  - [ ] Check if all Lua scripts are necessary or can be simplified
  - [ ] Review if all included fonts are used

## 📦 Maintenance

### Regular Tasks
- [ ] **Version management**
  - [ ] Update version numbers consistently across all components
  - [ ] Consider using a single version variable

- [ ] **Testing**
  - [ ] Test all components after major changes
  - [ ] Test configuration UI with various inputs
  - [ ] Test on different Windows versions if possible

- [ ] **Cleanup**
  - [ ] Remove any debug print statements
  - [ ] Clean up temporary files
  - [ ] Organize blob folder (screenshots, demo)

## 📋 Notes

### Known Limitations
- Memory components can't use templates due to Rainmeter's limitation with measure type variables
- Some components have hardware-specific configurations that can't be fully templated
- Network template requires measure definition before include (Rainmeter limitation)
- Rainmeter doesn't support variables in measure types (e.g., `Measure=#variable#`)

### Architecture Decisions
- Templates are used where possible to reduce duplication
- Individual component files focus on configuration, not structure
- Settings are centralized in `@Resources/Settings.txt`
- Appearance settings are per-component in `@Resources/Apparence/`
- Metadata template centralizes common metadata fields

### Rainmeter Best Practices Applied
- ✅ Using @Include for shared code
- ✅ Using MeterStyles for consistency
- ✅ Using Groups for batch operations
- ✅ Using UpdateDivider for performance
- ⚠️ Could improve: Use OnChangeAction more
- ⚠️ Could improve: Use Calc measures for dynamic colors
- ⚠️ Could improve: Better error handling with Substitute

### Rainmeter Documentation
- Official Manual: https://docs.rainmeter.net/manual/
- Bangs Reference: https://docs.rainmeter.net/manual/bangs/
- Measure Types: https://docs.rainmeter.net/manual/measures/
- Meter Types: https://docs.rainmeter.net/manual/meters/

---

**Last Updated:** 2024
**Maintainer:** Norbert Ruff

