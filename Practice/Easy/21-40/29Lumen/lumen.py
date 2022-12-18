import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

grid = []
candles = []
n = int(input())
l = int(input())
for i in range(n):
    grid.append([])
    count = 0
    for cell in input().split():
        grid[i].append(cell)
        if cell == 'C':
            candles.append({"y":i, "x":count})
        count+=1
        
def light_grid(c):
    x = c["x"]
    y = c["y"]
    for dx in range(-l,l+1):
      if x+dx < 0: 
          continue 
      
      if x+dx >= n:
          continue

      for dy in range(-l,l+1):
          if y+dy < 0: 
              continue 

          if y+dy >= n: 
              continue 

          cl = l - max([abs(dx),abs(dy)])
          
          grid_item = grid[y+dy][x+dx]
          if grid_item == 'X' or grid_item == 'C':
            grid[y+dy][x+dx] = cl
          else:
            grid[y+dy][x+dx] = max([cl, int(grid_item)])


for c in candles:
    light_grid(c)

flattened = [x for i in grid for x in i]
print(len(list(filter(lambda x: x == 0 or x == 'X', flattened))))
print(f"grid is now {grid}", file=sys.stderr, flush=True)
print(f"candles are {candles}", file=sys.stderr, flush=True)
print(f"flattened is {flattened}", file=sys.stderr, flush=True)

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

# print("2")
