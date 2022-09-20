while True:
    try:
        n, *line = [int(x) for x in input().strip().split(" ")]
        if n == 1:
            print("Jolly")
            continue

        nums = []
        is_jolly = True
        for key, value in enumerate(line[:-1]):
            diff = abs(line[key] - line[key + 1])
            if diff >= n or diff == 0 or diff in nums:
                is_jolly = False
                break
            else:
                nums.append(diff)

        if is_jolly:
            print("Jolly")
        else:
            print("Not jolly")

    except EOFError:
        break
