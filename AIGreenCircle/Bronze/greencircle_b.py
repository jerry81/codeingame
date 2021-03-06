from collections import defaultdict
import sys

# Complete the hackathon before your opponent by following the principles of Green IT
def get_tech_debt(hand,req):
    bonus_cards = hand[-2]
    tech_debt = sum(req)
    diff = []
    for i in range(8):
        diff.append(max((req[i] - (hand[i] * 2)),0))
    tech_debt = max((sum(diff) - bonus_cards) ,0)
    return tech_debt


def get_best(rm):
    items_sorted = {k: v for k, v in sorted(rm.items(), key=lambda item: item[1])}
    if (len(list(items_sorted.keys())) == 0):
        return None
    return list(items_sorted.keys())[0]

def get_rc(cm):
    k = list(cm.keys())
    # map and filter
    mapped = list(map(lambda x: x.split("RELEASE "),k))
    filtered = list(filter(lambda x: len(x) > 1,mapped))
    processed = list(map(lambda x: x[1], filtered))
    return processed

def next_lowest(oppLoc,myLoc):
    forbidden = [oppLoc,myLoc]
    if oppLoc == -1:
        return 0
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

def app_summary(app):
  summary = [0]*8
  lists = list(app.values())
  for l in lists:
    for idx,k in enumerate(l):
        summary[idx] += k
  return summary 

def handle_move(amax):
    print(f"amax is {amax}", file=sys.stderr, flush=True)
    if pm[f"MOVE {amax}"]:
        print(f"MOVE {amax}")
    else:
        print("RANDOM")

def has_ci(pm):
    possible_keys = list(pm.keys())
    continuous = list(filter(lambda y: len(y) > 1, list(map(lambda x: x.split("CONTINUOUS_INTEGRATION "), possible_keys))))
    possible_idxs = list(map(lambda a: a[1],continuous))
    return len(possible_idxs) > 1

def get_possible_task_prioritizations(pm):
    possible_keys = list(pm.keys())
    tp = list(filter(lambda y: len(y) > 1, list(map(lambda x: x.split("TASK_PRIORITIZATION "), possible_keys))))
    indexes = list(map(lambda a: a[1].split(" "),tp))
    return indexes

def get_best_task_prioritization(indexes, requirements, cards):
    draw = cards["DRAW"]
    discard = cards["DISCARD"]
    automated = cards["AUTOMATED"]
    if len(draw) == 0:
        draw = [0] * 8 
    if len(discard) == 0:
        discard = [0] * 8
    if len(automated) == 0:
        automated = [0] * 8
    req_sum = [0] * 8
    hand_sum = [0] * 8
    for i in requirements.values():
        for idx,j in enumerate(i):
            req_sum[idx] += j
    for i in range(8):
      hand_sum[i] += draw[i]
      hand_sum[i] += discard[i]
      hand_sum[i] += automated[i]
    diff = [0] * 8
    for i in range(8):
        diff[i] = req_sum[i] - (2*hand_sum[i])
    best_indexes = sorted(range(len(diff)), key=lambda k: diff[k], reverse = True)
    best_indexes.append(8)
    for i in range(9):
        j = 8 - i
        worst = best_indexes[j]
        for k in range(9):
            best = best_indexes[k]
            if [str(worst), str(best)] in indexes:
                return f"TASK_PRIORITIZATION {worst} {best}"
    return "RANDOM"

def handle_play(pm, ci = [], apps = [], cm = {}):
    tps = get_possible_task_prioritizations(pm)
    if pm[f"REFACTORING"]:
        print(f"REFACTORING")
    elif pm[f"CODE_REVIEW"]:
        print(f"CODE_REVIEW")
    elif has_ci(pm): # needs special handling 
    #     print(f"CONTINUOUS_DELIVERY")
      cim = get_best_ci(apps,ci)
      print(get_best_possible_ci(pm,cim))
    elif pm[f"ARCHITECTURE_STUDY"]:
        print(f"ARCHITECTURE_STUDY")
    elif len(tps) > 0:
        print(get_best_task_prioritization(tps, apps,cm))
    else:
        print("RANDOM")

def handle_throw(pm):
    if pm[f"THROW 8"]:
        print(f"THROW 8")
    elif pm[f"THROW 0"]:
        print(f"THROW 0")
    elif pm[f"THROW 1"]:
        print(f"THROW 1")
    elif pm[f"THROW 2"]:
        print(f"THROW 2")
    elif pm[f"THROW 3"]:
        print(f"THROW 3")
    elif pm[f"THROW 5"]:
        print(f"THROW 5")
    else:
        print("RANDOM")

