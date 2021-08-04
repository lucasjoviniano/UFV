#include <cmath>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;
int main() {
  int N;
  cin >> N;
  unsigned long long int a[N];
  a[0] = 0;
  a[1] = 1;
  for (int i = 2; i <= N; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }

  for (int i = N - 1; i >= 0; i--) {
    cout << a[i] << ((i == 0) ? "\n" : " ");
  }
  return 0;
}
