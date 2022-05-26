import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
lookup = {}
n = int(input())
for i in range(n):
    assignment = input()
    split_arr = assignment.split('[')
    name = split_arr[0]
    rest = split_arr[1]
    split_arr = rest.split(']')
    indicies = split_arr[0]
    rest = split_arr[1]
    split_arr = rest.split('=')
    values = split_arr[1].strip().split(" ")
    start_idx = indicies.split('..')[0]
    lookup[name] = { "s": start_idx, "v": values }
    print(f"lookup is now  is {lookup}", file=sys.stderr, flush=True)

x = input()

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("0")
