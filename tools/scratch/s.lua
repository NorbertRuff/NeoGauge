function Update()
  for _, n in ipairs({'mA','mB','mC'}) do
    local m = SKIN:GetMeasure(n)
    SKIN:Bang('!SetVariable', 's' .. n, '<' .. m:GetStringValue() .. '>' .. tostring(#m:GetStringValue()))
  end
  return 0
end
