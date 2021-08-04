#include <iostream>

using namespace std;

int main() {
  int N, I, L, idade, id_fora = 0;
  cin >> N >> I >> L;
  for (int j = 0; j < N; j++) {
    cin >> idade;
    if (idade >= I)
      id_fora++;
  }
  if (id_fora > L)
    cout << "Nao aceito.\n";
  else
    cout << "Aceito.\n";

  return 0;
}
