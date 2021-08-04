#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  long int menor, maior, resultado;
  cin >> menor >> maior;
  if (maior == 0 && menor == 0) {
    resultado = 1;
  } else {
    if (maior % menor == 0) {
      resultado = 1;
    } else {
      resultado = 0;
    }
  }
  cout << resultado << endl;

  return 0;
}
