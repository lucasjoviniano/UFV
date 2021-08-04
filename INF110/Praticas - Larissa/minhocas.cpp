#include <cmath>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;
int main() {
  int nlin, ncol, maior;
  long int a[100][100];
  int sumlin[100] = {0}, sumcol[100] = {0};
  cin >> nlin >> ncol;
  for (int i = 0; i < nlin; i++) {
    for (int j = 0; j < ncol; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < nlin; i++) {
    for (int j = 0; j < ncol; j++) {
      sumlin[i] += a[i][j];
    }
  }
  for (int j = 0; j < ncol; j++) {
    for (int i = 0; i < nlin; i++) {
      sumcol[j] += a[i][j];
    }
  }
  maior = sumlin[0];
  for (int i = 1; i < nlin; i++) {
    (sumlin[i] > maior) ? (maior = sumlin[i]) : (maior = maior);
  }
  for (int j = 0; j < ncol; j++) {
    (sumcol[j] > maior) ? (maior = sumcol[j]) : (maior = maior);
  }
  cout << maior << endl;
  return 0;
}
