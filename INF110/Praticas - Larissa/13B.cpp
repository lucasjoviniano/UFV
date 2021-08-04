#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

struct Ponto {
  int x, y;
};

double area(double a, double b, double c, double semip) {
  double valor = sqrt(semip * (semip - a) * (semip - b) * (semip - c));
  return valor;
}

double dist(Ponto P, Ponto Q) {
  double reta = sqrt(pow(P.x - Q.x, 2) + pow(P.y - Q.y, 2));
  return reta;
}

int main() {
  Ponto p1, p2, p3;
  // Ler as coordenadas de cada ponto
  cin >> p1.x;
  cin >> p1.y;
  cin >> p2.x;
  cin >> p2.y;
  cin >> p3.x;
  cin >> p3.y;

  // Sendo assim, serão 3 retas: p1 -> p2; p2 -> p3;
  // p3 -> p1;

  // Analisando o tamanho de cada reta

  double reta1 = dist(p1, p2);
  double reta2 = dist(p2, p3);
  double reta3 = dist(p3, p1);

  // Calculamos então o semiperímetro
  double semip = (reta1 + reta2 + reta3) / 2;

  // E então chamamos a funcao area
  double valor_area = area(reta1, reta2, reta3, semip);

  cout << setprecision(2) << fixed << valor_area << endl;

  return 0;
}