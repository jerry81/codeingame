grid = []
grid.append(['e','x','x','x','x'])
grid.append(['x','x','x','x','x'])
grid.append(['x','x','x','x','x'])
grid.append(['x','x','x','x','s'])

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
          distances[f"{i},{j}"] = 9999
    distances[f"{y},{x}"] = 0
    visited[f"{y},{x}"] = True
    pointerx = x 
    pointery = y
    cur_d = 0
    neighbors = get_neighbors(pointerx,pointery,grid,visited)
    new_neighbors = []
    new_visited = []
    min_dist = 9999
    for n in neighbors:
        n_a = n.split(',')
        nx = int(n_a[1])
        ny = int(n_a[0])
        n_d = distances[n]
        distances[n] = min([n_d, cur_d+1])
        if distances[n] <= min_dist:
            min_dist = distances[n]
            print(f"distances, mindist {distances[n]} {min_dist}")
            if distances[n] == min_dist:
                new_visited.append(n)
            else:
                new_visited = [n]
        new_neighbors.append(get_neighbors(nx,ny,grid,visited))
    flat_list = [x for xs in new_neighbors for x in xs]
    as_set = list(set(flat_list))
    print(f"as set {as_set}")
    print(f"visited {new_visited}")
    # print(f"neighbors are {neighbors}")
    print(f"distances are now {distances}")
    

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