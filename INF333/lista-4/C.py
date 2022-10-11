while True:
    n = int(input())

    if n == 0:
        break

    ans = 1
    for i in range(n + 2, 2 * n + 1):
        ans *= i

    print(ans)
