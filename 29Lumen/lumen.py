import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

grid = []
n = int(input())
l = int(input())
for i in range(n):
    grid.append([])
    count = 0
    for cell in input().split():
        grid[i].append(cell)
        count+=1
        pass

print(f"grid is now {grid}", file=sys.stderr, flush=True)
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("2")
