import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
codes = {}
for i in range(n):
    inputs = input().split()
    b = inputs[0] # key 
    c = int(inputs[1]) # byte
    codes[b] = chr(c)
s = input()

sorted = {k: v for k,v in sorted(codes.items(), key=lambda item: len(item[0]))} 
# first step 
result = []
error = None
next_s = 0
while next_s < len(s):
  found = False
  for k,v in sorted.items():
      l = len(k)
      sub = s[next_s:next_s+l]
      if sub == k:
          result.append(v)
          next_s += l
          found = True
          print(f"match, sub is {sub} next_s is {next_s} result is {result}", file=sys.stderr, flush=True)
          break
  if not found:
    error = "DECODE FAIL AT INDEX " + str(next_s)
    break

print(f"result is {result}", file=sys.stderr, flush=True)
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
if error:
  print(error)
else:
  print(("").join(result))
