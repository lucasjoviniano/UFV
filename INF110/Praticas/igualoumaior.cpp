#include <iostream>
using namespace std;
int main() {

  int num1, num2;

  cout << "Digite 2 numeros";
  cin >> num1 >> num2;

  if (num1 == num2)
    cout << "Sao iguais!\n";
  else if (num1 > num2) {
    cout << num1;
  } else
    cout << num2;
  cout << "Eh maior\n";

  return 0;
}
