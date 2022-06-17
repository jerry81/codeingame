def get_tech_debt(hand,req):
    bonus_cards = hand[-2]
    tech_debt = sum(req)
    diff = []
    for i in range(7):
        diff.append(max((req[i] - hand[i]),0))
    tech_debt = max((sum(diff) - bonus_cards) ,0)
    return tech_debt

hand = [0, 1, 0, 0, 0, 0, 0, 1, 3, 0] # last 2 - bonus, tech debt 
req = [0, 0, 2, 0, 0, 2, 2, 0]
expect = 3
print(f"expect {expect} {get_tech_debt(hand,req)}")

def get_rc(cm):
    k = list(cm.keys())
    # map and filter
    mapped = list(map(lambda x: x.split("RELEASE"),k))
    filtered = list(filter(lambda x: len(x) > 1,mapped))
    processed = list(map(lambda x: x[1], filtered))
    return processed

cm = {'RELEASE 5': True, 'RELEASE 6': True, 'RELEASE 12': True, 'RELEASE 8': True, \
      'RELEASE 11': True, 'RELEASE 15': True, 'RELEASE 2': True, 'RELEASE 3': True, \
      'RELEASE 17': True, 'RANDOM': True, 'WAIT': True}

expect = [5,6,12,8,11,15,2,3,17]

print(f"expect {expect} {get_rc(cm)}")

def get_best(rm):
    items_sorted = {k: v for k, v in sorted(rm.items(), key=lambda item: item[1])}
    print(f"items_sorted is {items_sorted}")
    return list(items_sorted.keys())[0]

rm = {'16': 5, '13': 2, '1': 2, '21': 5, '4': 4, '14': 6, '6': 5}
expect = 13

print(f"expect {expect} {get_best(rm)}")

def app_summary(app):
  summary = [0]*8
  lists = list(app.values())
  for l in lists:
    for idx,k in enumerate(l):
        print(f'idx is {idx}')
        print(f'k is {k}')
        summary[idx] += k
  return summary 

applications =  {21: [0, 2, 2, 0, 0, 2, 0, 0], 23: [2, 0, 0, 2, 0, 0, 0, 2], 16: [2, 0, 0, 0, 0, 2, 2, 0], 20: [0, 0, 0, 2, 0, 0, 2, 2], 2: [0, 0, 2, 0, 0, 0, 2, 2], 5: [0, 0, 2, 2, 0, 2, 0, 0], 6: [0, 0, 2, 0, 0, 2, 2, 0], 13: [0, 0, 0, 0, 2, 0, 2, 2], 25: [2, 2, 0, 0, 2, 0, 0, 0], 3: [0, 2, 2, 2, 0, 0, 0, 0], 9: [2, 0, 2, 0, 0, 0, 2, 0], 24: [0, 0, 0, 2, 0, 2, 2, 0]}
expect = ['sum', 'sum2', 'sum3...']
print(f"expect {expect} {app_summary(applications)}")

def highest_req(reqs):
    mi = 0
    mx = 0 
    for i in range(len(reqs)):
        if reqs[i] > mx:
            mi = i
            mx = reqs[i]
    return mi

reqs = [8, 6, 12, 10, 4, 10, 14, 8]
expect = 6
print(f"expect {expect} {highest_req(reqs)}")