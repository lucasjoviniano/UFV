#include "Circulo.h"

#include <iostream>
using namespace std;

const float PI = 3.141592653589;

Circulo::Circulo(double x, double y, double raio, int esp, int cor, int tipo): FigBase(x, y, esp, cor, tipo) {
    setRaio(raio);
}

double Circulo::getRaio() const {
    return raio;
}

void Circulo::setRaio(double r) {
    raio = r;
}

float Circulo::area() const {
    return PI * raio * raio;
}

float Circulo::perimetro() const {
    return 2 * PI * raio;
}

void Circulo::le(istream & file) {
    FigBase::le1(file);
    double r;
    file >> r;
    setRaio(r);
    FigBase::le2(file);
}

void Circulo::imprime(ostream & file) const {
    file << "--- [Circulo] ---" << endl;
    FigBase::imprime(file);
    file << " raio = " << getRaio() << endl; 
    file << " area = " << area() << " perimetro = " << perimetro() << endl;
}

ostream& operator<<(ostream & file, const Circulo & obj) {
    obj.imprime(file);
    return file;
}
istream& operator>>(istream & file, Circulo & obj) {
    obj.le(file);
    return file;
}