#ifndef RETANGULO_H
#define RETANGULO_H

#include "FigBase.h"

#include <iostream>
using namespace std;

class Retangulo: public FigBase {
    public:
        Retangulo(double = 0, double = 0, double = 0, double = 0, int = 1, int = 1, int = 1);
        double getLargura() const;
        void setLargura(double);
        double getAltura() const;
        void setAltura(double);
        float area() const;
        float perimetro() const;
        void le(istream &);
        void imprime(ostream &) const;
        friend ostream& operator<<(ostream &, const Retangulo &);
        friend istream& operator>>(istream &, Retangulo &);
    private:
        double largura, altura;
};

#endif