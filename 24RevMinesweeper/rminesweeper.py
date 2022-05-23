import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w = int(input())
h = int(input())
grid = []
for i in range(h):
    line = input()
    grid.append(line) # python has no list.push

for row,y in enumerate(grid):
  for col,x in enumerate(y):
    if x == 'x':
      print(f'mine found at {row} {col}', file=sys.stderr, flush=True)

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
print(f'grid is {grid}', file=sys.stderr, flush=True)
print("answer")
