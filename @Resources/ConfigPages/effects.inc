; ============================================================
; Effects page: ring animation and effects for every gauge
; (fx* variables in @Resources\Settings.txt, used by ringTemplate.inc)
; ============================================================

[Variables]
pageColor=200,140,255,230

[presetHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(20*#s#)
Text=Presets
ToolTipText=Sets all the options below at once

[opt_fxPreset_off]
Meter=String
MeterStyle=sText | sFirst
Text=off
ToolTipText=Rings jump once a second, like the original skin. Lightest.
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('off')"]

[opt_fxPreset_light]
Meter=String
MeterStyle=sText | sNext
Text=light
ToolTipText=Smooth motion only
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('light')"]

[opt_fxPreset_balanced]
Meter=String
MeterStyle=sText | sNext
Text=balanced
ToolTipText=Smooth motion, glow under load, peak hold and afterglow
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('balanced')"]

[opt_fxPreset_everything]
Meter=String
MeterStyle=sText | sNext
Text=everything
ToolTipText=Everything, including the comet arc and round ends. Heaviest.
LeftMouseUpAction=[!CommandMeasure mScript "setFxPreset('everything')"]

[costNote]
Meter=String
MeterStyle=sText | sNote
X=(140*#s#)
Y=(4*#s#)R
W=(420*#s#)
ClipString=2
Text=A gauge only animates while its ring is moving (20 frames a second), then goes idle. Busy gauges such as CPU and network animate most.

; ------------------------------------------------------------

[motionHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(116*#s#)
Text=Motion

[tog_fxSmooth]
Meter=String
MeterStyle=sText | sFirst
Text=smooth
ToolTipText=The ring glides to each new reading instead of jumping
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxSmooth', 'settings')"]

[speedLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=speed

[opt_fxEaseMs_150]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=fast
LeftMouseUpAction=[!WriteKeyValue Variables fxEaseMs 150 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxEaseMs_280]
Meter=String
MeterStyle=sText | sNext
Text=normal
LeftMouseUpAction=[!WriteKeyValue Variables fxEaseMs 280 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxEaseMs_500]
Meter=String
MeterStyle=sText | sNext
Text=slow
LeftMouseUpAction=[!WriteKeyValue Variables fxEaseMs 500 "#@#Settings.txt"][!RefreshGroup rsm]

; ------------------------------------------------------------

[glowHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(172*#s#)
Text=Glow
ToolTipText=A soft halo in the arc's own color

[opt_fxGlow_0]
Meter=String
MeterStyle=sText | sFirst
Text=off
LeftMouseUpAction=[!WriteKeyValue Variables fxGlow 0 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlow_1]
Meter=String
MeterStyle=sText | sNext
Text=always
LeftMouseUpAction=[!WriteKeyValue Variables fxGlow 1 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlow_2]
Meter=String
MeterStyle=sText | sNext
Text=grows with load
ToolTipText=None below 55 %, full at 90 %
LeftMouseUpAction=[!WriteKeyValue Variables fxGlow 2 "#@#Settings.txt"][!RefreshGroup rsm]

[strengthLabel]
Meter=String
MeterStyle=sText | sNext | sNote
FontSize=(10*#s#)
X=(24*#s#)R
Text=strength

[opt_fxGlowStrength_0_4]
Meter=String
MeterStyle=sText | sNext
X=(8*#s#)R
Text=subtle
LeftMouseUpAction=[!WriteKeyValue Variables fxGlowStrength 0.4 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlowStrength_0_6]
Meter=String
MeterStyle=sText | sNext
Text=medium
LeftMouseUpAction=[!WriteKeyValue Variables fxGlowStrength 0.6 "#@#Settings.txt"][!RefreshGroup rsm]

[opt_fxGlowStrength_0_9]
Meter=String
MeterStyle=sText | sNext
Text=strong
LeftMouseUpAction=[!WriteKeyValue Variables fxGlowStrength 0.9 "#@#Settings.txt"][!RefreshGroup rsm]

; ------------------------------------------------------------

[extrasHeader]
Meter=String
MeterStyle=sText | sHeader
Y=(228*#s#)
Text=Extras
ToolTipText=Click to switch each one on or off

[tog_fxPeak]
Meter=String
MeterStyle=sText | sFirst
Text=peak hold
ToolTipText=A tick marks the recent high for 3 s, then slides back
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxPeak', 'settings')"]

[tog_fxAfterglow]
Meter=String
MeterStyle=sText | sNext
Text=afterglow
ToolTipText=When a value drops, the old arc fades out instead of vanishing
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxAfterglow', 'settings')"]

[tog_fxComet]
Meter=String
MeterStyle=sText | sNext
Text=comet
ToolTipText=The arc brightens toward a glowing tip. The heaviest effect.
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxComet', 'settings')"]

[tog_fxRoundCaps]
Meter=String
MeterStyle=sText | sNext
Text=round ends
LeftMouseUpAction=[!CommandMeasure mScript "toggle('fxRoundCaps', 'settings')"]
