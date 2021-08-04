#include <iostream>
using namespace std;
int main() {

  int n, x, cont = 0;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++)
    cin >> num[i];
  cin >> x;
  for (int i = n - 1; i >= 0; i--) {
    if (num[i] >= x)
      cont++;
  }
  cout << cont++ << endl;
  return 0;
}
