#include <iostream>
using namespace std;
int main() {
  long long int n, x;
  bool igualx = false;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cin >> x;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] + a[j] == x) {
        igualx = true;
        break;
      }
    }
  }
  if (igualx)
    cout << "SIM" << endl;
  else
    cout << "NAO" << endl;

  return 0;
}
