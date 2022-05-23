import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w = int(input())
h = int(input())
grid = []
for i in range(h):
    line = input()
    grid.append(list(line)) # python has no list.push

for row,y in enumerate(grid):
  for col,x in enumerate(y):
    if x == 'x':
      print(f'mine found at {row} {col}', file=sys.stderr, flush=True)
      uy = row-1 
      dy = row+1 
      lx = col-1
      rx = col+1
      if uy > -1:
        if grid[uy][col] == '.':
          grid[uy][col] = 1
        elif grid[uy][col] != 'x':
          grid[uy][col] += 1
      if dy < h:
        if grid[dy][col] == '.':
          grid[dy][col] = 1
        elif grid[dy][col] != 'x':
          grid[dy][col] += 1
      if rx < w:
        if grid[row][rx] == '.':
          grid[row][rx] = 1
        elif grid[row][rx] != 'x':
          grid[row][rx] += 1
      if lx > -1:
        if grid[row][lx] == '.':
          grid[row][lx] = 1
        elif grid[row][lx] != 'x':
          grid[row][lx] += 1
      

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
print(f'grid is {grid}', file=sys.stderr, flush=True)
for x in grid:
    st = ''.join(x)
    print(f'{st}')
