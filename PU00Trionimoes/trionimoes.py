import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
x, y = [int(i) for i in input().split()]

# ideas
# 1.  simplify?  represent shapes with 01, 11 where 0 is the hole
# 2.  helper method to detect a fillable hole?
# 3.  "edge blocks" of 2x2 have limited choices
  # they always need to place the hole to the opposite direction of the corner it is in
  # unless they have the one hole specified in the input 
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("+--+")

for i in range(n):

    # Write an answer using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    print("|  |\n+--+")
