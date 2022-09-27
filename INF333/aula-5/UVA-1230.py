c = int(input())

for _ in range(c):
    x, y, n = [int(x) for x in input().split()]
    print("%d" %(pow(x, y, mod=n)))
