def get_minutes(time: str):
    hh, mm = [x.strip() for x in time.split(":")]

    return int(hh) * 60 + int(mm)


day = 1

while True:
    try:
        n = int(input().strip())
        secs = []

        for i in range(0, n):
            line = input().strip().split(" ")
            secs.append(get_minutes(line[0]))
            secs.append(get_minutes(line[1]))

        secs = [60 * 10] + secs
        secs.append(18 * 60)
        secs.sort()

        diffs = []

        for i in range(0, len(secs) - 1, 2):
            diffs.append(secs[i + 1] - secs[i])

        nap_time = max(diffs)
        start = secs[diffs.index(nap_time) * 2]

        if nap_time >= 60:
            print(
                "Day #{}: the longest nap starts at {}:{:>02} and will last for {} hours and {} minutes.".format(
                    day, start // 60, start % 60, nap_time // 60, nap_time % 60
                )
            )
        else:
            print(
                "Day #{}: the longest nap starts at {}:{:>02} and will last for {} minutes.".format(
                    day, start // 60, start % 60, nap_time
                )
            )

        day += 1

    except EOFError:
        break
