#include <iostream>
using namespace std;
int main() {

  int n, cont = 0;
  long long int fora, maior;

  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  maior = a[0];
  for (int i = 1; i < n; i++)
    if (maior < a[i])
      maior = a[i];

  fora = maior + 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j])
        a[j] = fora;
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i] < fora)
      cont++;
  }
  cout << cont << endl;
  return 0;
}
