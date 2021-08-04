#include <iomanip>
#include <iostream>

using namespace std;

struct aluno {
  int matricula, nota;
};

int main() {
  int qtd;
  cin >> qtd;
  aluno matriz[100];
  for (int i = 0; i < qtd; i++) {
    cin >> matriz[i].matricula;
    cin >> matriz[i].nota;
  }
  for (int passo = 0; passo < qtd - 1; passo++) {
    for (int i = 0; i < qtd - 1; i++) {
      if (matriz[i].matricula > matriz[i + 1].matricula) {
        int aux = matriz[i].matricula;
        int aux2 = matriz[i].nota;

        matriz[i].matricula = matriz[i + 1].matricula;
        matriz[i].nota = matriz[i + 1].nota;

        matriz[i + 1].matricula = aux;
        matriz[i + 1].nota = aux2;
      }
    }
    // cout << matriz[passo].matricula << ' ' << matriz[passo].nota<<endl;
  }

  for (int i = 0; i < qtd; i++) {
    cout << matriz[i].matricula << ' ' << matriz[i].nota << endl;
  }

  return 0;
}