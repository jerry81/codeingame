# test dictionary

from collections import defaultdict
import copy


testd = {}
testd[0,0] = "fuck" # tuples as keys work 
b = 0
testd[0+1,b+1] = "you" # manipulation of tuples works 
print(f"testd is {testd}")

x = 1,2
print(f"x is {x}") # is a tuple 

tg = [['.']*10 for _ in range(10)]
for g in tg:
    print(g)

for i in range(9):
    tg[i][3] = 'x'

for i in range(1,10):
    tg[i][5] = 'x'

def mark(grid,x,y,w,h):
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

res = mark(tg,0,0,10,10)
for item in res.items():
    y,x = item[0]
    tg[y][x] = item[1]

print('r"')
for r in res.items():
    print(r)

for t in tg:
    print(t)