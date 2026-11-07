function Update()
  local m = SKIN:GetMeter('mainText')
  if m then SKIN:Bang('!SetVariable', 'optClick', m:GetOption('LeftMouseUpAction', '?')) end
  SKIN:Bang('!SetVariable', 'subNow', SKIN:GetMeter('subText'):GetOption('Text', '?'))
  SKIN:Bang('!SetVariable', 'mainNow', SKIN:GetMeter('mainText'):GetOption('Text', '?'))
  return 0
end
