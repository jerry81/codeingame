import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
x, y = [int(i) for i in input().split()]

# ideas
# 1.  simplify?  represent shapes with 0,1,2,3 - UL, UR, DL, DR (location of hole)
# 2.  helper method to detect a fillable hole?
# 3.  "edge blocks" of 2x2 have limited choices
  # they always need to place the hole to the opposite direction of the corner it is in
  # unless they have the one hole specified in the input 
# 4.  in the case of 8*8 
  # the hole only appears in one place, so start with that 2*2 square 
  # then it fills the 4*4 square because we handled that before
  # then for the other 3 4*4 squares, they must leave a hole, so leave it in the corner away from the edge corner
# 5.  helper to draw 

def draw(type):
    l1 = '+--+--+'
    l3 = '+--+--+'
    l5 = '+--+--+'
    if type == 0:
        l2 = '|xx|  |'
        l4 = '|  |  |'
    elif type == 1:
        l2 = '|  |xx|'
        l4 = '|  |  |'
    elif type == 2:
        l2 = '|  |  |'
        l4 = '|xx|  |'
    else:
        l2 = '|  |  |'
        l4 = '|  |xx|'
    return [l1,l2,l3,l4,l5]
        
for i in draw(0):
  print(f"test draw0 {i}", file=sys.stderr, flush=True)

for i in draw(1):
  print(f"test draw1 {i}", file=sys.stderr, flush=True)

for i in draw(2):
  print(f"test draw2 {i}", file=sys.stderr, flush=True)

for i in draw(3):
  print(f"test draw3 {i}", file=sys.stderr, flush=True)

# start with line 1
def clean(lines):
    h = len(lines)
    w = len(lines[0]) # assuming not empty 
    for i in range(0,h//2):
        ci = i * 2 + 1 
        for j in range (0,w//3):
            cj = j * 3 + 1
            print(f"test clean {lines[ci][cj]}", file=sys.stderr, flush=True)

clean(draw(0))
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("+--+")

for i in range(n):

    # Write an answer using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    print("|  |\n+--+")
