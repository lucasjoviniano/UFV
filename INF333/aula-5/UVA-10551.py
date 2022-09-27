def base_10(num, base):
    res = ''
    while num >= base:
        num, rem = divmod(num, base)
        res += str(rem)
    res += str(num)
    return res[::-1]

while True:
    line = input()
    if line == '0':
        break

    b, p, m = line.split()

    b = int(b)

    p = int(p, base=b)
    m = int(m, base=b)


    print(base_10(p % m, b))
