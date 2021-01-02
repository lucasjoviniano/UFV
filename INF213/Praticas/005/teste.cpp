#include "MyVec.h"

#include <iostream>
using namespace std;

int main() {
    MyVec<char> v(40000, 'a');
    char caso;

    cin >> caso;
    if (caso == 'a') {
        v.eraseMatchingElements('a');
    } else {
        v.eraseMatchingElements('b');
    }
    cout << v << endl;

    return 0;
}