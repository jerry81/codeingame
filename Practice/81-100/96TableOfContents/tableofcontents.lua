--[[
Goal
You are writing a book, and the table of contents is the only thing left to do. Sadly, the necessary packages are not working well, so you will have to implement one yourself.

To generate the table of contents, your program will read N entries, describing a section with its level, title and page.
- The level is given by the number of > at the start of the entry.
- The title will not contain any space nor > characters.
- The page is an integer, separated from the title by a space.
Your program will then output the table of contents with the right format, N lines containing :
- An indentation to reflect the level, 4 spaces per level.
- The number of the section
- Its title
- A variable number of dots, for each line to be lengthofline long (including the page number)
- The page number
Input
Line 1 Length of line: lengthofline
Line 2 Number of entries: N
Next N lines Entries in inappropriate format
Output
N lines: Entries, 1 per line, in the good format.
Constraints
1 ≤ N ≤ 30
30 ≤ lengthofline ≤ 50
Example
Input
40
5
Title1 4
>Subtitle1 5
>>Subsubtitle1 5
>Subtitle2 6
Title2 10
Output
1 Title1...............................4
    1 Subtitle1........................5
        1 Subsubtitle1.................5
    2 Subtitle2........................6
2 Title2..............................10
]]--

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.


function countArrows(str)
  count = 0
  for i=1,#str do
    c = string.sub(str,i,i)
    io.stderr:write("c is "..c.."\n")
    if c == '>' then
        count = count+1
    else
        return count
    end
  end
end

function split (inputstr, sep)
    if sep == nil then
       sep = "%s"
    end
    local t={}
    for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
       table.insert(t, str)
    end
    return t
  end

function processstr(str)
    arrows = countArrows(str)
    rest = string.sub(str,arrows+1)
    spl = split(rest," ")
    return {arrows=arrows, title=spl[1], page=spl[2]}
end

function pr(obj)
    io.stderr:write("arrows are : "..obj.arrows.." title is "..obj.title.." and page is "..obj.page.."\n")
end

levels = {}
lengthofline = tonumber(io.read())
N = tonumber(io.read())
for i=0,N-1 do
    entry = io.read()
    obj = processstr(entry)
    levels[obj.arrows] = levels[obj.arrows] and levels[obj.arrows] + 1 or 1
    nextstr = ""
    marker = levels[obj.arrows]
    numspaces = obj.arrows * 4
    numdots = lengthofline-numspaces-#obj.title-3
    spaces = ""
    for j=1,numspaces do
        spaces = spaces.." "
    end
    dots = ""
    for k=1,numdots do
        dots = dots.."."
    end
    print(spaces..marker.." "..obj.title..dots..obj.page)
end

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

-- print("Format error")