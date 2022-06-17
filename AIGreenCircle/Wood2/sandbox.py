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