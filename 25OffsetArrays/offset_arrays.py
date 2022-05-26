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

print(f"spl {split_input}", file=sys.stderr, flush=True)
l = len(split_input)
print(f"len is {len(split_input) }", file=sys.stderr, flush=True)
# handle nesting 
stack = split_input[:l-1]
last = split_input[l-1]
idx = int(last.split(']')[0])
# until split_input only has 1 item left 
cur_num = idx
while len(stack) > 0:
  name = stack.pop()
  entry = lookup[name]
  arr = entry["v"]
  offset = entry["s"]
  idx = abs(offset - idx)
  cur_num = arr[idx]
print(cur_num)
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

