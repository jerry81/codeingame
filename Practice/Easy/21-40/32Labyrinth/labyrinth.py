from collections import defaultdict
import sys

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def mark(grid,x,y,w,h):
    # print(f"w is {w} h is {h}", file=sys.stderr, flush=True)
    distances = defaultdict(lambda: 9999)
    neighbors = [(y,x)]
    distances[y,x] = 0
    visited = defaultdict(lambda: False)
    while len(neighbors) > 0:
      ny,nx = neighbors.pop(0)
      cur = distances[ny,nx]
      visited[ny,nx] = True
      d = ny+1
      u = ny-1
      r = nx+1
      l = nx-1
      if d < h:
          grid_item = grid[d][nx]
          if not visited[d,nx] and grid_item == '.':
            neighbors.append((d,nx))
      if u >= 0:
          grid_item = grid[u][nx]
          if not visited[u,nx] and grid_item == '.':
            neighbors.append((u,nx))
      if r < w:
          grid_item = grid[ny][r]
          if not visited[ny,r] and grid_item == '.':
            neighbors.append((ny,r))
      if l >= 0:
          grid_item = grid[ny][l]
          if not visited[ny,l] and grid_item == '.':
            neighbors.append((ny,l))
      for tup in neighbors:
          distances[tup] = min(cur + 1, distances[tup])
          visited[tup] = True 
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
            dists = mark(grid,tc,tr,c,r)
            for k,v in dists.items():
                y,x = k
                grid[y][x] = v
            # build path from grid
            path = []
            cy = kr 
            cx = kc
            while (cy!=tr or cx!=tc):
                d = cy + 1
                u = cy - 1 
                ri = cx + 1 
                le = cx - 1
                nx = cx 
                ny = cy
                md = "UP"
                mdist = 9999
                if u >=0:
                  i = grid[u][cx]
                  if type(i) == int: 
                    if i < mdist:
                        mdist = i 
                        md = "UP"
                        ny = u 
                        nx = cx
                if d < r:
                  i = grid[d][cx]
                  if type(i) == int:
                    if i < mdist:
                        mdist = i 
                        md = "DOWN"
                        ny = d
                        nx = cx
                if ri < c:
                  i = grid[cy][ri]
                  # print(f"right item is {i}", file=sys.stderr, flush=True)
                  if type(i) == int:
                    if i < mdist:
                        mdist = i 
                        md = "RIGHT"
                        ny = cy 
                        nx = ri
                if le >= 0:
                  i = grid[cy][le]
                  if type(i) == int:
                    if i < mdist:
                        mdist = i 
                        md = "LEFT"
                        ny = cy 
                        nx = le
                cy = ny 
                cx = nx
                path.append(md)
                # print(f"path is now {path}", file=sys.stderr, flush=True)
            
            shortestPath = path 
            # print(f"shortest path is {shortestPath}", file=sys.stderr, flush=True)
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
            next = shortestPath.pop(0)
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
    