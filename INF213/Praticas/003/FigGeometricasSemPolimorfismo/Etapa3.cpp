#include <iostream>
#include "Circulo.h"
#include "Retangulo.h"
#include "FigBase.h"
#include "Segmento.h"

using namespace std;

int main() {
    Circulo c1;
    Circulo c2;
    Retangulo r1;
    Segmento s1;
    Segmento s2;
    FigBase *v[5] = {&c1, &c2, &r1, &s1, &s2};

    for (int i = 0; i < 5; i++) {
        cin >> *v[i];
    }

    for (int i = 0; i < 5; i++) cout << *(v[i]);
}