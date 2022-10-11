while True:
    try:
        n, m = [int(x) for x in input().split()]
        if n == 0 and m == 0:
            break

        jack = set()
        jill = set()

        for i in range(n):
            jack.add(int(input()))

        for i in range(m):
            jill.add(int(input()))

        print(len(jack.intersection(jill)))


    except IOError:
        break
