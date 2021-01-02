#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "FigBase.h"

class Segmento: public FigBase {
    public:
        Segmento(double = 0, double = 0, double = 0, double = 0, int = 1, int = 1, int = 1);
        double getX2() const;
        void setX2(double);
        double getY2() const;
        void setY2(double);
        float area() const;
        float perimetro() const;
        void le(istream &);
        void imprime(ostream &) const;
        friend ostream& operator<<(ostream &, const Segmento &);
        friend istream& operator>>(istream &, Segmento &);
    private:
        double x2, y2;
};

#endif