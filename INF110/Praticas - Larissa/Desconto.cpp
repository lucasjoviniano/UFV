#include <iostream>
using namespace std;

int main() {
  double preco;
  char resp;
  double porcDesconto;

  // Ler o preco normal
  cin >> preco;

  // Preguntar se tem desconto
  cout << "Tem desconto? (S)im ou (N)ao: ";

  // vendedor responde S ou N
  cin >> resp;

  while (resp != 'N' && resp != 'S' && resp != 'n' && resp != 's') {
    cout << "Opcao invalidA!\n";
    cout << "Tem desconto? (S)im ou (N)ao: ";
    cin >> resp;
  }

  // Se resposta for S, pergunta % de desconto
  if (resp == 'S' || resp == 's') {
    cout << "Quantos %? ";
    cin >> porcDesconto;
    double desconto = preco * (porcDesconto / 100);
    preco = preco - desconto;
  }

  // Informar o preco final
  cout << "Preco final: " << preco << endl;

  return 0;
}
