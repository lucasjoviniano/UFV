#include <iostream>
using namespace std;

int main() {

  char a[101], b[101];
  int d = 0, conta = 0, contb = 0;

  cin >> a;
  cin >> b;

  for (int i = 0; a[i] != '\0'; i++)
    conta++;
  for (int i = 0; b[i] != '\0'; i++)
    contb++;

  if (conta == contb) {
    for (int i = 0; a[i] != '\0'; i++)
      if (a[i] != b[i])
        d++;
    if (d == 1)
      cout << "SIM" << endl;
    if (d != 1)
      cout << "NAO" << endl;
  } else
    cout << "NAO" << endl;
  return 0;
}