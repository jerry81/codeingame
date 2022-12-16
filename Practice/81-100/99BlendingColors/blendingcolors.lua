--[[

Goal
Designers are placing shapes of different sizes and colors on the canvas of an image editor.

About Colors
The shapes have primary colors defined in RGB color notations. Red is (255, 0, 0); Green is (0, 255, 0); Blue is (0, 0, 255). Besides these, they also use Yellow (255, 255, 0), Cyan (0, 255, 255) and Magenta (255, 0, 255).
All shapes have a very thin black border (0, 0, 0) and are on a white background (255, 255, 255).

The shapes are defined as transparent so that when one shape is overlaying another, their colors will mix to reveal a new color. When two or more colors blend together, the new color is the average of all layer's colors.

For example, when R and G blend, the mixed color is (128, 128, 0). When Y, M and G mix, the result will be ((255+255+0)/3, (255+0+255)/3, (0+255+0)/3), which is (170, 170, 85). We round the decimal results to get the nearest integers (i.e. 10.4 is regarded as 10; 10.5 is regarded as 11).

Black and White do not have blending effects.

In the final design, only squares and circles are used. Designers want to have a program to automatically calculate the color at any chosen point.

When a chosen point is within one or more shapes, report the color or mixed color at that point.
When a chosen point is outside the shapes, report White (255, 255, 255).
When a chosen point is on the borderline of any shape, report Black (0, 0, 0).
Input
Line 1: Integer S and P, for the number of Shapes and number of checking points.

Next S lines: Each line defines one Shape by seven elements, space separated:
name is either SQUARE or CIRCLE
x0 y0 are integers. For a circle, this is the coordinates of the center. For a square, it is the coordinates of the lower-left corner. We are using the Cartesian coordinates system. All square sides are parallel to the x or y axis.
len is an integer. For a circle, it is the radius. For a square, it is the side length.
R G B are integers, color values of this shape.

Next P lines: Each line defines a point by integers x y. You have to calculate the color at each of the points.
Output
Write P lines Each line is a RGB color notation in format (R, G, B).
Constraints
1 ≤ S ≤ 50
1 ≤ P ≤ 50
0 ≤ x, y ≤ 1000 (This is the canvas size limit)
1 ≤ len ≤ 500
0 ≤ R, G, B ≤ 255

Some shapes may be partially drawn outside the canvas. Your business is within the canvas only.
Example
Input
3 6
SQUARE 0 5 6 255 0 0
SQUARE 4 2 3 0 255 0
CIRCLE 4 6 3 0 0 255
0 0
4 5
2 6
5 3
5 4
3 4
Output
(255, 255, 255)
(0, 0, 0)
(128, 0, 128)
(0, 255, 0)
(0, 128, 128)
(0, 0, 255)

]]--

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.
-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.


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

function round(num)
    return math.floor(num+0.5)
end

function avg(colors)
    rs = 0
    gs = 0
    bs = 0
    for i=1,#colors do
        rs = rs+colors[i].r + rs
        gs = gs+colors[i].g + gs
        bs = bs+colors[i].b + bs
    end
    return {r=round(rs/#colors), g=round(gs/#colors), b=round(bs/#colors)}
end

shapes = {}

function createShape(shape)
    spl = split(shape)
    sh = {
        type=spl[1],
        x=spl[2],
        y=spl[3],
        l=spl[4],
        r=spl[5],
        g=spl[6],
        b=spl[7]
    }
    table.insert(shapes, sh)
end

function hitTestCircle(x,y,v)
    border = false
    wrap = false
    -- border case
    ox = v.x
    oy = v.y
    cx = x - ox
    cy = y - oy
    cxsq = cx * cx
    rsq = v.l * v.l
    diff = rsq - cxsq
    testy = math.sqrt(diff)
    ntesty = -1 * testy
    max = testy > ntesty and testy or ntesty
    min = testy < ntesty and testy or ntesty
    return border,wrap
end

function hitTestSquare(x,y,v)
    border = false
    wrap = false
    sqx = v.x
    sqy = v.y
    l = v.l
    if sqx == x or sqy == y or x == sqx+l or y == sqy+l then
        border = true
        wrap = false
    end

    xin = x > sqx and x < sqx+l
    yin = y > sqy and y < sqy+l
    if xin and yin then wrap = true end
    return border,wrap
end

function hitTest(x,y)
    wrapped = {}
    borders = {}
    for _,v in ipairs(shapes) do
        hit = false
        if v.type == CIRCLE then
            hit, border = hitTestCircle(x,y,v)
        else
            hit, border = hitTestSquare(x,y,v)
        end
        if border then
            table.insert(borders, 1)
        end
        if hit then
            table.insert(wrapped, {r=v.r, g=v.g,b=v.b})
        end
    end
end

function pp(w,b)
  if #b != 0 then
    print("(0, 0, 0)")
    return
  end

  if #w == 0 then
    print("(255, 255, 255)")
    return
  end

  shape = avg(w)
  print("("..shape.r..", "..shape.g..", "..shape.b..")")
end

next_token = string.gmatch(io.read(), "[^%s]+")
S = tonumber(next_token())
P = tonumber(next_token())
for i=0,S-1 do
    line = io.read()
    createShape(line)
end

-- testing

for _,v in ipairs(shapes) do
    io.stderr:write("pretty printing "..v.type.." "..v.x.." "..v.y.." "..v.l.." "..v.r.." "..v.g.." "..v.b.."\n")
end

for i=0,P-1 do
    next_token = string.gmatch(io.read(), "[^%s]+")
    x = tonumber(next_token())
    y = tonumber(next_token())
    wrap, border = hitTest(x,y)
    pp(wrap, border)
end

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print("answer")