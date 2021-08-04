#include <cmath>
#include <cstdio>  /* printf */
#include <cstdlib> /* abs */
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  long int notaF, faltaT, faltaP;
  cin >> notaF >> faltaT >> faltaP;
  if (faltaT > 15 || faltaP > 7) {
    cout << "Reprovado\n";
  } else {
    if (notaF < 40) {
      cout << "Reprovado\n";
    } else {
      if (notaF < 60) {
        cout << "Final\n";
      } else {
        cout << "Aprovado\n";
      }
    }
  }
  return 0;
}
