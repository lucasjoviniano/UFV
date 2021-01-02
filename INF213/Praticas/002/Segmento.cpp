#include "Segmento.h"

#include <iostream>
#include <math.h>
using namespace std;

Segmento::Segmento(double x, double y, double x2, double y2, int esp, int cor, int tipo): FigBase(x, y, esp, cor, tipo) {
    setX2(x2);
    setY2(y2);
}

double Segmento::getX2() const {
    return x2;
}

void Segmento::setX2(double x) {
    x2 = x;
}

double Segmento::getY2() const {
    return y2;
}

void Segmento::setY2(double y) {
    y2 = y;
}

float Segmento::area() const {
    return 0;
}

float Segmento::perimetro() const {
    return sqrt(pow(x2 - FigBase::getX(), 2) + pow(y2 - FigBase::getY(), 2));
}

void Segmento::le(istream & file) {
    FigBase::le1(file);
    double a;
    file >> a;
    setX2(a);
    file >> a;
    setY2(a);
}

void Segmento::imprime(ostream & file) const {
    file << "--- [Segmento] ---" << endl;
    FigBase::imprime(file);
    file << "x2 = " << getX2() << " Y2 = " << getY2() << endl;
    file << "area = " << area() << " perimetro = " << perimetro() << endl;
}

ostream& operator<<(ostream & file, const Segmento & obj) {
    obj.imprime(file);
    return file;
}
istream& operator>>(istream & file, Segmento & obj) {
    obj.le(file);
    return file;
}