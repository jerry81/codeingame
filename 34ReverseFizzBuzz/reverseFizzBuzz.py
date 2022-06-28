from collections import defaultdict
import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
fizzIdxes = []
buzzIdxes = []
allIdxes = defaultdict(lambda: -1)
fizzBuzzI = []
for i in range(n):
    line = input()
    if (line == 'Fizz'):
         print(f"fizz is {i}", file=sys.stderr, flush=True)
         fizzIdxes.append(i)
    elif (line == 'Buzz'):
         print(f"buzz is {i}", file=sys.stderr, flush=True)
         buzzIdxes.append(i)
    elif (line == 'FizzBuzz'):
        fizzBuzzI.append(i)
    else: 
        allIdxes[i] = int(line)
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
if len(fizzIdxes) == 1:
    idx = fizzIdxes[0]
    prevItem = allIdxes[idx-1]
    print(f"prevItem is {prevItem}", file=sys.stderr, flush=True)
    if prevItem is int and prevItem > -1: #!= "Fizz" and prevItem != "Buzz" and prevItem != "FizzBuzz":
        print(f"prevItem is {prevItem}", file=sys.stderr, flush=True)
        f = prevItem + 1
    nextItem = allIdxes[idx+1]
    if nextItem is int and nextItem > 0:# != "Fizz" and nextItem != "Buzz" and nextItem != "FizzBuzz":
        print(f"shouldnt be here is {prevItem}", file=sys.stderr, flush=True)
        f = nextItem - 1
if len(buzzIdxes) == 1:
    idx = buzzIdxes[0]
    prevItem = allIdxes[idx-1]
    if prevItem is int and prevItem > -1: # != "Fizz" and prevItem != "Buzz" and prevItem != "FizzBuzz":
        b = prevItem + 1
    nextItem = allIdxes[idx+1]
    if nextItem is int and nextItem > 0: # != "Fizz" and nextItem != "Buzz" and nextItem != "FizzBuzz":
        b = nextItem - 1
    
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(f"{f} {b}")
