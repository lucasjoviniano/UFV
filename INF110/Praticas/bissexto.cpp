#include <cmath>
#include <iostream>

using namespace std;
bool bissexto(int n) {
  if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
    return true;
  else
    return false;
}
int main() {

  int ano;
  cin >> ano;
  while (ano > 0) {
    if (bissexto(ano))
      cout << "bissexto\n";
    else
      cout << "nao bissexto\n";
    cin >> ano;
  }
  return 0;
}
