#include <iostream>
using namespace std;

int main() {
  double altura;
  double massa;
  double imc;

  cin >> altura >> massa;
  imc = massa / (altura * altura);
  cout << "IMC = " << imc << endl;
  if (imc < 18.5)
    cout << "Abaixo do peso\n";
  else if (imc < 25)
    cout << "Peso normal\n";
  else if (imc < 30)
    cout << "Acima do peso\n";
  else
    cout << "Obesidade\n";

  return 0;
}
