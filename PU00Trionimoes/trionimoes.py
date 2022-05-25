import sys
import math

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

def find_hole(grid):
    l = len(grid)
    for i in range(l):
        for j in range(l):
            if grid[i][j] == 'h':
                return True
    return False

def divide_grid(grid, ox, oy, ox2, oy2):
    if ox2-ox <= 2: 
        return
    l = ox2-ox
    nl = l//2
    u_grid = grid[oy:nl+oy]
    d_grid = grid[oy+nl:oy2]
    ul_grid = list(map(lambda x: x[ox:ox+nl], u_grid))
    dl_grid = list(map(lambda x: x[ox:ox+nl], d_grid))
    ur_grid = list(map(lambda x: x[ox+nl:ox2], u_grid))
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

def pprint(grid,y,x):
    dim = len(grid)
    w = dim*3+1
    h = dim*2+1
    pgrid = [[' ' for _ in range(w)] for _ in range(h)]
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
              pgrid[py][px+3:px+7] =    list("+--+")
              pgrid[py+1][px+3:px+7] =  list("|  |")
              pgrid[py+2][px:px+7] = list("+--+  +")
              pgrid[py+3][px:px+7] = list("|     |")
              pgrid[py+4][px:px+7] = list("+--+--+")
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
    py = y*2
    px = x*3
    pgrid[py][px:px+4] =   "+--+"
    pgrid[py+1][px:px+4] = "|##|"
    pgrid[py+2][px:px+4] = "+--+"
    for i in pgrid:
      joined="".join(i)
      print(joined) 
    
pprint(grid,y,x)
