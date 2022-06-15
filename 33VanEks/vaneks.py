from collections import defaultdict
import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

a1 = int(input())
n = int(input())

memo = {}
for i in range(n-1):
  try: 
    lastIdx = memo[a1]
    a1 = i - lastIdx
  except:
    memo[a1] = i
    a1 = 0
  
print(a1)
# 0, 0, 1, 0, 2, 0, 2, 2, 1, 6,

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

