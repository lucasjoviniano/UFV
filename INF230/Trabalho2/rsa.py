import itertools
import random
import sys
from typing import Iterable, Tuple, TypeVar

T = TypeVar("T")

MAX_INT = (2 ** 31) - 1


def main():

    if sys.argv[1] == 'gerar':
        p, q = generate_keys()

        n: int = p * q

        phi: int = (p - 1) * (q - 1)

        e: int = get_e(phi)

        d: int = get_d(e, phi)

        print("E: {}, D: {}, N: {}".format(e, d, n))

    elif sys.argv[1] == 'codificar':

        mensagem, n, e = sys.argv[2], int(sys.argv[3]), int(sys.argv[4])

        coded = encode(mensagem, n, e)

        print(str(coded)[1:-1])

    elif sys.argv[1] == 'decodificar':
        mensagem, n, d = "1634805184089914118, 437016238775307267, 2458304341065466193", 2752537950741231113, 492940772177008613

        decoded = decode([x.strip() for x in mensagem.split(',')], int(d), int(n))

        print(decoded)


    message: str = 'TAYLORSWIFTRAINHADOPOP'
    #
    #
    #
    # coded = encode(message, n, e)
    #
    # print("Mensagem Codificada: {}".format(coded))
    #
    # decoded = decode(coded, d, n)
    #
    # print("Mensagem Decodificada: {}".format(decoded))
    #
    # signed = sign(message, d, n)
    #
    # print("Mensagem Assinada: {}".format(signed))
    #
    # unsigned = check_sign(signed, e, n)
    #
    # print("Mensagem Conferida: {}".format(unsigned))


def get_e(phi: int) -> int:

    while True:
        number = random.randint(0, MAX_INT)
        if is_coprime(number, phi):
            return number


def get_d(e: int, phi: int) -> int:
    rest, s, t = extended_mdc(e, phi)

    if s < 0:
        return s + phi

    return s


def sign(message, d, n):
    block_size = get_block_size(n)

    blocks = generate_message_blocks(message, block_size)

    return [mod_pow(int(x), d, n) for x in blocks]


def check_sign(message, e, n):
    codes = [str(mod_pow(int(x), e, n)) for x in message]
    message = ''

    for i, k in enumerate(codes):
        if len(k) % 2 != 0:
            codes[i] = '0' + k

    for k in codes:
        for a, b in grouped(k):
            message += get_char_from_code(a + b)

    return message


def encode(message: str, key: int, e: int) -> [str]:
    block_size = get_block_size(key)

    blocks = generate_message_blocks(message, block_size)

    return [mod_pow(int(x), e, key) for x in blocks]


def generate_message_blocks(message, block_size):
    k = 0
    blocks = []

    for _ in message:
        block = []
        while len(block) < block_size and k < len(message):
            block.append(get_char_code(message[k]))
            k += 1

        blocks.append(''.join(block))

    blocks = list(filter(None, blocks))

    return blocks


def decode(blocks: [int], d: int, n: int) -> str:

    codes = [str(mod_pow(int(x), d, n)) for x in blocks]
    message = ''

    for i, k in enumerate(codes):
        if len(k) % 2 != 0:
            codes[i] = '0' + k

    for k in codes:
        for a, b in grouped(k):
            message += get_char_from_code(a + b)

    return message


# https://stackoverflow.com/questions/5389507/iterating-over-every-two-elements-in-a-list
def grouped(iterable: Iterable[T], n=2) -> Iterable[Tuple[T, ...]]:
    return zip(*[iter(iterable)] * n)


def get_char_from_code(char: str) -> str:

    return chr(int(char) + 65)


def get_char_code(char: str) -> str:
    code = ord(char) - 65

    if code < 10:
        return '0' + str(code)

    return str(code)


def get_block_size(n: int) -> int:
    i = "25" * len(str(n))

    while int(i) > n:
        i = i[:-2]

    return len(i.split('2')) - 1


def generate_keys() -> (int, int):
    p, q = 0, 0

    while q == 0:
        rng = random.randint(10000, MAX_INT)

        if fermat_primality_test(rng):
            q = rng

        while p == 0:
            rng = random.randint(10000, MAX_INT)

            if fermat_primality_test(rng) and rng != q:
                p = rng

    return p, q


def fermat_primality_test(prime: int) -> bool:
    factors = generate_coprimes(prime, 10)

    for factor in factors:
        if mod_pow(factor, prime - 1, prime) != 1:
            return False

    return True


def generate_coprimes(prime: int, n: int) -> [int]:
    coprimes: [int] = []
    for i in itertools.count(start=1):
        if is_coprime(prime, i):
            coprimes.append(i)

        if len(coprimes) == n:
            break

    return coprimes


def is_coprime(a: int, b: int) -> bool:
    return mdc(a, b) == 1


def extended_mdc(a: int, b: int) -> (int, int, int):
    r = a
    r_old = b

    s = 1
    s_old = 0

    t = 0
    t_old = 1

    while r_old != 0:
        q = r // r_old
        rs = r
        ss = s
        ts = t

        r = r_old
        s = s_old
        t = t_old

        r_old = rs - q * r_old
        s_old = ss - q * s
        t_old = ts - q & t_old

    return r, s, t


def mdc(a: int, b: int) -> int:
    if b != 0:
        return mdc(b, a % b)
    else:
        return a


def mod_pow(base: int, exponent: int, modulo: int) -> int:
    number: int = base % modulo

    if exponent == 0:
        return 1
    elif exponent == 1:
        return number
    elif exponent % 2 == 0:
        return mod_pow(number * number % modulo, exponent // 2, modulo)
    else:
        return number * mod_pow(number, exponent - 1, modulo) % modulo


if __name__ == '__main__':
    main()
