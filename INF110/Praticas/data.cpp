#include <cmath>
#include <iostream>

using namespace std;
bool bissexto(int n) {
  if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
    return true;
  } else {
    return false;
  }
}
bool validaData(int d, int m, int a) {
  if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) &&
      (d >= 1 && d <= 31))
    return true;
  if ((m == 4 || m == 6 || m == 9 || m == 11) && (d >= 1 && d <= 30))
    return true;
  if ((m == 2) && ((d >= 1 && d <= 28) || ((d == 29) && bissexto(a))))
    return true;
  return false;
}

int main() {
  int dia, mes, ano;
  cin >> dia >> mes >> ano;
  if (validaData(dia, mes, ano)) {
    cout << "data valida\n";
  } else {
    cout << "data invalida\n";
  }
  return 0;
}
