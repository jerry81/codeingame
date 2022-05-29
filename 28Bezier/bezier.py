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
    cur = height - i - 1
    cur_l = grid[cur]
    if len(cur_l) == 0:
        print('.')
    else:
        count = 0
        mx = max(cur_l)
        print(f"max is {mx}", file=sys.stderr, flush=True)
        chr_arr = [' '] * (mx+1)
        print(f"chr is {chr_arr}", file=sys.stderr, flush=True)
        chr_arr[0] = '.'
        for i in cur_l:
            print(f"i is {i}", file=sys.stderr, flush=True)
            chr_arr[i] = '#'
        print(f"chr_arr is {chr_arr}", file=sys.stderr, flush=True)
        print (''.join(chr_arr))
