#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  // Declaracao de variaveis
  int largura, peso;

  // Le os dados do caminhao
  cout << "Digite a largura e o peso do caminhao: ";
  cin >> largura >> peso;

  // Fazer o teste usando operador logico && (and)
  if (largura <= 3 && peso <= 10)
    cout << "Pode passar\n";
  else
    cout << "Nao pode passar\n";

  // Fazer o teste usando operador logico || (ou) - verifica se excede limites
  if (largura > 3 || peso > 10)
    cout << "Nao pode passar\n";
  else
    cout << "Pode passar\n";

  return 0;
}
