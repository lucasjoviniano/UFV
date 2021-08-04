#include <iostream>
using namespace std;

int main() {
  int a, b;
  char operador;
  int resultado;

  // Leitura da expressao
  cin >> a >> operador >> b;

  // Calculo
  if (operador == '+')
    resultado = a + b;
  else if (operador == '-')
    resultado = a - b;
  else if (operador == '*')
    resultado = a * b;
  else
    resultado = a / b;

  // Impressao do resultado
  cout << resultado << endl;

  return 0;
}
