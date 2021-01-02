#include "Retangulo.h"

#include <iostream>

using namespace std;

Retangulo::Retangulo(double x, double y, double largura, double altura, int esp, int cor, int tipo): FigBase(x, y, esp, cor, tipo) {
    setLargura(largura);
    setAltura(altura);
}

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double l) {
    largura = l;
}

double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double a) {
    altura = a;
}

float Retangulo::area() const {
    return largura * altura;
}

float Retangulo::perimetro() const {
    return 2 * (largura + altura);
}

void Retangulo::le(istream & file) {
    FigBase::le1(file);
    double a;
    file >> a;
    setAltura(a);
    file >> a;
    setLargura(a);
    FigBase::le2(file);
}

void Retangulo::imprime(ostream & file) const {
    file << "--- [Retangulo] ---" << endl;
    FigBase::imprime(file);
    file << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    file << " area = " << area() << " perimetro = " << perimetro() << endl;
}

ostream& operator<<(ostream & file, const Retangulo & obj) {
    obj.imprime(file);
    return file;
}
istream& operator>>(istream & file, Retangulo & obj) {
    obj.le(file);
    return file;
}