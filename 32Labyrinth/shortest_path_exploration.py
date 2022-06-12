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

def mark(grid,x,y,w,h):
    distances = defaultdict(lambda: 9999)
    distances[y,x] = 0
    neighbors = []
    visited = defaultdict(lambda: False)
    visited[y,x] = True
    d = y+1
    u = y-1
    r = x+1
    l = x-1
    if d < h:
        if not visited[d,x]:
          neighbors.append((d,x))
    if u >= 0:
        if not visited[u,x]:
          neighbors.append((u,x))
    if r < w:
        if not visited[y,r]:
          neighbors.append((y,r))
    if l >= 0:
        if not visited[y,l]:
          neighbors.append((y,l))
    return res

res = mark(tg,0,0)
print('r"')
for r in res:
    print(r)