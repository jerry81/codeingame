import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

grid = []
n = int(input())
l = int(input())
for i in range(n):
    grid[i] = []
    count = 0
    for cell in input().split():
        count+=1
        grid[i][count]=cell
        pass

print(f"grid is now {grid}", file=sys.stderr, flush=True)
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("2")
