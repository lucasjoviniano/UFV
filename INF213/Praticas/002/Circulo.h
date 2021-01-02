#ifndef CIRCULO_H
#define CIRCULO_H

#include "FigBase.h"

#include <iostream>
using namespace std;

class Circulo: public FigBase {
    public:
        Circulo(double = 0, double = 0, double = 0, int = 1, int = 1, int = 1);
        double getRaio() const;
        void setRaio(double);
        float area() const;
        float perimetro() const;
        void le(istream &);
        void imprime(ostream &) const;
        friend ostream& operator<<(ostream &, const Circulo &);
        friend istream& operator>>(istream &, Circulo &);
    private:
        double raio;
};

#endif