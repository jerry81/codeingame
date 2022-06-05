import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
grid = [[""]*9 for _ in range(9)]
# need validator for every row
# every column
# 9 blocks 
for i in range(9):
    for idx,j in enumerate(input().split()):
        n = int(j)
        grid[i][idx] = n

print(f"grid is {grid}", file=sys.stderr, flush=True)

def validate(g):
    VALIDATOR = [1,2,3,4,5,6,7,8,9]
    copy1 = VALIDATOR.copy()
    for i in range(9):
        row = grid[i]
        for x in row:
            try:
                copy1.remove(x)
            except:
                print("false")
                return 


# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

validate(grid)
