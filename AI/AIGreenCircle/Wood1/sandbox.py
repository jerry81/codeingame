
def highest_req2(reqs,draw,hand,oppLoc):
    dhsum = [0]*8
    forbidden = [oppLoc]
    if oppLoc-1 < 0:
        forbidden.append(7)
    else:
        forbidden.append(oppLoc-1)
    if oppLoc+1 > 7:
        forbidden.append(0)
    else:
        forbidden.append(oppLoc+1)

    print(f'forbidden is {forbidden}')
    for i in range(8):
        dhsum[i] = (reqs[i] - (draw[i] + hand[i]))
    mi = 0
    mx = 0 
    for i in range(8):
        if dhsum[i] > mx and i not in forbidden:
            mi = i
            mx = dhsum[i]
    return mi

draw =  [1, 0, 2, 2, 1, 1, 0, 1, 6, 9]
hand =  [0, 0, 0, 0, 0, 1, 8, 1, 1, 2]
# sum is [1,0,2,2,1,2,0,2]
# diff is [7,6,10,8,3,8,14,6]
print(f"expect 2 {highest_req2(reqs,draw,hand,1)}")