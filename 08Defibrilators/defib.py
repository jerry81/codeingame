import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def dist(lona, lonb, lata, latb):
    x = (lonb - lona) * math.cos(((lata + latb) / 2))
    y = latb - lata
    return math.sqrt((x**2 + y**2) * 6371)

lon = input() # ulon
lat = input() # ulat
smallestDist = None
smallestName = ""
n = int(input())
defibmap = {}
for i in range(n):
    defib = input()
    arr = defib.split(';')
    defibmap[arr[1]] = { lon: arr[4], lat: arr[5] }
    distToUser = dist(lon, lat, arr[4], arr[5])
   
    if (smallestDist == None) or (smallestDist > distToUser):
        smallestDist = distToUser
        smallestName = arr[1]
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(smallestName)
