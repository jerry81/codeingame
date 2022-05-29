import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

width, height = [int(i) for i in input().split()]
steps = int(input())
ax, ay = [int(i) for i in input().split()]
bx, by = [int(i) for i in input().split()]
cx, cy = [int(i) for i in input().split()]
dx, dy = [int(i) for i in input().split()]

def interpolate(t,px,py,qx,qy):
    rx = px*(1-t) + qx*(t)
    ry = py*(1-t) + qy*(t)
    return rx,ry

def get_point(t,ax,ay,bx,by,cx,cy,dx,dy):
    abx,aby = interpolate(t,ax,ay,bx,by)
    bcx,bcy = interpolate(t,bx,by,cx,cy)
    cdx,cdy = interpolate(t,cx,cy,dx,dy)
    abcx,abcy = interpolate(t,abx,aby,bcx,bcy)
    bcdx,bcdy = interpolate(t,bcx,bcy,cdx,cdy)
    px,py = interpolate(t,abcx,abcy,bcdx,bcdy)
    return px,py

points = [{"x":ax, "y": ay}, {"x":dx, "y":dy}]
s = 1/(steps-1)
print(f"step is {s}", file=sys.stderr, flush=True)
for i in range(1,steps-1):
    t = i*s
    px,py = get_point(t,ax,ay,bx,by,cx,cy,dx,dy)
    points.append({"x":px, "y":py})

print(f"points are {points}", file=sys.stderr, flush=True)

rounded = list(map(lambda item: {"x":round(item["x"]), "y":round(item["y"])},points))

print(f"rounded are {rounded}", file=sys.stderr, flush=True)

# ascii printing

# make a dictionary with keys of the heights from 0 to height
grid = {}
for i in range(height):
    grid[i] = []

for p in rounded:
    y = p["y"]
    grid[y].append(p["x"])
    
for v in grid.values():
   v.sort()

print(f"grid is {grid}", file=sys.stderr, flush=True)

for i in range(height):

    # Write an answer using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    print("curve")
