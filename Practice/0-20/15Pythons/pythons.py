import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.


strArr = []
heads = []
n, m = [int(i) for i in input().split()]
for i in range(n):
    t = input()
    strArr.append(t)
    for j in range(m):
        if t[j] == 'o':
            heads.append({"i":i, "j":j})

def getNextPos(ci,cj,direction):
    ni = ci 
    nj = cj 
    if direction == 'L':
        nj -= 1
    elif direction == 'R':
        nj += 1
    elif direction == 'U':
        ni -= 1
    else:
        ni += 1
    return ni,nj
    

def getNextDir(hi, hj, preclude = None):
    direction = ""
    hri = hi
    hrj = hj + 1
    hli = hi
    hlj = hj - 1
    hui = hi - 1
    hdi = hi + 1
    huj = hj
    hdj = hj
    if hrj < j:
        item = strArr[hri][hrj]
        if item == '-' and preclude != 'L':
            direction = 'R'
    if hlj >= 0:
        item = strArr[hli][hlj]
        if item == '-' and preclude != 'R':
            direction = 'L'
    if hui >= 0:
        item = strArr[hui][huj]
        if item == '|' and preclude != 'D':
            direction = 'U'
    if hdi < i:
        item = strArr[hdi][hdj]
        if item == '|' and preclude != 'U':
            direction = 'D'
    return direction

enders = ['<', '>', '^', 'v']
turners = ['o', '*']
longestLen = 1
longestCount = 1
for h in heads: 
    direction = ""
    length = 1
    nextItem = 'o'
    hi = h["i"]
    hj = h["j"]

    while nextItem not in enders:
      if nextItem in turners:
        preclude = direction if nextItem == '*' else None
        direction = getNextDir(hi, hj, preclude)
      hi, hj = getNextPos(hi,hj,direction)
      nextItem = strArr[hi][hj] 
      length += 1
    if length > longestLen:
        longestLen = length
        longestCount = 1
    elif length == longestLen:
        longestCount += 1

print("strArr is ", strArr, file=sys.stderr, flush=True)
print("heads is ", heads, file=sys.stderr, flush=True)

# test removing a head
"""
item = heads[0]
heads.remove(item)
print("heads after delete ", heads, file=sys.stderr, flush=True)
"""
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

# next steps:
# 1.  for each head
# 2.  find the initial direction by checking left cell and right cell (considering bounds) and seeing if there is a '-'
#  also check above and below for '|"
# 3.  keep going in the direction until a * or a tail depending on the direction 


print(longestLen)
print(longestCount)



""" 
refresher on multiline block comment - triple double quotes 

test cases 
7 7
.......
.......
.......
<-----o
.......
.......
.......
7
1

5 7
*-----*
|*---*|
||*-*||
|||.|||
vov.ovo
15
1

16 16
*--------------*
|*------------*|
||*----------*||
|||*--------*|||
||||*------*||||
|||||*----*|||||
||||||*--*||||||
|||||||o.|||||||
||||||||.|||||||
|||||||*-*||||||
||||||*---*|||||
|||||*-----*||||
||||*-------*|||
|||*---------*||
||*-----------*|
v*-------------*
254
1

legend: 
o - head
- - snake segment
| - vertical segment
v, <, >, ^ - snake heads
* curved part of snake 

most complex case

80 80
................................................................................
................................................................................
...o....................................................o.......................
...|....................................................|.......................
...|....................................................|.......................
...|....................................................|.......................
...|.................o->................................|.......................
...|....................................................|.......................
...*----->..............................................|.......................
........................................................|.......................
........................................................|.......................
.................................................o----->|.......................
........................................................v.......................
................................................................................
................................................................................
o-----------------------------------*...........................................
............................o------*|...........................................
......................^............||...........................................
......................|............||...........................................
....................o-*............||...........................................
...................................||...........................................
...................................||...........................................
...................................||...........................................
...................................||...........................................
...................................||...........................................
...................................||...........................................
...................................v|...........................................
....................................|...........................................
....................................|............................^^^^^^.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|.................*-----*....||||||.........
....................................|.................|*---*|....||||||.........
....................................|.................||o..||....||||||.........
....................................|.................|||..||....||||||.........
....................................|.................v|*--*|....||||||.........
....................................|..................*----*....||||||.........
....................................|............................||||||.........
....................................|............................||||||.........
....................................|............................o|||||.........
................<-----------------o.|.............................|||||.........
....................................|.............................|||||.........
..................................o.|.............................|||||.........
^.................................|.|.............................||o||.........
|.................................|.|.............................||.||.........
|.................................|.|.*------------*..............||.||.........
|.................................|.|.|*---------->|..............||.||.........
|..........o--------------------->|.|.||...........|..............||.||.........
|....o--------------------------->|.|.||...........|..............||.||.........
|..o----------------------------->|.|.||...........|..............o|.||.........
*--------------------------------o|.|.||...........|...............|.||.........
..................................|.|.||...........|...............|.||.........
..................................|.|.||...........|...............|.||.........
..................................|.|.||...........|...............|.||.........
..................................|.|.||...........|...............|.||.........
..................................|.|.v|...........|...............|.o|.........
..................................|.*--*...........|...............|..|.........
..................................*----------------*...............o..|.........
.............................................................o--------*.........
123
1
"""