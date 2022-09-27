from fractions import Fraction

n = int(input())

for _ in range(n):
    p, q = [int(x) for x in input().split()[::2]]
    f = Fraction(p, q)

    print("%d / %d" % (f.numerator, f.denominator))
