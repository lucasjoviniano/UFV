#include <iostream>
using namespace std;

// Retorna o valor de x!
long long int fatorial(int x) {
  long long int fat = 1;
  for (int i = 2; i <= x; i++)
    fat *= i;
  return fat;
}
short int n, k;
long long int fat;
int main() {
  cin >> n >> k;
  cout << fatorial(n) / (fatorial(k) * fatorial(n - k)) << "\n";

  return 0;
}
