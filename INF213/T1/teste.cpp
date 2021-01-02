#include <iostream>
#include <string.h>
#include "MyMatrix.h"
using namespace std;

int main() {

    int cols[] = {0, 0, 0};
    MyMatrix<int> m(0, cols, false);
    cout << m.isRagged() << endl;

    {
        MyMatrix<int> n = m;
        cout << m.isRagged() << endl;
    }

    m.print();

    return 0;
}