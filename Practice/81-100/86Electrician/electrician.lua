--[[
Goal
After working with your apprentice Tom on a very bizarre electrical installation, you are about to turn on the power to carry out the final checks. As a professional, you labelled all switches beforehand and made sure they were off before you disconnected the power supply.

However during the intervention, Tom flipped the switches all over the place! Fortunately, you had asked him to take notes, so you should be able to find out which equipment will trigger when the power supply is turned back on.

Switches can be mounted in series or in parallel. For a circuit to be on, all switches in series must be on and at least one switch for each parallel derivation must be on.

Wiring description is a space-delimited sequence of:
• the - character followed by the identifiers of the switches mounted in series
• the = character followed by the identifiers of the switches mounted in parallel
Each SWITCH has a unique label.

Eg. for the following circuit:


                      +-[A1]-+        +-[A4]--[RADIO]---+
                      |      |        |                 |
                      |      +--[A3]--+----------[TV]---+
                   +--+      |        |                 |
                   |  |      |        +-----[CONSOLE]---+
                   |  |      |                          |
                   |  +-[A2]-+                          |
                   |                                    |
                   +------------[POWER SUPPLY]----------+
                   |                                    |
                   +--[B1]--[B2]-------------[LIGHTS]---+


The wiring description is:

    TV = A1 A2 - A3
    RADIO = A1 A2 - A3 A4
    CONSOLE = A1 A2 - A3
    LIGHTS - B1 B2
Input
First line: the number of circuits C
Next C lines: name of the EQUIPMENT and wiring description
Next line: the number of Tom's actions A
Next A lines: the SWITCH that Tom toggled
Output
C lines, one for each equipment in the same order.
Each line should read EQUIPMENT is ON or EQUIPMENT is OFF
Constraints
1 ≤ C ≤ 25
0 ≤ A ≤ 25
Length of SWITCH ≤ 20
Length of EQUIPMENT ≤ 40
Max input line length = 1024
Example
Input
1
LIGHT - A1
1
A1
Output
LIGHT is ON
]]--
-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.
function mysplit (inputstr, sep)
  if sep == nil then
     sep = "%s"
  end
  local t={}
  for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
     table.insert(t, str)
  end
  return t
end

tokens_list = {}
devices = {}
switches = {}

function p()
  for i,v in pairs(devices) do
    io.stderr:write("iterating devices i is \n")
    io.stderr:write(i)
    io.stderr:write("\n")
    for _,vv in pairs(v.parallel) do
      io.stderr:write("new parallel circuit")
      io.stderr:write("\n")
      for _,vvv in pairs(vv) do
        io.stderr:write("parallel is\n")
        io.stderr:write(vvv)
        io.stderr:write("\n")
      end
    end
    for _,vv in pairs(v.series) do
      io.stderr:write("new series circuit")
      io.stderr:write("\n")
      for _,vvv in pairs(vv) do
        io.stderr:write("series is\n")
        io.stderr:write(vvv)
        io.stderr:write("\n")
      end
    end
  end

  for i,v in pairs(switches) do
    io.stderr:write("switch i is \n")
    io.stderr:write(i)
    io.stderr:write("\n")
    io.stderr:write("status is \n")
    io.stderr:write(tostring(v))
    io.stderr:write("\n")
  end
end

C = tonumber(io.read())
for i=0,C-1 do
    WIRING = io.read()
    tokens = mysplit(WIRING)
    for i,v in ipairs(tokens) do
      tokens_list[i] = tostring(v)
    end
    curDevice = ""
    curType = ""
    for i,v in ipairs(tokens_list) do
      if (i == 1) then
        curDevice = v
        devices[v] = {series={}, parallel={}}
        cd = devices[curDevice]
      elseif v == "-" then
        curType = "series"
        table.insert(cd[curType],{})
      elseif v == "=" then
        curType = "parallel"
        table.insert(cd[curType],{})
      else
        switches[v] = false
        table.insert(cd[curType][#cd[curType]], v)
      end
    end
end

A = tonumber(io.read())
for i=0,A-1 do
    SWITCH = io.read()
    switches[SWITCH] = not switches[SWITCH]
end
p()

function is_parallel_on(parallel_t)
  for _,v in pairs(parallel_t) do
    if switches[v] then
      return true
    end
  end
  return false
end

function is_series_on(series_t)
  for _,v in pairs(series_t) do
    if switches[v] then
      return false
    end
  end
  return true
end

for i,v in pairs(devices) do
  device_on = "ON"
  for _,vv in pairs(v.series) do
    series_on = is_series_on(v)
    if not series_on then device_on = "OFF" end
  end
  for _,vv in pairs(v.parallel) do
    parallel_on = is_parallel_on(vv)
    if not parallel_on then device_on = "OFF" end
  end
  print(i.." is "..device_on)
end

--[[
TODO: there may be multiple seperate parallel
 and multiple seperate series
]]--