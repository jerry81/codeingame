import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

h = int(input())

buckets = []
sizes = []
total_size = 0

for i in range(h):
    a,b = input().split()
    a = int(a)
    b = int(b[0:len(b)-1]) # this removes the trailing %
    sizes.append(a)
    total_size += a*b/100

sizes.sort(reverse=True)

for size in sizes:
    if total_size > size:
        buckets.append("100%")
        total_size -= size
    else:
        proc = round(total_size/size*100)
        buckets.append(str(proc)+"%")
        break

for i in range(len(buckets)):
    print(str(sizes[i])+" "+buckets[i])


