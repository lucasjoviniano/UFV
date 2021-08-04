#include <iostream>
using namespace std;
int main() {

  int n, prod = 0;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = n - 1; i >= 0; i--)
    prod += a[i] * b[i];

  cout << prod << endl;
  return 0;
}
