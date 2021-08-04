#include <iostream>
using namespace std;
int main() {
  int n, i, soma = 0;
  cin >> n;
  for (i = 1; i < n; i++) {
    if (n % i == 0)
      soma += i;
  }
  if (soma == n)
    cout << "SIM\n";
  else
    cout << "NAO\n";

  return 0;
}
