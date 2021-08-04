#include <iostream>
using namespace std;

double area(double r) { return 3.1415 * r * r; }

double vcilindro(double r, double h) { return h * area(r); }

int main() {
  for (int i = 1; i < 10; i++) {
    cout << "Circulo de raio " << i << "tem area " << area(i) << endl;
  }

  double raio, altura;
  cin >> raio >> altura;
  cout << "Volume: " << vcilindro(raio, altura);

  return 0;
}
