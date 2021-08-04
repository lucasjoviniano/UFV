#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double catalan(int n) {
  if (n == 0)
    return 1;

  return (((4.0 * n) - 2) * catalan(n - 1)) / (n + 1);
}

int main() {
  int n;
  cin >> n;
  while (n != -1) {
    cout << fixed << setprecision(0) << catalan(n) << endl;
    cin >> n;
  }

  return 0;
}