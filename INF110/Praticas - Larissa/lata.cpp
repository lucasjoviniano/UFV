#include <cstdio> //para usar printf
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  const double pi = 3.1415;
  double raio, altura, volume;
  cin >> raio >> altura;
  volume = pi * raio * raio * altura;
  // printf("%.2lf\n",quociente);
  cout << fixed << setprecision(2) << volume << endl;
  return 0;
}
