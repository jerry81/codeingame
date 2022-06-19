
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
    if myLoc == -1:
        forbidden = [oppLoc]
        myLoc = 0
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
print(f"expect 2 {next_lowest(4,1)}")
print(f"expect 2 {next_lowest(7,0)}")
print(f"expect 3 {next_lowest(1,-1)}")

def get_best_ci(applications,automated):

    if len(automated) == 0:
        automated = [0] * 8
    appsum = [0]*8 
    for v in applications.values():
        for idx, val in enumerate(v):
          appsum[idx] += val
    for i,v in enumerate(appsum):
      appsum[i] = appsum[i] - (automated[i] * 2)
    return appsum
    # return sorted(range(len(appsum)), key=lambda k: appsum[k], reverse = True)

def get_best_possible_ci(pm,cimap):
    possible_keys = list(pm.keys())
    continuous = list(filter(lambda y: len(y) > 1, list(map(lambda x: x.split("CONTINUOUS_INTEGRATION "), possible_keys))))
    possible_idxs = list(map(lambda a: a[1],continuous))
    best = 0 
    bestv = 0 
    for i in possible_idxs:
        if i == '8':
            if bestv < 2:
                bestv = 2
                best = int(i)
        else:
          v = cimap[int(i)]
          if v > bestv:
            bestv = v 
            best = int(i)
    return f"CONTINUOUS_INTEGRATION {str(best)}"


def has_ci(pm):
    possible_keys = list(pm.keys())
    continuous = list(filter(lambda y: len(y) > 1, list(map(lambda x: x.split("CONTINUOUS_INTEGRATION "), possible_keys))))
    possible_idxs = list(map(lambda a: a[1],continuous))
    return len(possible_idxs) > 1

pm = {'TASK_PRIORITIZATION 8 0': True, 'TASK_PRIORITIZATION 8 1': True, 'TASK_PRIORITIZATION 8 2': True, 'TASK_PRIORITIZATION 8 3': True, 'TASK_PRIORITIZATION 8 4': True, 'TASK_PRIORITIZATION 8 5': True, 'TASK_PRIORITIZATION 8 6': True, 'TASK_PRIORITIZATION 8 7': True, 'TASK_PRIORITIZATION 5 0': True, 'TASK_PRIORITIZATION 5 1': True, 'TASK_PRIORITIZATION 5 2': True, 'TASK_PRIORITIZATION 5 3': True, 'TASK_PRIORITIZATION 5 4': True, 'TASK_PRIORITIZATION 5 5': True, 'TASK_PRIORITIZATION 5 6': True, 'TASK_PRIORITIZATION 5 7': True, 'CONTINUOUS_INTEGRATION 8': True, 'CONTINUOUS_INTEGRATION 3': True, 'RELEASE 8': True, 'RANDOM': True, 'WAIT': True}
applications = {3: [4, 0, 0, 0, 4, 0, 0, 0], 7: [0, 4, 4, 0, 0, 0, 0, 0], 12: [0, 4, 0, 0, 0, 0, 0, 4], 18: [0, 0, 0, 4, 4, 0, 0, 0], 10: [0, 4, 0, 0, 0, 4, 0, 0], 17: [0, 0, 4, 0, 0, 0, 0, 4], 26: [0, 0, 0, 0, 0, 4, 0, 4], 6: [4, 0, 0, 0, 0, 0, 0, 4], 16: [0, 0, 4, 0, 0, 0, 4, 0], 8: [0, 4, 0, 4, 0, 0, 0, 0], 14: [0, 0, 4, 0, 4, 0, 0, 0]}
automated = [0, 0, 0, 2, 0, 0, 0, 0, 0, 0]

print(f"expect [1,2,7,4,0,5,3,6] {get_best_ci(applications, [])}")
print(f"expect [1,2,7,4,0,5,3,6] {get_best_ci(applications, automated)}")
best_map = get_best_ci(applications, [])
best_ci = get_best_possible_ci(pm,best_map)
print(f"best ci is {best_ci}")
print(f"expect yes {has_ci(pm)}")
print(f"expect no {has_ci( {'TASK_PRIORITIZATION 8 0': True})}")