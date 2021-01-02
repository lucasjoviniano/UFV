#include "MyMap.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    MyMap<string, int> m;
    string s;
    int cont = 0;
    while (cin >> s) {
        if (m.find(s) == NULL) {
            m.insert(make_pair(s, cont));
            cout << s << " " << cont << endl;
            cont++;
        } else {
            cout << s << " " << m[s] << endl;
        }
    }

    return 0;
}