#include "Conjunto2.h"

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    Conjunto<int> A(n);
    Conjunto<int> B(n);

    for (int i = 1; i <= n; i++) {
        A.insere(i);
        B.insere(-i);
    }

    Conjunto<int> C = A + B;

    cout << C.pertence(10) << endl;

    return 0;
}