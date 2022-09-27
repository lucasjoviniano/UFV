cont = 1

while True:
    a, b = [int(x) for x in input().split(" ")]

    if a == 0 and b == 0:
        break

    result = 0
    for _ in range(a):
        result += int(input())

    print("Bill #%d costs %d: each friend should pay %d" % (cont, result, result // b))
    print()
    cont += 1
