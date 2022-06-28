import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
fizzIdxes = []
buzzIdxes = []
allIdxes = []
fizzBuzzI = []
for i in range(n):
    line = input()
    if (line == 'Fizz'):
         print(f"fizz is {i}", file=sys.stderr, flush=True)
         fizzIdxes.append(i)
    if (line == 'Buzz'):
         print(f"buzz is {i}", file=sys.stderr, flush=True)
         buzzIdxes.append(i)
    if (line == 'FizzBuzz'):
        fizzBuzzI.append(i)
    allIdxes.append({i:line})
print(f"fizzIdxes is {fizzIdxes}", file=sys.stderr, flush=True)
print(f"buzzIdxes is {buzzIdxes}", file=sys.stderr, flush=True)
print(f"all is {allIdxes}", file=sys.stderr, flush=True)
f = -1
b = -1
if len(fizzIdxes) >= 2:
    f = fizzIdxes[1] - fizzIdxes[0]
if len(buzzIdxes) >= 2:
    b = buzzIdxes[1] - buzzIdxes[0]
if len(buzzIdxes) == 0 and len(fizzBuzzI) >= 2:
    b = fizzBuzzI[1] - fizzBuzzI[0]
if len(fizzIdxes) == 0 and len(fizzBuzzI) >= 2:
    f = fizzBuzzI[1] - fizzBuzzI[0]

    
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(f"{f} {b}")
