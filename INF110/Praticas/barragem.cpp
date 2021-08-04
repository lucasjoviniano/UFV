#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int i = 1, t, p, pes = 0, soma = 0;
  cin >> p >> t;
  while (true) {
    cin >> pes;
    if (pes == -1)
      break;
    if (i <= t) {
      soma += pes;
    }
    i++;
  }
  if (soma == p) {
    cout << "Todos a salvo\n";
  } else {
    cout << "Apenas " << soma << " pessoas a salvo\n";
  }
  return 0;
}
