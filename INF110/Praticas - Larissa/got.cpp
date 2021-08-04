#include <iostream>
using namespace std;

int main() {

  int n, i;
  int at = 0, aux, aux2 = 0;

  cin >> n;

  int a[n];

  for (i = 0; i < n; i++) {
    cin >> a[i];
    at = at + a[i];
  }
  aux = at / 2;

  for (i = 0; i < n; i++) {
    aux2 = aux2 + a[i];
    if (aux2 == aux) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}
