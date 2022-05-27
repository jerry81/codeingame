import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

number_snails = int(input())
snails = {}
for i in range(number_snails):
    speed_snail = int(input())
    snails[i+1] = {"s": speed_snail}
goals = []
map_height = int(input())
map_width = int(input())
for i in range(map_height):
    row = input()
    for j in range(map_width):
        c = row[j]
        if c == '#':
            goals.append({'x':j,'y':i})
        elif c != '*':
            snail = snails[int(c)]
            snail['x'] = j
            snail['y'] = i

print(f"snails are {snails}", file=sys.stderr, flush=True)
print(f"goals are {goals}", file=sys.stderr, flush=True)

print("winner is number")
