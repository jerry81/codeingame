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
        


print(f"grid is now {grid}", file=sys.stderr, flush=True)
print(f"candles are {candles}", file=sys.stderr, flush=True)
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("2")
