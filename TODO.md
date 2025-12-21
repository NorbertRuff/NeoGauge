# TODO - NeoGauge Rainmeter Skin

This document tracks future improvements, refactoring tasks, and maintenance items for the NeoGauge skin.

## 🔧 Code Quality & Refactoring

### High Priority
- [ ] **Update outdated documentation references**
  - [ ] Fix `UpTime/Uptime.ini` - still references SpeedFan instead of HWiNFO64
  - [ ] Fix `@Resources/ConfigPages/page9.inc` - commented line still has old `\RSMTwo\` path reference
  - [ ] Update all Information fields that mention SpeedFan to reference HWiNFO64

- [ ] **Settings.txt cleanup**
  - [ ] Review and document unused variables (motherboardTemp, motherboardTemp2, 12v, 5v, disk1Rpm-disk5Rpm)
  - [ ] Consider removing or clearly marking hardware-specific values as examples
  - [ ] Add comments explaining what each sensor variable does
  - [ ] Group related variables better (e.g., all CPU temps together)

- [ ] **Template improvements**
  - [ ] Consider creating a base template for common structure (header, includes, metadata)
  - [ ] Document template variable requirements more clearly
  - [ ] Add validation or error handling for missing template variables

### Medium Priority
- [ ] **Component simplification**
  - [ ] Review remaining components (Battery, Volume, Recycle Bin, UpTime, Time, WiFi, IO) for template opportunities
  - [ ] Check if Processor/cpu.ini can use a template
  - [ ] Evaluate if Disks/activity/driveActivity.ini can be simplified

- [ ] **Code consistency**
  - [ ] Standardize UpdateDivider values across similar components
  - [ ] Review and standardize Update rates (some use 1000ms, others 500ms)
  - [ ] Ensure consistent naming conventions (camelCase vs snake_case)

- [ ] **Error handling**
  - [ ] Add better error handling in Lua scripts for edge cases
  - [ ] Add validation for user input in Config.ini input fields
  - [ ] Consider adding fallback values for missing sensor data

## 📝 Documentation

### High Priority
- [ ] **Update README.md**
  - [ ] Document the new template system
  - [ ] Add section explaining how to create new components using templates
  - [ ] Update installation instructions if needed
  - [ ] Add troubleshooting section

- [ ] **Code documentation**
  - [ ] Add inline comments to complex calculations in Lua scripts
  - [ ] Document template variable requirements in each template file
  - [ ] Add comments explaining UpdateDivider choices

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
- [ ] **Settings.txt issues**
  - [ ] Fix duplicate/suspicious RPM values (disk1Rpm-disk5Rpm all use Value2 or Value17)
  - [ ] Verify all sensor mappings are correct
  - [ ] Check if motherboardTemp, 12v, 5v variables are actually used anywhere

- [ ] **Path references**
  - [ ] Verify all `#rootConfigName#` references work correctly
  - [ ] Test that skin works when folder is renamed

### Medium Priority
- [ ] **Performance optimization**
  - [ ] Review UpdateDivider values - some might be too frequent
  - [ ] Consider caching registry reads for temperature sensors
  - [ ] Optimize network IP lookups (WAN IP updates every 12 hours, could be configurable)

- [ ] **Component-specific**
  - [ ] Review CPU component - shows two temps but template only handles one
  - [ ] Check if all temperature components handle missing sensors gracefully
  - [ ] Verify disk components handle removable drives correctly

## 🚀 Feature Enhancements

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

### Architecture Decisions
- Templates are used where possible to reduce duplication
- Individual component files focus on configuration, not structure
- Settings are centralized in `@Resources/Settings.txt`
- Appearance settings are per-component in `@Resources/Apparence/`

---

**Last Updated:** 2024
**Maintainer:** Norbert Ruff

