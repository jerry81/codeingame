import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
x, y = [int(i) for i in input().split()]

def make_grid(gn,gx,gy):
    dim = 2**gn
    grid = []
    for i in range(dim):
        grid.append([])
        for _ in range(dim):
            grid[i].append(' ')
    grid[gy][gx] = "h" # o for original hole
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

# prepare grid - separate original hole with the created holes 

# make a new method to print the grid
def pprint(grid,y,x):
    # split into blocks of 2x2
    dim = len(grid)
    w = dim*3+1
    h = dim*2+1
    # this is a trap! pgrid = [[' ']*w]*l 
    pgrid = [[' ' for _ in range(w)] for _ in range(h)]
    # make first and last lines
    # next two loops probably not necessary
    # for idx in range(w//3):
    #     pgrid[0][idx*3:(idx+1)*3] = ['+','-','-']
    #     pgrid[0][w-1] = '+'
    #     pgrid[h-1][idx*3:(idx+1)*3] = ['+','-','-']
    #     pgrid[h-1][w-1] = '+'
    # for idx in range(h):
    #     pgrid[idx][0] = ['+', '|'][idx%2]
    #     pgrid[idx][w-1] = ['+', '|'][idx%2]
    for idx_y in range(dim//2):
      for idx_x in range(dim//2):
          cy = idx_y*2
          cx = idx_x*2
          py = cy*2
          px = cx*3
          ul = grid[cy][cx]
          ur = grid[cy][cx+1]
          dl = grid[cy+1][cx]
          dr = grid[cy+1][cx+1]
          if ul == 'h':
              # 4 lines 
              pgrid[py][px+3:px+7] =    list("+--+")
              pgrid[py+1][px+3:px+7] =  list("|  |")
              pgrid[py+2][px:px+7] = list("+--+  +")
              pgrid[py+3][px:px+7] = list("|     |")
              pgrid[py+4][px:px+7] = list("+--+--+")
              # put a shape in the pgrid
          if ur == 'h':
              pgrid[py][px:px+4] =   list("+--+")
              pgrid[py+1][px:px+4] = list("|  |")
              pgrid[py+2][px:px+7] = list("+  +--+")
              pgrid[py+3][px:px+7] = list("|     |")
              pgrid[py+4][px:px+7] = list("+--+--+")
          if dl == 'h':
              pgrid[py][px:px+7] =   list("+--+--+")
              pgrid[py+1][px:px+7] = list("|     |")
              pgrid[py+2][px:px+7] = list("+--+  +")
              pgrid[py+3][px+3:px+7] =  list("|  |")
              pgrid[py+4][px+3:px+7] =  list("+--+")
          if dr == 'h': 
              pgrid[py][px:px+7] =   list("+--+--+")
              pgrid[py+1][px:px+7] = list("|     |")
              pgrid[py+2][px:px+7] = list("+  +--+")
              pgrid[py+3][px:px+4] = list("|  |")
              pgrid[py+4][px:px+4] = list("+--+")
    # draw the hole 
    py = y*2
    px = x*3
    pgrid[py][px:px+4] =   "+--+"
    pgrid[py+1][px:px+4] = "|##|"
    pgrid[py+2][px:px+4] = "+--+"
    for i in pgrid:
      joined="".join(i)
      print(joined) 
    
"""
given 
divided is [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '] 
divided is [' ', 'h', 'h', ' ', ' ', 'h', 'h', ' '] 
divided is [' ', 'h', ' ', ' ', ' ', ' ', 'h', ' '] 
divided is [' ', ' ', ' ', 'h', 'h', ' ', ' ', ' '] 
divided is [' ', ' ', ' ', ' ', 'h', ' ', ' ', ' '] 
divided is [' ', 'h', 'h', ' ', ' ', ' ', 'h', ' '] 
divided is ['o', ' ', 'h', ' ', ' ', 'h', 'h', ' '] 
divided is [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '] 

+--+--+
|     |
+  +--+
|  |
+--+
should print 
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

8x8 => 8*2 = 16 + 1 = 17 x 8*3 = 24 + 1 = 25

divided is [' ', ' ', ' ', ' '] 
divided is ['o', ' ', 'h', ' '] 
divided is [' ', 'h', 'h', ' '] 
divided is [' ', ' ', ' ', ' '] 

should print 
+--+--+--+--+
|     |     |
+--+  +--+  +
|##|  |  |  |
+--+--+  +--+
|  |     |  |
+  +--+--+  +
|     |     |
+--+--+--+--+

4x4 -> 13x9
"""
pprint(grid,y,x)
