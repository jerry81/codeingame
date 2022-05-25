n = int(input())
x, y = [int(i) for i in input().split()]
HOLE = 'h'
dim = 2**n
grid = [[' ' for _ in range(dim)] for _ in range(dim)]
grid[y][x] = HOLE

def find_hole(grid):
    l = len(grid)
    for i in range(l):
        for j in range(l):
            if grid[i][j] == HOLE:
                return True
    return False

def divide_grid(grid, ox, oy, ox2, oy2):
    if ox2-ox <= 2: 
        return
    l = ox2-ox
    nl = l//2
    mid_x = ox+nl
    mid_y = oy+nl
    u_grid = grid[oy:mid_y]
    d_grid = grid[mid_y:oy2]
    ul_grid = list(map(lambda x: x[ox:mid_x], u_grid))
    dl_grid = list(map(lambda x: x[ox:mid_x], d_grid))
    ur_grid = list(map(lambda x: x[mid_x:ox2], u_grid))
    ulh = find_hole(ul_grid)
    urh = find_hole(ur_grid)
    dlh = find_hole(dl_grid)
    if ulh:
        grid[mid_y-1][mid_x] = HOLE
        grid[mid_y][mid_x] = HOLE
        grid[mid_y][mid_x-1] = HOLE
    elif urh:
        grid[mid_y-1][mid_x-1] = HOLE 
        grid[mid_y][mid_x-1] = HOLE 
        grid[mid_y][mid_x] = HOLE
    elif dlh:
        grid[mid_y-1][mid_x-1] = HOLE
        grid[mid_y-1][mid_x] = HOLE
        grid[mid_y][mid_x] = HOLE
    else: # drh
        grid[mid_y-1][mid_x-1] = HOLE
        grid[mid_y][mid_x-1] = HOLE
        grid[mid_y-1][mid_x] = HOLE
    divide_grid(grid,ox,oy,mid_x,mid_y)
    divide_grid(grid,mid_x,oy,ox2,mid_y)
    divide_grid(grid,ox,mid_y,mid_x,oy2)
    divide_grid(grid,mid_x,mid_y,ox2,oy2)
    
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
          if ul == HOLE:
              pgrid[py][px+3:px+7] =    list("+--+")
              pgrid[py+1][px+3:px+7] =  list("|  |")
              pgrid[py+2][px:px+7] = list("+--+  +")
              pgrid[py+3][px:px+7] = list("|     |")
              pgrid[py+4][px:px+7] = list("+--+--+")
          if ur == HOLE:
              pgrid[py][px:px+4] =   list("+--+")
              pgrid[py+1][px:px+4] = list("|  |")
              pgrid[py+2][px:px+7] = list("+  +--+")
              pgrid[py+3][px:px+7] = list("|     |")
              pgrid[py+4][px:px+7] = list("+--+--+")
          if dl == HOLE:
              pgrid[py][px:px+7] =   list("+--+--+")
              pgrid[py+1][px:px+7] = list("|     |")
              pgrid[py+2][px:px+7] = list("+--+  +")
              pgrid[py+3][px+3:px+7] =  list("|  |")
              pgrid[py+4][px+3:px+7] =  list("+--+")
          if dr == HOLE: 
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
