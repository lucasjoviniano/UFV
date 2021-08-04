#include <cmath>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;
int main() {
  int N, soma = 0, somasec = 0, nsec;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    soma += a[i];
  }
  for (int i = 0; somasec < soma / 2; i++) {
    somasec += a[i];
    nsec = i + 1;
  }
  cout << nsec << "\n";
  return 0;
}
