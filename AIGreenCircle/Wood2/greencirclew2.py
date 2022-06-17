from collections import defaultdict
import sys
import math

# Complete the hackathon before your opponent by following the principles of Green IT

# game loop
applications = {}

while True:
    game_phase = input()  # can be MOVE, GIVE_CARD, THROW_CARD, PLAY_CARD or RELEASE
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
    print(f"applications is {applications}", file=sys.stderr, flush=True)
    for i in range(2):
        # player_location: id of the zone in which the player is located
        # player_permanent_daily_routine_cards: number of DAILY_ROUTINE the player has played. It allows them to take cards from the adjacent zones
        # player_permanent_architecture_study_cards: number of ARCHITECTURE_STUDY the player has played. It allows them to draw more cards
        player_location, player_score, player_permanent_daily_routine_cards, player_permanent_architecture_study_cards = [int(j) for j in input().split()]
        print(f"perma archi is {player_permanent_architecture_study_cards}", file=sys.stderr, flush=True)
        print(f"perma daily is {player_permanent_daily_routine_cards}", file=sys.stderr, flush=True)
    card_locations_count = int(input())
    cm = {"DRAW":[], "HAND": [], "DISCARD": [], "OPPONENT_CARDS": []}
    for i in range(card_locations_count):
        inputs = input().split()
        cards_location = inputs[0]  # the location of the card list. It can be HAND, DRAW, DISCARD or OPPONENT_CARDS (AUTOMATED and OPPONENT_AUTOMATED will appear in later leagues)
        print(f"location {cards_location}", file=sys.stderr, flush=True)
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

    print(f"pm is {pm}", file=sys.stderr, flush=True)
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)


    # In the first league: RANDOM | MOVE <zoneId> | RELEASE <applicationId> | WAIT; In later leagues: | GIVE <cardType> | THROW <cardType> | TRAINING | CODING | DAILY_ROUTINE | TASK_PRIORITIZATION <cardTypeToThrow> <cardTypeToTake> | ARCHITECTURE_STUDY | CONTINUOUS_DELIVERY <cardTypeToAutomate> | CODE_REVIEW | REFACTORING;
    if pm["MOVE 4"]:
        print("MOVE 4")
    else:
        print("RANDOM")
