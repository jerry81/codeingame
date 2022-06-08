import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# r: number of rows.
# c: number of columns.
# a: number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
r, c, a = [int(i) for i in input().split()]

# game loop
while True:
    count = 0 
    reached = False
    grid = []
    visited = {}
    breadcrumb = []
    STATE = "EXPLORE"
    STATE = "FOUND"
    STATE = "REACHED"
    # kr: row where Rick is located.
    # kc: column where Rick is located.
    kr, kc = [int(i) for i in input().split()]
    visited[f"{kr},{kc}"] = True
    for i in range(r):
        row = input()  # C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
        rl = list(row)
        grid.append(rl)
    print(f"grid is {grid}", file=sys.stderr, flush=True)
    print(f"visited is {visited}")
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)
    # 3 phases - C not found
    # C found
    # C reached
    # 2 large problems - find control
    # shortest path back with something like a*
    # OR
    # keep breadcrumb trail 
    # heuristic rules
    # keep track of explored and unexplored nodes 
    # shortest path util handy in both cases
      # if C has been found, try to find a path to C 
      # using dykstra
    # if path not found
    # move to closest unexplored 
    # Rick's next move (UP DOWN LEFT or RIGHT).
    print("RIGHT")
