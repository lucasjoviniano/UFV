#include <iostream>

using namespace std;

int main() {
  char palavra[101];
  cin.getline(palavra, 101, ' ');
  int inic, fim;
  cin >> inic >> fim;

  for (int i = inic; i < inic + fim; i++) {
    cout << palavra[i];
  }
  cout << endl;

  return 0;
}