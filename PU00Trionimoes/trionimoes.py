import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
x, y = [int(i) for i in input().split()]

# ideas
# 1.  simplify?  represent shapes with 0,1,2,3 - UL, UR, DL, DR (location of hole) - done 
# 2.  helper method to detect a fillable hole? - todo 
# 3.  "edge blocks" of 2x2 have limited choices
  # they always need to place the hole to the opposite direction of the corner it is in
  # unless they have the one hole specified in the input 
# 4.  in the case of 8*8 
  # the hole only appears in one place, so start with that 2*2 square 
  # then it fills the 4*4 square because we handled that before
  # then for the other 3 4*4 squares, they must leave a hole, so leave it in the corner away from the edge corner
# 5.  helper to draw - done
# 6.  improve helper to draw bigger squares 
# 7.  solve the "abstract" problem where 2x2 blocks represented with 0-4



def draw(type):
    l1 = '+--+--+'
    l3 = '+--+--+'
    l5 = '+--+--+'
    if type == 0:
        l2 = '|##|  |'
        l4 = '|  |  |'
    elif type == 1:
        l2 = '|  |##|'
        l4 = '|  |  |'
    elif type == 2:
        l2 = '|  |  |'
        l4 = '|##|  |'
    else:
        l2 = '|  |  |'
        l4 = '|  |##|'
    return [l1,l2,l3,l4,l5]
        
