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