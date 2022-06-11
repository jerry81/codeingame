grid = []
grid.append(['e','x','x','x','x'])
grid.append(['x','x','x','x','x'])
grid.append(['x','x','x','x','x'])
grid.append(['x','x','x','x','x'])

"""
a - b - c
|   |   |
d - e - f
|   |   |
g - h - i 

01c - a,b,c visited
1ef
ghi

012 - c e g visited
12
2


a.g
b.h
cei
dfj

0 6
1 5
234
345
"""

def get_neighbors(x,y,grid,visited):
  uy = y-1
  dy = y+1
  lx = x-1
  rx = x+1 
  neighbors = []
  u_visited = False
  d_visited = False
  l_visited = False 
  r_visited = False
  try:
      u_visited = visited[f"{uy},{x}"]
  except: 
      u_visited = False
  try:
      d_visited = visited[f"{dy},{x}"]
  except: 
      d_visited = False
  try:
      l_visited = visited[f"{y},{lx}"]
  except: 
      l_visited = False
  try:
      r_visited = visited[f"{y},{rx}"]
  except: 
      r_visited = False
  if uy >= 0 and grid[uy][x] == 'x' and not u_visited:
      neighbors.append(f"{uy},{x}")
  if dy < len(grid) and grid[dy][x] == 'x' and not d_visited:
      neighbors.append(f"{dy},{x}")
  if lx >= 0 and grid[y][lx] == 'x' and not l_visited:
      neighbors.append(f"{y},{lx}")
  if rx < len(grid[0]) and grid[y][rx] == 'x' and not r_visited:
      neighbors.append(f"{y},{rx}")
  return neighbors

def mark_distances_from(grid,x,y):
    distances = {}
    visited = {}
    for i in range(len(grid)):
        for j in range(len(grid[0])):
          if grid[i][j] != '.':
              distances[f"{i},{j}"] = 9999
    distances[f"{y},{x}"] = 0
    visited[f"{y},{x}"] = True
    pointerx = x 
    pointery = y
    cur_d = 0
    neighbors = get_neighbors(pointerx,pointery,grid,visited)
    next_set = [{"d": cur_d, "n": neighbors}]
    while len(next_set) > 0:
      new_neighbors = []
      new_visited = []
      min_dist = 9999
      for ns in next_set:
          cur_dist = ns["d"]
          neighbors = ns["n"]
          for n in neighbors: 
            n_a = n.split(',')
            nx = int(n_a[1])
            ny = int(n_a[0])
            n_d = distances[n]
            distances[n] = min([n_d, cur_dist+1])
            if distances[n] <= min_dist:
                min_dist = distances[n]
                if distances[n] == min_dist:
                    new_visited.append(n)
                else:
                    new_visited = [n]
            next_neighbors = get_neighbors(nx,ny,grid,visited)
            new_neighbors.append({"d":distances[n], "n":next_neighbors})
      next_set = new_neighbors
      for i in new_visited:
          visited[i] = True
    return distances
    

# grid[y][x] = 0
# uy = y-1
# dy = y+1
# lx = x-1
# rx = x+1 
# if uy >= 0:
#     grid[uy][x] = 1
# if dy < len(grid):
#     grid[dy][x] = 1 
# if lx >= 0:
#     grid[y][lx] = 1 
# if rx < len(grid[0]):
#     grid[y][rx] = 1

d = mark_distances_from(grid,0,0)
print(f"markdistances {d}")

# 0 1 2 3 4 
# 1 2 3 4 5 
# 2 3 4 5 6
# etc...

grid = []
grid.append(['e','.','x','x','x'])
grid.append(['x','.','x','x','x'])
grid.append(['x','.','x','.','x'])
grid.append(['x','x','x','.','x'])

d = mark_distances_from(grid,0,0)
print(f"markdistances {d}")

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