# start with line 1
def clean(lines):
    as_arr = list(map(lambda l: list(l), lines))
    h = len(as_arr)
    w = len(as_arr[0]) # assuming not empty 
    for i in range(0,h//2):
        ci = i * 2 + 1 
        for j in range(0,w//3):
            cj = j * 3 + 1
            hole_test = as_arr[ci][cj]
            if hole_test != '#':
                if cj < w-3:
                    as_arr[ci][cj+2] = ' '
                if ci < h-2:
                    as_arr[ci+1][cj] = ' '
                    as_arr[ci+1][cj+1] = ' '
            else: 
                as_arr[ci-1][cj-1:cj+3] = ['+','-','-','+']
                as_arr[ci][cj-1] = '|'
                as_arr[ci][cj+2] = '|'
                as_arr[ci+1][cj-1:cj+3] = ['+','-','-','+']
                
    return as_arr
                
def clean_holes(lines):
    print(f"todo: impl", file=sys.stderr, flush=True)

cleaned = clean(draw(3))
as_strs = list(map(lambda x: ''.join(x),cleaned))
for s in as_strs:
  print(f"s is {s}", file=sys.stderr, flush=True)

def pretty_p(cleaned):
  as_strs = list(map(lambda x: ''.join(x),cleaned))
  for s in as_strs:
    print(f"{s}")

def get_type(x,y):
    t = 0
    if x == 0:
        if y == 0:
            t = 0
        if y == 1:
            t = 2
    if x == 1:
        if y == 0:
            t = 1
        if y == 1:
            t = 3
    return t 

"""
divide and conquer picture
                                                      s(0)     o = 3

           uls(0)                      urs(1)                      dls(2)                     drs(4)      o = 2

uls(0) urs(1) dls(2) drs(3) uls(4) urs(5) dls(6) drs(7) uls(8) urs(9) dls(10) drs(11) uls(12) urs(13) dls(14) drs(15)    o = 1
"""

"""
divide might not even be necessary

just create the grid which has a single hole 
and iteratively conker
"""
def make_grid(gn,gx,gy):
    dim = 2**gn
    grid = []
    for i in range(dim):
        grid.append([])
        for _ in range(dim):
            grid[i].append(' ')
    grid[gy][gx] = "h"
    return grid

grid = make_grid(n,x,y)
print(f"grid is {grid}", file=sys.stderr, flush=True) 
top = y <= (2**n)//2 - 1 # hole is in top quadrant
left = x <= (2**n)//2 - 1 # hole is in left quadrant 

def find_hole(grid):
    l = len(grid)
    for i in range(l):
        for j in range(l):
            if grid[i][j] == 'h':
                return True
    return False

def divide_grid(grid, ox, oy, ox2, oy2):
    # for recursion - need a stop condition 
    # need to call myself 
    if ox2-ox <= 2: 
        return
    l = ox2-ox
    nl = l//2
    u_grid = grid[oy:nl+oy]
    d_grid = grid[oy+nl:oy2]
    ul_grid = list(map(lambda x: x[ox:ox+nl], u_grid))
    dl_grid = list(map(lambda x: x[ox:ox+nl], d_grid))
    ur_grid = list(map(lambda x: x[ox+nl:ox2], u_grid))
    # dr_grid = list(map(lambda x: x[nl:oy2], d_grid))
    ulh = find_hole(ul_grid)
    urh = find_hole(ur_grid)
    dlh = find_hole(dl_grid)
    if ulh:
        grid[oy+nl-1][ox+nl] = 'h'
        grid[oy+nl][ox+nl] = 'h'
        grid[oy+nl][ox+nl-1] = 'h'
    elif urh:
        grid[oy+nl-1][ox+nl-1] = 'h' # ul
        grid[oy+nl][ox+nl-1] = 'h' # 
        grid[oy+nl][ox+nl] = 'h'
    elif dlh:
        grid[oy+nl-1][ox+nl-1] = 'h'
        grid[oy+nl-1][ox+nl] = 'h'
        grid[oy+nl][ox+nl] = 'h'
    else: # drh
        grid[oy+nl-1][ox+nl-1] = 'h'
        grid[oy+nl][ox+nl-1] = 'h'
        grid[oy+nl-1][ox+nl] = 'h'
    divide_grid(grid,ox,oy,ox+nl,oy+nl)
    divide_grid(grid,ox+nl,oy,ox2,oy+nl)
    divide_grid(grid,ox,oy+nl,ox+nl,oy2)
    divide_grid(grid,ox+nl,oy+nl,ox2,oy2)
    
dim = len(grid)
divide_grid(grid,0,0,dim,dim)


for i in grid:
    print(f"divided is {i} ", file=sys.stderr, flush=True) 

pretty_p(clean(draw(get_type(x,y))))

"""
styding other DAC algorithms
- quicksort does in-place changes to the array - markers are passed in to "divide" the array 
"""

# analysis
"""
2
0 1
+--+--+--+--+
|     |     |
+--+  +--+  +
|##|  |  |  |
+--+--+  +--+
|  |     |  |
+  +--+--+  +
|     |     |
+--+--+--+--+
can be represented as 
2, 2
1, 0
where 0,0 was due to input
0,1 will always be 2
1,0 will always be 1
and 
1,1 will always be 0 


2
0 2
+--+--+--+--+
|     |     |
+  +--+--+  +
|  |     |  |
+--+--+  +--+
|##|  |  |  |
+--+  +--+  +
|     |     |
+--+--+--+--+
can be represented as 
3, 2
0, 0

3
2 3
+--+--+--+--+--+--+--+--+
|     |     |     |     |
+  +--+--+  +  +--+--+  +
|  |     |  |  |     |  |
+--+  +--+--+--+--+  +--+
|  |  |     |     |  |  |
+  +--+--+  +--+  +--+  +
|     |##|  |  |  |     |
+--+--+--+--+  +--+--+--+
|     |  |     |  |     |
+  +--+  +--+--+  +--+  +
|  |  |     |     |  |  |
+--+  +--+--+--+--+  +--+
|  |     |  |  |     |  |
+  +--+--+  +  +--+--+  +
|     |     |     |     |
+--+--+--+--+--+--+--+--+

3,2,3,2
1,2(exception), 2(because hole needs to be "centralized"), 0
3,1(centralize), 0(centralize), 2
1,0,1,0

3
0 6
+--+--+--+--+--+--+--+--+
|     |     |     |     |
+  +--+--+  +  +--+--+  +
|  |     |  |  |     |  |
+--+  +--+--+--+--+  +--+
|  |  |     |     |  |  |
+  +--+  +--+--+  +--+  +
|     |  |     |  |     |
+--+--+--+--+  +--+--+--+
|     |     |  |  |     |
+  +--+--+  +--+  +--+  +
|  |     |  |     |  |  |
+--+--+  +--+--+--+  +--+
|##|  |  |  |  |     |  |
+--+  +--+  +  +--+--+  +
|     |     |     |     |
+--+--+--+--+--+--+--+--+

3,2,3,2
1,3,2,0
3,2,0,2
0*,0,1,0
"""
