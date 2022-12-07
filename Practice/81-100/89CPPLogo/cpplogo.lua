--[[

	Goal
Legend has it that the origin of the name "C#" was really just two "++" stacked on top of each other, like this
++
++
...and that formed a "sharp" (musical note symbol). Cool, right?

C-Enterprises is considering releasing yet another programming language and their Marketing Department is in need of a logo for it that will play off that history, so it too will consist solely of plus-signs. They have asked you to do some rough drafts for them.

Here is what they know they want:
~ They want just the outline of plus-signs
~ The outline itself will be done in plus-signs characters (+)
~ When 2 plus-signs touch each other, the outlines separating the touching parts should disappear, so that it all "flows together"

They have not decided the following so these will be inputs in the various cases:
~ The size of the plus-signs
~ The thickness of the two-lines that form each plus-sign
~ The number and arrangement of the plus-signs

(You explain you are a programmer -- not a graphic artist -- but alas they insist. So you just do your best, knowing the console application output will make the proportions appear a bit elongated.)
Input
Line 1: An integer size (both the height and width) of a single plus-sign outline
Line 2: An integer thickness of the two lines of the plus-sign
Line 3: An integer N for the number of rows in the proposed logo
Next N lines: a string that constitutes a row of that logo
Output
Draw the logo
(Trim off any white space to the right on each line)
Constraints
If size is even, thickness is even
If size is odd, thickness is odd

size ≥ 5
thickness ≥ 3
thickness < size
Example
Input
13
5
2
+++
++
Output
    +++++        +++++        +++++
    +   +        +   +        +   +
    +   +        +   +        +   +
    +   +        +   +        +   +
+++++   ++++++++++   ++++++++++   +++++
+                                     +
+                                     +
+                                     +
+++++   ++++++++++   ++++++++++   +++++
    +   +        +   +        +   +
    +   +        +   +        +   +
    +   +        +   +        +   +
    +   +        +   +        +++++
    +   +        +   +
    +   +        +   +
    +   +        +   +
    +   +        +   +
+++++   ++++++++++   +++++
+                        +
+                        +
+                        +
+++++   ++++++++++   +++++
    +   +        +   +
    +   +        +   +
    +   +        +   +
    +++++        +++++

]]--

size = tonumber(io.read())
thickness = tonumber(io.read())
N = tonumber(io.read())
ref = {}
maxw = 0
for i=0,N-1 do
    logoLine = io.read()
    table.insert(ref, logoLine)
    if #logoLine > maxw then
        maxw = #logoLine
    end
end

rem = size - thickness
hrem = rem / 2

function stri(str,i)
    return string.sub(str,i,i)
end
tdarr = {}
function init(height,width)
    for i=1,height do
        table.insert(tdarr,{})
        for j=1,width do
            table.insert(tdarr[i]," ")
        end
    end
end

init(size * N, size * maxw)

function paintAt(y,x)
    starty = 1 + (y-1)*size
    startx = 1 + (x-1)*size
    left = startx + hrem
    right = left + thickness - 1
    top = starty + hrem
    bottom = top + thickness - 1
    for i=left, right do
        tdarr[starty][i] = "+"
    end
    for i=starty, top do
        tdarr[i][left] = "+"
        tdarr[i][right] = "+"
    end
    for i=startx, left do
        tdarr[top][i] = "+"
    end
    for i=right, startx+size-1 do
        tdarr[top][i] = "+"
    end
    for i=top, bottom do
        tdarr[i][startx] = "+"
        tdarr[i][startx+size-1] = "+"
    end
    for i=startx, left do
        tdarr[bottom][i] = "+"
    end
    for i=right, startx+size-1 do
        tdarr[bottom][i] = "+"
    end
    for i=bottom, starty+size-1 do
        tdarr[i][left] = "+"
        tdarr[i][right] = "+"
    end
    for i=left, right do
        tdarr[starty+size-1][i] = "+"
    end
end

function remove_border(x1,x2,y1,y2)
    starty = 1 + (y1-1)*size
    startx = 1 + (x1-1)*size
    if x1==x2 then
        for i = starty-1, starty do
            for j=startx+hrem+1, startx+hrem+thickness-2 do
                tdarr[i][j] = " "
            end
        end

    else
        for i=startx-1, startx do
          for j=starty+hrem+1, starty+hrem+thickness-2 do
              tdarr[j][i] = " "
          end
        end
    end
end

for i,v in ipairs(ref) do
  for j=1,#v do
    if stri(v,j) == '+' then
        paintAt(i,j)
    end
  end
end

function trim(line)
    for i=#line,1,-1 do
        if stri(line,i) ~= " " then
            return string.sub(line,0,i)
        end
    end
    return ""
end



for i,v in ipairs(ref) do
    for j=1,#v do -- remove horizontal borders
        if j > 1 and stri(v,j) == '+' and stri(v,j-1) == '+' then
          remove_border(j, j-1, i, i)
        end
    end
end
for i=1,maxw do
    for j=1,N do
        if j > 1 and stri(ref[j],i) == '+' and stri(ref[j-1],i) == '+' then
            remove_border(i,i,j, j-1)
        end
    end
end

for i,v in ipairs(tdarr) do
res = table.concat(v, "")
print(trim(res))

end