# game loop
turn_count = 0
while True:
    applications = {}
    game_phase = input()  # can be MOVE, GIVE_CARD, THROW_CARD, PLAY_CARD or RELEASE
    print(f"gamePhase is {game_phase}", file=sys.stderr, flush=True)
    applications_count = int(input())
    for i in range(applications_count):
          inputs = input().split()
          object_type = inputs[0]
          _id = int(inputs[1])
          applications[_id] = []
          training_needed = int(inputs[2])  # number of TRAINING skills needed to release this application
          applications[_id].append(training_needed)
          coding_needed = int(inputs[3])  # number of CODING skills needed to release this application
          applications[_id].append(coding_needed)
          daily_routine_needed = int(inputs[4])  # number of DAILY_ROUTINE skills needed to release this application
          applications[_id].append(daily_routine_needed)
          task_prioritization_needed = int(inputs[5])  # number of TASK_PRIORITIZATION skills needed to release this application
          applications[_id].append(task_prioritization_needed)
          architecture_study_needed = int(inputs[6])  # number of ARCHITECTURE_STUDY skills needed to release this application
          applications[_id].append(architecture_study_needed)
          continuous_delivery_needed = int(inputs[7])  # number of CONTINUOUS_DELIVERY skills needed to release this application
          applications[_id].append(continuous_delivery_needed)
          code_review_needed = int(inputs[8])  # number of CODE_REVIEW skills needed to release this application
          applications[_id].append(code_review_needed)
          refactoring_needed = int(inputs[9])  # number of REFACTORING skills needed to release this application
          applications[_id].append(refactoring_needed)
    my_loc = "UNKNOWN"
    opponent_loc = "UNKNOWN"
    perma_a = 0
    perma_d = 0
    for i in range(2):
        # player_location: id of the zone in which the player is located
        # player_permanent_daily_routine_cards: number of DAILY_ROUTINE the player has played. It allows them to take cards from the adjacent zones
        # player_permanent_architecture_study_cards: number of ARCHITECTURE_STUDY the player has played. It allows them to draw more cards
        player_location, player_score, player_permanent_daily_routine_cards, player_permanent_architecture_study_cards = [int(j) for j in input().split()]
        if i==1:
            opponent_loc = player_location
        else:
            my_loc = player_location
            perma_a = player_permanent_architecture_study_cards
            perma_d = player_permanent_daily_routine_cards
    
    print(f"opponent_loc is {opponent_loc}", file=sys.stderr, flush=True)
    card_locations_count = int(input())
    cm = {"DRAW":[], "HAND": [], "DISCARD": [], "OPPONENT_CARDS": [], "PLAYED_CARDS": [], "AUTOMATED": [], "OPPONENT_AUTOMATED": []}
    for i in range(card_locations_count):
        inputs = input().split()
        cards_location = inputs[0]  # the location of the card list. It can be HAND, DRAW, DISCARD or OPPONENT_CARDS (AUTOMATED and OPPONENT_AUTOMATED will appear in later leagues)
        training_cards_count = int(inputs[1])
        cm[cards_location].append(training_cards_count)
        coding_cards_count = int(inputs[2])
        cm[cards_location].append(coding_cards_count)
        daily_routine_cards_count = int(inputs[3])
        cm[cards_location].append(daily_routine_cards_count)
        task_prioritization_cards_count = int(inputs[4])
        cm[cards_location].append(task_prioritization_cards_count)
        architecture_study_cards_count = int(inputs[5])
        cm[cards_location].append(architecture_study_cards_count)
        continuous_delivery_cards_count = int(inputs[6])
        cm[cards_location].append(continuous_delivery_cards_count)
        code_review_cards_count = int(inputs[7])
        cm[cards_location].append(code_review_cards_count)
        refactoring_cards_count = int(inputs[8])
        cm[cards_location].append(refactoring_cards_count)
        bonus_cards_count = int(inputs[9])
        cm[cards_location].append(bonus_cards_count)
        technical_debt_cards_count = int(inputs[10])
        cm[cards_location].append(technical_debt_cards_count)
    for c in cm.items():
      print(f"cm is {c}", file=sys.stderr, flush=True)
    asum = app_summary(applications)
    amax = next_lowest(opponent_loc,my_loc)
    possible_moves_count = int(input())
    pm = defaultdict(bool)
    for i in range(possible_moves_count):
        possible_move = input()
        pm[possible_move] = True
    rc = get_rc(pm)
    for i in pm.items():
      print(f"pm is {i}", file=sys.stderr, flush=True)
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # In the first league: RANDOM | MOVE <zoneId> | RELEASE <applicationId> | WAIT; In later leagues: | GIVE <cardType> | THROW <cardType> | TRAINING | CODING | DAILY_ROUTINE | TASK_PRIORITIZATION <cardTypeToThrow> <cardTypeToTake> | ARCHITECTURE_STUDY | CONTINUOUS_DELIVERY <cardTypeToAutomate> | CODE_REVIEW | REFACTORING;
    rm = {}
    print(f"perma a is {perma_a}", file=sys.stderr, flush=True)
    print(f"perma d is {perma_d}", file=sys.stderr, flush=True)
    for r in rc:
        rm[r] = get_tech_debt(cm["HAND"],applications[int(r)])
    for i in rm.items():
      print(f"rm is {i}", file=sys.stderr, flush=True)
    optimized = get_best(rm)
    print(f"optmized is {optimized}", file=sys.stderr, flush=True)
    if optimized is not None:
         print(f"tech is is {rm[optimized]}", file=sys.stderr, flush=True)
    print(f"amax is {amax}", file=sys.stderr, flush=True)

    if game_phase == "MOVE":
        handle_move(amax)
    elif game_phase == "PLAY_CARD":
        handle_play(pm,cm["AUTOMATED"],applications,cm)
    elif game_phase == "THROW_CARD":
        handle_throw(pm)
    else:
        if optimized is not None:
          print(f"RELEASE {optimized}")
        else: 
          print("RANDOM")

