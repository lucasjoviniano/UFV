#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Polinomio.h"

using namespace std;

double randDouble() {
  return -10.0 + (rand() / (RAND_MAX / 20.0));
}

int main() {

  double* v;
  unsigned int n;
  int op = 0;
  srand(time(NULL));
  int a = 10, b = 12, c=0;
  cout << "Soma de polinomios" << endl;
  cout << a + b << endl;
  cout << a++ << endl;
  cout << b++ << endl;
  cout << "Subtracao de polinomios" << endl;
  cout << a - b << endl;
  cout << a-- << endl;
  cout << b-- << endl;
  cout << "multiplicao de polinomios" << endl;
  cout << a * b << endl;
  cout << "divisao de polinomio" << endl;
  cout << a/b << endl;
  cout << "i-esimo coeficiente" << endl;
  cout << a%b << endl;
  if (a == b) cout << "iguais\n";
  if (a != b) cout << "diferentes\n";
  if (a > b) cout << a << " maior que " << b<< "\n";
  if (a < b) cout << a <<" menor que " << b <<"\n";
  if (a <=b ) cout << a <<" menor ou igual a " << b <<"\n";
  if (a >= b) cout << a << " maior ou igual a "<< b<<"\n";

  cout << "==========Calculadora Interativa============\n";
  cout << "Funcoes da calculadora\n";
  cout << "1 - Derivada\n";
  cout << "2 - Integral\n";
  cout << "3 - Raizes reais e complexas\n";
  cout << "4 - Integral definida\n";
  cout << "5 - Divisao do binomio\n";
  cout << "6 - O polinomio avaliado\n";
  cout << "7 - Sair\n";
  cout << "Digite a funcao que deseja\n";
  cin >> op; 
  while(op!=7){
  cout << "Digite o grau do polinomio\n";
  cin >> n;

  v = new double[n + 1];

  for (int i = 0; i <= n; i++) v[i] = randDouble();

  Polinomio poli(n, v);
  Polinomio binomio(1, v);
  delete [] v;
  double a = 0;
  double b = 0;

  switch (op){
  
    case 1:
      cout << "O polinomio e: " << poli << endl;
      cout << "Sua derivada e: " << poli.derivada() << endl;
      break;

    case 2:
      cout << "O polinomio e: " << poli << endl;  
      cout << "Sua integral é: " << poli.integral() << endl;
      break;

    case 3:
      int r;
      double* raizes;

      try {
      raizes = poli.resolve(r);
      cout << "Suas raízes reais são: ";
      for (int i = 0; i < r; i++) cout << raizes[i] << " ";
      cout << endl;
      delete [] raizes;
    } catch (RaizInexistenteExcept exc) {
      cout << "Poxa a matematica :(, infelizmente nao possui raízes reais" << endl;
    }
    try {
      complex <double>* raizesC = poli.resolveComplexas(r);
      cout << "Suas raízes complexas são:\n";
      for (int i = 0; i < r; i++) cout << raizesC[i] << " ";
      cout << endl;

      delete [] raizesC;
    } catch(RaizInexistenteExcept exc) {
      cout << "O polinômio escolhido não possui raízes, fica triste nao, escolhe outro\n";
    }
      break;

    case 4:
      a = randDouble();
      b = randDouble();
      cout << "Sua integral definida entre " << a << " e " << b << " é: " << poli.integral(a, b) << endl;
      break;

    case 5:
      v = new double[2];
      v[0] = randDouble();
      v[1] = 1;

      try {
        cout << "Sua divisão pelo binômio " << binomio << " é: " << poli/binomio << endl;
      } catch (ArgumentoInvalidoExcept exc) {
        cout << "O numero que voce digitou nao eh valido, tenta alguma coisa diferente de 0 ou 1\n";
      }

      break;
      case 6:
        a = randDouble();
        cout << "O polinomio avaliado em " << a << " é:" << poli.avalia(a) << endl;
        break;

      default:
        cout << "Pelo visto voce nao selecionou a opcao correta, clica enter para voltar";
        break;
      
  }  
  cout << "Digite a funcao que deseja\n";
  cin >> op;
}
cout << "Voce saiu, espero que tenha gostado ;)" << endl;

  /*
  cout << "Insira o grau de um polinomio\n";

  cin >> n;

  v = new double[n + 1];

  cout << "Digite os " << n + 1 << " coficientes\n";

  for (int i = 0; i <= n; i++) cin >> v[i];
  */
  return 0;
}
