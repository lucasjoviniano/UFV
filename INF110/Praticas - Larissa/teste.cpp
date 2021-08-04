#include <iostream>
using namespace std;
int main() {

  int num1, num2, maior;

  cout << "Digite 2 numeros\n";
  cin >> num1 >> num2;

  if (num1 == num2)
    cout << "Sao iguais!\n";

  else {
    if (num1 > num2) {

      cout << num1;
      num1 = maior;
    } else
      cout << num2;
    cout << " Eh maior\n";
  }

  if (num1 % 2 == 0)
    cout << "E par\n";
  else
    cout << "E impar\n";
  return 0;
}
