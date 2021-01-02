#include "FigBase.h"

#include <iostream>
using namespace std;

FigBase::FigBase(double x, double y, int espessura, int cor, int tipo) {
    setX(x);
    setY(y);
    setEspessura(espessura);
    setCor(cor);
    setTipo(tipo);
}

double FigBase::getX() const {
    return x;
}

void FigBase::setX(double x) {
    this->x = x;
}

double FigBase::getY() const {
    return y;
}

void FigBase::setY(double y) {
    this-> y = y;
}

int FigBase::getEspessura() const {
    return espessura;
}

void FigBase::setEspessura(int esp) {
    espessura = (esp < 1 || esp > 5) ? 1 : esp;
}

int FigBase::getCor() const {
    return cor;
}

void FigBase::setCor(int c) {
    cor = (c < 1 || c > 5) ? 1 : c;
} 

int FigBase::getTipo() const {
    return tipo;
}

void FigBase::setTipo(int tipo) {
    this->tipo = (tipo < 1 || tipo > 3) ? 1 : tipo;
}

// Le x e y
void FigBase::le1(istream & file) {
    double a;
    file >> a;
    setX(a);
    file >> a;
    setY(a);
}

// Le o resto
void FigBase::le2(istream & file) {
    int a;
    file >> a;
    setEspessura(a);
    file >> a;
    setCor(a);
    file >> a;
    setTipo(a);
}

void FigBase::imprime(ostream & file) const {
    file << " Atributos da linha: " << endl;
    file << "     Espessura = " << getEspessura() << endl;
    file << "     Cor       = " << getCor() << endl;
    file << "     Tipo      = " << getTipo() << endl;          
    file << " x = " << getX() << " y = " << getY() << endl;
}

ostream& operator<<(ostream & file, const FigBase & obj) {
    obj.imprime(file);
    return file;
}
istream& operator>>(istream & file, FigBase & obj) {
    obj.le1(file);
    obj.le2(file);
    return file;
}