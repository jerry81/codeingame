import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
fizzIdxes = []
buzzIdxes = []
allIdxes = []
for i in range(n):
    line = input()
    if (line == 'fizz'):
         print(f"fizz is {i}", file=sys.stderr, flush=True)
         fizzIdxes.append(i)
         allIdxes.append({i:line})
    print(f"fizz is {i}", file=sys.stderr, flush=True)
        


# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("fizz buzz")
