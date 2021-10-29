import math

p = 0

while p * p < math.sqrt(9223372036854775807):
    p += 1

print(p - 1)
