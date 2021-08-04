#include <cmath>  //para usar sqrt
#include <cstdio> //para usar printf
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double x1, x2, y1, y2, distancia;
  cin >> x1 >> y1 >> x2 >> y2;
  distancia = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  cout << fixed << setprecision(2) << distancia << endl;
  return 0;
}
