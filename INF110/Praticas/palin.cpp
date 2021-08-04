#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;
int main() {
  char palavra[31], aux[31];
  cin >> palavra;
  int n = strlen(palavra);
  for (int i = 0; i <= n; i++) {
    aux[i] = palavra[n - i - 1];
  }
  if (strcmp(palavra, aux) == 0) {
    cout << "PALINDROMO" << endl;
  } else {
    cout << "NAO" << endl;
  }
  return 0;
}
