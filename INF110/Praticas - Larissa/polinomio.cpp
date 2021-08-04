#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int grau;
  cin >> grau;
  double coef[grau];
  double x;
  double result = 0;
  for (int i = grau; i >= 0; i--) {
    cin >> coef[i];
  }
  cin >> x;
  for (int j = grau; j >= 0; j--) {
    result += coef[j] * pow(x, j);
  }
  cout << fixed << setprecision(2) << result << endl;
  return 0;
}