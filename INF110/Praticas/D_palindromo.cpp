#include <iostream>
using namespace std;
int main() {

  char p[31];
  int i, aux = 0;
  bool a = true;
  cin >> p;
  for (i = 0; p[i] != '\0'; i++)
    aux++;

  for (i = 0; i < aux; i++) {
    if (p[i] != p[aux - 1])
      a = false;
    aux--;
  }

  if (a)
    cout << "PALINDROMO" << endl;
  else
    cout << "NAO" << endl;

  return 0;
}
