#include <cmath>
#include <cstdio>  /* printf */
#include <cstdlib> /* abs */
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double a, b, c, raizMenos, raizMais, delta;
  cin >> a >> b >> c;
  delta = b * b - 4 * a * c;
  if (delta < 0) {
    cout << "Nao ha raiz real\n";
  } else {
    if (delta == 0) {
      raizMenos = -b / (2 * a);
      cout << fixed << setprecision(2) << raizMenos << endl;
    } else {
      raizMenos = (-b - sqrt(delta)) / (2 * a);
      raizMais = (-b + sqrt(delta)) / (2 * a);
      cout << fixed << setprecision(2) << raizMenos << " " << raizMais << endl;
    }
  }
  return 0;
}
