import sys
import numpy as np

MAX = 10

def writeMatrix(f, X, n):
    for i in range(n):
        f.write(' '.join(map(str, X[i])))
        f.write('\n')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage 'python check.py n'")
        sys.exit(0)
    n = int(sys.argv[1])
    A = np.random.randint(MAX, size = (n, n)) - MAX // 2
    B = np.random.randint(MAX, size = (n, n)) - MAX // 2

    with open('input.txt', 'w') as f:
        f.write(str(n) + '\n')
        writeMatrix(f, A, n)
        writeMatrix(f, B, n)
 
    with open('output.txt', 'w') as f:
        writeMatrix(f, A.dot(B), n)
