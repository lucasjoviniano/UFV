#ifndef FIGBASE_H
#define FIGBASE_H

#include <iostream>
using namespace std;

class FigBase {
    public:
        FigBase(double = 0, double = 0, int = 1, int = 1, int = 1);
        double getX() const;
        void setX(double);
        double getY() const;
        void setY(double);
        int getEspessura() const;
        void setEspessura(int);
        int getCor() const;
        void setCor(int);
        int getTipo() const;
        void setTipo(int);
        void le1(istream &);
        void le2(istream &);
        void imprime(ostream &) const;
        friend ostream& operator<<(ostream &, const FigBase &);
        friend istream& operator>>(istream &, FigBase &);
    private:
        double x, y;
        int espessura, cor, tipo;
};

#endif