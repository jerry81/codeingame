import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def dist(lona, lonb, lata, latb):
    x = (lonb - lona) * math.cos(((lata + latb) / 2.0))
    y = latb - lata
    return math.sqrt((x**2 + y**2)) * 6371

lon = input() # ulon
lat = input() # ulat
lonF = ".".join(lon.split(','))
latF = ".".join(lat.split(','))
print("lonF is ", lonF , file=sys.stderr, flush=True)
smallestDist = None
smallestName = ""
n = int(input())
defibmap = {}
for i in range(n):
    defib = input()
    arr = defib.split(';')
    lonD = arr[4]
    latD = arr[5]
    lonDf = ".".join(lonD.split(','))
    latDf = ".".join(latD.split(','))
    distToUser = dist(float(lonF), float(lonDf), float(latF), float(latDf))
   
    if (smallestDist == None) or (smallestDist > distToUser):
        smallestDist = distToUser
        smallestName = arr[1]
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(smallestName)
