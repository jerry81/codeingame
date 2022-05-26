import sys
import re

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
    lookup[name] = { "s": int(start_idx), "v": values }
x = input()
split_input = x.split('[')
name = split_input[0]
rest = split_input[1]
split_input = rest.split(']')
print(f"name is {name} spl {split_input} and lookup is {lookup}", file=sys.stderr, flush=True)
idx = int(split_input[0])
print(f"name is {name} split input is now {split_input}", file=sys.stderr, flush=True)
entry = lookup[name]
arr = entry["v"]
offset = entry["s"]
print(f"idx is {idx} offset {offset}", file=sys.stderr, flush=True)
idx = abs(offset - idx)
print(arr[idx])
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

