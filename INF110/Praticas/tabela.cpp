#include <iostream>
using namespace std;
long long int d, f;
int main() {
  cin >> d >> f;
  int a[d][f];
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < f; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < f; j++) {
    for (int i = 0; i < d; i++) {
      cout << a[i][j];
      (i < d - 1) ? (cout << " ") : (cout << "\n");
    }
  }
  return 0;
}
