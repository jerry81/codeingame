import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
x, y = [int(i) for i in input().split()]

# ideas
# 1.  simplify?  represent shapes with 0,1,2,3 - UL, UR, DL, DR (location of hole) - done 
# 2.  helper method to detect a fillable hole? - todo 
# 3.  "edge blocks" of 2x2 have limited choices
  # they always need to place the hole to the opposite direction of the corner it is in
  # unless they have the one hole specified in the input 
# 4.  in the case of 8*8 
  # the hole only appears in one place, so start with that 2*2 square 
  # then it fills the 4*4 square because we handled that before
  # then for the other 3 4*4 squares, they must leave a hole, so leave it in the corner away from the edge corner
# 5.  helper to draw - done
# 6.  improve helper to draw bigger squares 
# 7.  solve the "abstract" problem where 2x2 blocks represented with 0-4



def draw(type):
    l1 = '+--+--+'
    l3 = '+--+--+'
    l5 = '+--+--+'
    if type == 0:
        l2 = '|##|  |'
        l4 = '|  |  |'
    elif type == 1:
        l2 = '|  |##|'
        l4 = '|  |  |'
    elif type == 2:
        l2 = '|  |  |'
        l4 = '|##|  |'
    else:
        l2 = '|  |  |'
        l4 = '|  |##|'
    return [l1,l2,l3,l4,l5]
        
# start with line 1
def clean(lines):
    as_arr = list(map(lambda l: list(l), lines))
    h = len(as_arr)
    w = len(as_arr[0]) # assuming not empty 
    for i in range(0,h//2):
        ci = i * 2 + 1 
        for j in range(0,w//3):
            cj = j * 3 + 1
            hole_test = as_arr[ci][cj]
            if hole_test != '#':
                if cj < w-3:
                    as_arr[ci][cj+2] = ' '
                if ci < h-2:
                    as_arr[ci+1][cj] = ' '
                    as_arr[ci+1][cj+1] = ' '
            else: 
                as_arr[ci-1][cj-1:cj+3] = ['+','-','-','+']
                as_arr[ci][cj-1] = '|'
                as_arr[ci][cj+2] = '|'
                as_arr[ci+1][cj-1:cj+3] = ['+','-','-','+']
                
    return as_arr
                
def clean_holes(lines):
    print(f"todo: impl", file=sys.stderr, flush=True)

cleaned = clean(draw(3))
as_strs = list(map(lambda x: ''.join(x),cleaned))
for s in as_strs:
  print(f"s is {s}", file=sys.stderr, flush=True)

def pretty_p(cleaned):
  as_strs = list(map(lambda x: ''.join(x),cleaned))
  for s in as_strs:
    print(f"{s}")

def get_type(x,y):
    t = 0
    if x == 0:
        if y == 0:
            t = 0
        if y == 1:
            t = 2
    if x == 1:
        if y == 0:
            t = 1
        if y == 1:
            t = 3
    return t 

def solve(order,top,left,has_hole):
    if order == 1:
        nx = 0 if top else 1
        ny = 0 if left else 1
        return get_type(nx,ny)
    else:
        # for o == 2, in the start case, the exact starting block can be identified first 
        # x, y -> 0..3
        # ul 0..1, 0..1
        # let's say x is 0, y is 2
        # means the "hole" is in dl, why?
        # bc top half <= 2**order // 2 - 1
        n_o = order - 1
        ul = solve(n_o, False, False) if has_hole != 0 else solve(n_o, top, left)
        # ur 2..3, 0..1
        ur = solve(n_o, False, True)
        # dl 0..1, 2..3
        dl = solve(n_o, True, True)
        # dr 2..3, 2..3
        dr = solve(n_o, True, False)
        # o == 3?
        [ur,ur2,ul,ul2],[]

"""
divide and conquer picture
                                     s(8)
        s(4)                s(4)                s(4)                s(4)
s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) s(2) 
"""
        
top = y <= (2**n)//2 - 1 # hole is in top quadrant
left = x <= (2**n)//2 - 1 # hole is in left quadrant 

print(f"solve1 is {solve(1,False,False)}", file=sys.stderr, flush=True) 

print(f"solve2 is {solve(2,0,2)}", file=sys.stderr, flush=True) 


pretty_p(clean(draw(get_type(x,y))))



# analysis
"""
2
0 1
+--+--+--+--+
|     |     |
+--+  +--+  +
|##|  |  |  |
+--+--+  +--+
|  |     |  |
+  +--+--+  +
|     |     |
+--+--+--+--+
can be represented as 
2, 2
1, 0
where 0,0 was due to input
0,1 will always be 2
1,0 will always be 1
and 
1,1 will always be 0 


2
0 2
+--+--+--+--+
|     |     |
+  +--+--+  +
|  |     |  |
+--+--+  +--+
|##|  |  |  |
+--+  +--+  +
|     |     |
+--+--+--+--+
can be represented as 
3, 2
0, 0

3
2 3
+--+--+--+--+--+--+--+--+
|     |     |     |     |
+  +--+--+  +  +--+--+  +
|  |     |  |  |     |  |
+--+  +--+--+--+--+  +--+
|  |  |     |     |  |  |
+  +--+--+  +--+  +--+  +
|     |##|  |  |  |     |
+--+--+--+--+  +--+--+--+
|     |  |     |  |     |
+  +--+  +--+--+  +--+  +
|  |  |     |     |  |  |
+--+  +--+--+--+--+  +--+
|  |     |  |  |     |  |
+  +--+--+  +  +--+--+  +
|     |     |     |     |
+--+--+--+--+--+--+--+--+

3,2,3,2
1,2(exception), 2(because hole needs to be "centralized"), 0
3,1(centralize), 0(centralize), 2
1,0,1,0

3
0 6
+--+--+--+--+--+--+--+--+
|     |     |     |     |
+  +--+--+  +  +--+--+  +
|  |     |  |  |     |  |
+--+  +--+--+--+--+  +--+
|  |  |     |     |  |  |
+  +--+  +--+--+  +--+  +
|     |  |     |  |     |
+--+--+--+--+  +--+--+--+
|     |     |  |  |     |
+  +--+--+  +--+  +--+  +
|  |     |  |     |  |  |
+--+--+  +--+--+--+  +--+
|##|  |  |  |  |     |  |
+--+  +--+  +  +--+--+  +
|     |     |     |     |
+--+--+--+--+--+--+--+--+

3,2,3,2
1,3,2,0
3,2,0,2
0*,0,1,0
"""
