#include <cmath>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  bool difzero = false;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i][j] != 0) {
        difzero = true;
        break;
      }
    }
  }
  if (difzero) {
    cout << "NAO\n";
  } else {
    cout << "SIM\n";
  }

  return 0;
}
