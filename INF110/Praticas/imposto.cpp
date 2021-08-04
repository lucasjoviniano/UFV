#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
double imposto(double v) {
  const double v1 = 1713.58, v2 = 4257.57, v3 = 7633.51, v4 = 10432.32;
  const double lim1 = 22847.76, lim2 = 33919.80, lim3 = 45012.60,
               lim4 = 55976.16;
  if (v <= lim1)
    return 0;

  if (v > lim1 && v <= lim2)
    return 7.5 / 100 * v - v1;

  if (v > lim2 && v <= lim3)
    return 15.0 / 100 * v - v2;

  if (v > lim3 && v <= lim4)
    return 22.5 / 100 * v - v3;

  if (v > lim4)
    return 27.5 / 100 * v - v4;
}

int main() {
  long double v;
  cin >> v;
  while (v != 0) {
    cout << "R$ " << fixed << setprecision(2) << imposto(v) << endl;
    cin >> v;
  }
  return 0;
}
