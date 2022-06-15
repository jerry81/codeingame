from collections import defaultdict
import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

a1 = int(input())
n = int(input())

memo = defaultdict(int)
for i in range(n):
  print(f"memo[i] {memo[i]}", file=sys.stderr, flush=True)
  memo[i] = i 
  

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("answer")
