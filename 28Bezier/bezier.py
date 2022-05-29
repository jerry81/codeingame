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

points = []
s = 1/(steps-1)
print(f"step is {s}", file=sys.stderr, flush=True)
for i in range(steps-1):
    t = i*s
    print(f"t is {t}", file=sys.stderr, flush=True)
    px,py = get_point(t,ax,ay,bx,by,cx,cy,dx,dy)
    print(f"point is {px} {py}", file=sys.stderr, flush=True)

for i in range(height):

    # Write an answer using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    print("curve")
