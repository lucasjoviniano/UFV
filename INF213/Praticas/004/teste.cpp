#include <iostream>

using namespace std;

int main() {
    int * t = new int[10];

    for (int i = 0; i < 10; i++) {
        t[i] = i;
    }

    int el = 0;
    for (int i = 0; i < 10; i++) {
        cout << t[el++] << endl;
    }
}