#include <cmath>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;
int main() {
  int N, maior, cont = 0;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  maior = a[0];
  for (int i = 1; i < N; i++) {
    (a[i] > maior) ? (maior = a[i]) : (maior = maior);
  }
  for (int i = 0; i < N; i++) {
    if (a[i] == maior) {
      cont++;
    }
  }
  cout << maior << " " << cont << "\n";
  return 0;
}
