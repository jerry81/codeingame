
def highest_req2(reqs,draw,discard,oppLoc,myLoc):
    dhsum = [0]*8
    if len(discard) == 0:
        discard = [0]*8
    if len(draw) == 0:
        draw = [0]*8

    forbidden = [oppLoc,myLoc]
    if oppLoc-1 < 0:
        forbidden.append(7)
    else:
        forbidden.append(oppLoc-1)
    if oppLoc+1 > 7:
        forbidden.append(0)
    else:
        forbidden.append(oppLoc+1)

    for i in range(8):
        dhsum[i] = (reqs[i] - (draw[i] + discard[i]))
    mi = 0
    mx = 0 
    for i in range(8):
        if dhsum[i] > mx and i not in forbidden:
            mi = i
            mx = dhsum[i]
    return mi

def next_lowest(oppLoc,myLoc):
    forbidden = [oppLoc,myLoc]
    if oppLoc-1 < 0:
        forbidden.append(7)
    else:
        forbidden.append(oppLoc-1)
    if oppLoc+1 > 7:
        forbidden.append(0)
    else:
        forbidden.append(oppLoc+1)
    for i in range(8):
        idx = (i + myLoc)%8
        if idx not in forbidden:
            return idx

reqs = [10,10,10,10,10,10,10,10,10]
draw =  [1, 0, 2, 2, 1, 1, 0, 1, 6, 9]
hand =  [0, 0, 0, 0, 0, 1, 8, 1, 1, 2]
# sum is [1,0,2,2,1,2,0,2]
# diff is [7,6,10,8,3,8,14,6]
print(f"expect 2 {next_lowest(reqs,draw,hand,4,1)}")
print(f"expect 2 {next_lowest(reqs,draw,hand,7,0)}")