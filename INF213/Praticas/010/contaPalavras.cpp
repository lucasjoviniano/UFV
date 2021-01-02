#include "MySet.h"
#include "MyVecNewIterator.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    string s;

    int cont = 0;
    bool aux = false;

    if (strcmp(argv[1], "myvec") == 0) {
        MyVec<string> v;
        while (cin >> s) {
            aux = false;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == s) {
                    aux = true;
                    break;
                }
            }
            if (!aux) v.push_back(s);
            cont++;
        }
        cout << cont << " " << v.size() << endl;
    } else {
        MySet<string> v;
        while (cin >> s) {
            v.insert(s);
            cont++;
        }
        cout << cont << " " << v.size() << endl;
    }

    return 0;
}