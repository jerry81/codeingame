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
    for i in range(9):
        copy1 = VALIDATOR.copy()
        row = grid[i]
        for x in row:
            try:
                copy1.remove(x)
            except:
                return False
        if len(copy1) != 0:
            return False
    for i in range(9):
        copy2 = VALIDATOR.copy()
        for j in grid:
            try:
                copy2.remove(j[i])
            except:
                return False 
        if len(copy2) != 0:
            return False 
    for offsetx in range(0,9,3):
        for offsety in range(0,9,3):
          copy3 = VALIDATOR.copy()
          for i in range(3):
              for j in range(3):
                try:
                    copy3.remove(grid[i+offsety][j+offsetx])
                except: 
                    return False
          if len(copy3) != 0:
              return False 
    return True 

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
res = "true" if validate(grid) else "false"
print(res)
