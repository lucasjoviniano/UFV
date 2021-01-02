#include "Mediana.h"

void Mediana::insere(int x) {
    if (v1.size() == 0) v1.push(x);
    else if (v1.size() == 1 && v2.size() == 0) {
        if (x > v1.top()) v2.push(-x);
        else {
            v2.push(-v1.top());
            v1.pop();
            v1.push(x);
        }
    }
    else {
        if (x < v1.top()) v1.push(x);
        else v2.push(-x);
    }

    if (v1.size() - v2.size() > 1) {
            v2.push(-v1.top());
            v1.pop();
    } else if (v2.size() - v1.size() > 1) {
            v1.push(-v2.top());
            v2.pop();
    }
}

int Mediana::getMediana() {
    if (v1.size() == v2.size()) return ((v1.top() - v2.top()) / 2);
    else if (v1.size() > v2.size()) return v1.top();
    else return -v2.top();
}