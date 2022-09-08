while True:
    try:
        alumni, dinners = [int(x) for x in input().strip().split(" ")]

        if dinners == 0 and alumni == 0:
            break

        v = [0] * alumni

        for i in range(0, dinners):
            presence = [int(x) for x in input().strip().split(" ")]
            # print(presence)
            for j in range(0, len(presence)):
                v[j] += presence[j]

        # print(v)

        perfect = False
        for a in v:
            if a == dinners:
                perfect = True

        if perfect:
            print("yes")
        else:
            print("no")

    except EOFError:
        break
