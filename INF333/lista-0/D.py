while True:
    try:
        A, D = [int(x) for x in input().strip().split(' ')]

        if A == 0 and D == 0:
            break

        attk_players = [int(x) for x in input().strip().split(' ')]
        defd_players = [int(x) for x in input().strip().split(' ')]

        attk_players.sort()
        defd_players.sort()

        print('Y' if attk_players[0] < defd_players[1] else 'N')

    except EOFError:
        break