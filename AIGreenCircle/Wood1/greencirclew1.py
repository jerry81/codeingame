from collections import defaultdict
import sys
import math

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

def highest_req(reqs):
    mi = 0
    mx = 0 
    for i in range(len(reqs)):
        if reqs[i] > mx:
            mi = i
            mx = reqs[i]
    return mi

def app_summary(app):
  summary = [0]*8
  lists = list(app.values())
  for l in lists:
    for idx,k in enumerate(l):
        summary[idx] += k
  return summary 

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
    for a in list(applications.items()):
      print(f"applications is {a}", file=sys.stderr, flush=True)
    asum = app_summary(applications)
    amax = highest_req(asum)
    for i in range(2):
        # player_location: id of the zone in which the player is located
        # player_permanent_daily_routine_cards: number of DAILY_ROUTINE the player has played. It allows them to take cards from the adjacent zones
        # player_permanent_architecture_study_cards: number of ARCHITECTURE_STUDY the player has played. It allows them to draw more cards
        player_location, player_score, player_permanent_daily_routine_cards, player_permanent_architecture_study_cards = [int(j) for j in input().split()]
    card_locations_count = int(input())
    cm = {"DRAW":[], "HAND": [], "DISCARD": [], "OPPONENT_CARDS": [], "PLAYED_CARDS": []}
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
    print(f"cm is {cm}", file=sys.stderr, flush=True)

    possible_moves_count = int(input())
    pm = defaultdict(bool)
    for i in range(possible_moves_count):
        possible_move = input()
        pm[possible_move] = True
    rc = get_rc(pm)
    print(f"pm is {pm}", file=sys.stderr, flush=True)
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # In the first league: RANDOM | MOVE <zoneId> | RELEASE <applicationId> | WAIT; In later leagues: | GIVE <cardType> | THROW <cardType> | TRAINING | CODING | DAILY_ROUTINE | TASK_PRIORITIZATION <cardTypeToThrow> <cardTypeToTake> | ARCHITECTURE_STUDY | CONTINUOUS_DELIVERY <cardTypeToAutomate> | CODE_REVIEW | REFACTORING;
    rm = {}
    for r in rc:
        rm[r] = get_tech_debt(cm["HAND"],applications[int(r)])
    print(f"rm is {rm}", file=sys.stderr, flush=True)
    optimized = get_best(rm)
    print(f"optmized is {optimized}", file=sys.stderr, flush=True)
    if optimized is not None:
         print(f"tech is is {rm[optimized]}", file=sys.stderr, flush=True)
    print(f"amax is {amax}", file=sys.stderr, flush=True)
    if pm[f"MOVE {amax}"]:
        print(f"MOVE {amax}")
    else:
        # if turn_count < 1:
        #   if pm["WAIT"]:
        #     turn_count+=1
        #     print("WAIT")
        #   else: 
        #     if optimized is not None:
        #       print(f"RELEASE {optimized}")
        #     else: 
        #       print("RANDOM")
        # else:
        # turn_count = 0
          if optimized is not None:
            print(f"RELEASE {optimized}")
          else: 
            print("RANDOM")

