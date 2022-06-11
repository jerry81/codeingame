from http.client import CONTINUE
import sys

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def getClosestNeighbor(cur,dist_map):
  sp = cur.split(',')
  y = int(sp[0])
  x = int(sp[1])
  uy = y-1
  dy = y+1
  lx = x-1
  rx = x+1 
  has_u = False
  has_d = False
  has_r = False
  has_l = False
  try:
      has_u = dist_map[f"{uy},{x}"] >= 0
  except:
      has_u = False 
  try:
      has_d = dist_map[f"{dy},{x}"] >= 0
  except:
      has_d = False 
  try:
      has_l = dist_map[f"{y},{lx}"] >= 0
  except:
      has_l = False 
  try:
      has_r = dist_map[f"{y},{rx}"] >= 0
  except:
      has_r = False 
  min_d = 9999
  m_n = 'UP'
  key = None
  if has_u and dist_map[f"{uy},{x}"] < min_d:
      min_d = dist_map[f"{uy},{x}"]
      m_n = f"UP"
      key = f"{uy},{x}"
  if has_d and dist_map[f"{dy},{x}"] < min_d:
      min_d = dist_map[f"{dy},{x}"]
      m_n = f"DOWN"
      key = f"{dy},{x}"
  if has_r and dist_map[f"{y},{rx}"] < min_d:
      min_d = dist_map[f"{y},{rx}"]
      m_n = f"RIGHT"
      key = f"{y},{rx}"
  if has_l and dist_map[f"{y},{lx}"] < min_d:
      min_d = dist_map[f"{y},{lx}"]
      m_n = f"LEFT"
      key = f"{y},{lx}"
  return m_n,key

def getShortestFrom(y,x,dist_map):
    cur = f"{y},{x}"
    path = []
    dist = dist_map[cur]
    while dist > 0: 
      direction, key = getClosestNeighbor(cur, dist_map)
      if key is None:
          break
      path.append(direction)
      cur = key 
      dist = dist_map[cur]
    return path


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
  u_exist = False
  d_exist = False 
  l_exist = False 
  r_exist = False 
  try: 
    u_exist = grid[f"{uy},{x}"] is not None
  except:
    u_exist = False
  try:
      u_visited = visited[f"{uy},{x}"]
  except: 
      u_visited = False
  try:
      d_visited = visited[f"{dy},{x}"]
  except: 
      d_visited = False
  try: 
    d_exist = grid[f"{dy},{x}"] is not None
  except:
    d_exist = False
  try:
      l_visited = visited[f"{y},{lx}"]
  except: 
      l_visited = False
  try: 
    l_exist = grid[f"{y},{lx}"] is not None
  except:
    l_exist = False
  try:
      r_visited = visited[f"{y},{rx}"]
  except: 
      r_visited = False
  try: 
    r_exist = grid[f"{y},{rx}"] is not None
  except:
    r_exist = False
  if uy >= 0 and not u_visited and u_exist:
      neighbors.append(f"{uy},{x}")
  if dy < r and not d_visited and d_exist:
      neighbors.append(f"{dy},{x}")
  if lx >= 0 and not l_visited and l_exist:
      neighbors.append(f"{y},{lx}")
  if rx < c and not r_visited and r_exist:
      neighbors.append(f"{y},{rx}")
  return neighbors

def mark_distances_from(grid,x,y):
    distances = {}
    visited = {}
    for i in grid.keys():
      distances[i] = 9999
    distances[f"{y},{x}"] = 0
    visited[f"{y},{x}"] = True
    pointerx = x 
    pointery = y
    cur_d = 0
    neighbors = get_neighbors(pointerx,pointery,distances,visited)
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
            next_neighbors = get_neighbors(nx,ny,distances,visited)
            new_neighbors.append({"d":distances[n], "n":next_neighbors})
      next_set = new_neighbors
      for i in new_visited:
          visited[i] = True
    return distances
    

# r: number of rows.
# c: number of columns.
# a: number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
r, c, a = [int(i) for i in input().split()]
visited = {}
breadcrumb = []
tr = -1 
tc = -1
def is_visited(key):
  try:
      _ = visited[key]
      return True
  except:
      return False
explore = True

shortestPath = None

# game loop
while True:
    count = 0 
    grid = []
    # kr: row where Rick is located.
    # kc: column where Rick is located.
    kr, kc = [int(i) for i in input().split()]
    visited[f"{kr},{kc}"] = True
    
    for i in range(r):
        row = input()  # C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
        rl = list(row)
        grid.append(rl)
    if grid[kr][kc] == 'C':
      explore = False 

    if grid[kr][kc] == 'T':
      tr = kr
      tc = kc 
    
    if explore == False:
        if shortestPath is None:
            # build it
            distances = mark_distances_from(visited,tc,tr)
            shortestPath = getShortestFrom(kr,kc,distances)
            print(shortestPath.pop(0))
            continue
            # make distance map on the grid
            # starting with kr, kc
            # add neighbors
            # mark shortest distances of neighbors (0+1)
            # paths [0,n1] [0,n2]
            # for each path get last items' neighbors 
            # 
        else:
            # walk it
            print(f"before {shortestPath}", file=sys.stderr, flush=True)
            next = shortestPath.pop(0)
            print(f"after {shortestPath}", file=sys.stderr, flush=True)
            print(next)
            continue

    ur = kr - 1 
    dr = kr + 1 
    lc = kc - 1 
    rc = kc + 1 
    if ur >= 0:
      if grid[ur][kc] != '#' and not is_visited(f"{ur},{kc}"):
          # move up
          breadcrumb.append("DOWN")
          print("UP")
          continue
    if dr < r:
      if grid[dr][kc] != '#' and not is_visited(f"{dr},{kc}"):
          # move down 
          breadcrumb.append("UP")
          print("DOWN")
          continue
    if lc >= 0:
      if grid[kr][lc] != '#' and not is_visited(f"{kr},{lc}"):
          # move left
          breadcrumb.append("RIGHT")
          print("LEFT")
          continue
    if rc < c:
      if grid[kr][rc] != '#' and not is_visited(f"{kr},{rc}"):
          # move right 
          breadcrumb.append("LEFT")
          print("RIGHT")
          continue
    fallback = breadcrumb.pop()
    print(fallback)
    