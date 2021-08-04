#include <cmath>
#include <cstdio>  /* printf */
#include <cstdlib> /* abs */
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int a, b, mmc, mdc, menor, maior;
  cin >> a >> b;
  maior = (a > b) ? a : b;
  menor = (a < b) ? a : b;
  mdc = 1;
  for (int i = 1; i <= menor; i++) {
    if ((a % i == 0) && (b % i == 0)) {
      mdc = i;
    }
  }
  mmc = a * b / mdc;
  cout << mmc << endl;
  return 0;
}
