import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

number_snails = int(input())
snails = {}
for i in range(number_snails):
    speed_snail = int(input())
    snails[i+1] = {"s": speed_snail}
goals = []
map_height = int(input())
map_width = int(input())
for i in range(map_height):
    row = input()
    for j in range(map_width):
        c = row[j]
        if c == '#':
            goals.append({'x':j,'y':i})
        elif c != '*':
            snail = snails[int(c)]
            snail['x'] = j
            snail['y'] = i

def get_closest_goal(s, g):
  sx=s['x']
  sy=s['y']
  closest_d = 100
  for x in g:
      gx = x['x']
      gy = x['y']
      dist = abs(gx - sx) + abs(gy - sy)
      if dist < closest_d:
          closest_d = dist 
  return closest_d 

for k,v in snails.items():
    dist = get_closest_goal(v, goals)
    turns = math.ceil(dist/snails[k]["s"])
    snails[k]["t"] = turns

sorted = {k: v for k,v in sorted(snails.items(), key=lambda item: item[1]['t'])} 
# see https://stackoverflow.com/questions/16412563/python-sorting-dictionary-of-dictionaries for example 

print(f"snails are {snails}", file=sys.stderr, flush=True)
print(f"goals are {goals}", file=sys.stderr, flush=True)
print(f"sorted are {sorted}", file=sys.stderr, flush=True)

print(list(sorted.keys())[0])
