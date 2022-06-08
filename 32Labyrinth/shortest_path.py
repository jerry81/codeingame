grid = []
grid.append(['e','x','x','x','x'])
grid.append(['x','x','x','x','x'])
grid.append(['x','x','x','x','x'])
grid.append(['x','x','x','x','s'])

def mark_distances_from(grid,x,y):
    grid[y][x] = 0
    # neighbors 
    uy = y-1
    dy = y+1
    lx = x-1
    rx = x+1 
    if uy >= 0:
        grid[uy][x] = 1
    if dy < len(grid):
        grid[dy][x] = 1 
    if lx >= 0:
        grid[y][lx] = 1 
    if rx < len(grid[0]):
        grid[y][rx] = 1

mark_distances_from(grid,0,0)
print(f"markdistances {grid}")

# 0 1 2 3 4 
# 1 2 3 4 5 
# 2 3 4 5 6
# etc...

grid = []
grid.append(['e','.','7','8','9'])
grid.append(['0','.','6','7','8'])
grid.append(['1','.','5','.','9'])
grid.append(['2','3','4','.','s'])

# x, x, dddrruuu
# d, x, dddrruu
# dd, x, dddrru
# ddd, dddr, dddrr

grid = []
grid.append(['2','1','2','.','x','x','x','x','x'])
grid.append(['1','e','1','.','x','x','x','x','x'])
grid.append(['2','1','2','.','x','x','x','x','x'])
grid.append(['3','2','3','.','x','x','x','x','x'])
grid.append(['.','.','.','.','x','x','x','x','x'])
grid.append(['x','x','x','x','x','x','x','x','x'])
grid.append(['x','x','x','x','x','x','x','x','x'])
grid.append(['x','x','x','x','x','x','x','x','x'])
grid.append(['x','x','x','x','x','x','x','x','x'])