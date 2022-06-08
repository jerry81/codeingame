import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# r: number of rows.
# c: number of columns.
# a: number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
r, c, a = [int(i) for i in input().split()]
visited = {}
breadcrumb = []
def is_visited(key):
  try:
      _ = visited[key]
      return True
  except:
      return False

# game loop
while True:
    count = 0 
    reached = False
    grid = []

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
    ur = kr - 1 
    dr = kr + 1 
    lc = kc - 1 
    rc = kc + 1 
    if ur >= 0:
      if grid[ur][kc] == '.' and not is_visited(f"{ur},{kc}"):
          # move up
          breadcrumb.append("DOWN")
          print("UP")
          continue
    if dr < r:
      if grid[dr][kc] == '.' and not is_visited(f"{dr},{kc}"):
          # move down 
          breadcrumb.append("UP")
          print("DOWN")
          continue
    if lc >= 0:
      if grid[kr][lc] == '.' and not is_visited(f"{kr},{lc}"):
          # move left
          breadcrumb.append("RIGHT")
          print("LEFT")
          continue
    if rc < c:
      if grid[kr][rc] == '.' and not is_visited(f"{kr},{rc}"):
          # move right 
          breadcrumb.append("LEFT")
          print("RIGHT")
          continue

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
