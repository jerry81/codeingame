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
print(f"sorted is #{sorted}", file=sys.stderr, flush=True)

# first step 
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("abracadabra")
