def crivo(n):
    sieve = [True for i in range(n + 1)]


while True:
    try:
        l, u = [int(x) for x in input().split()]

    except IOError:
        break
