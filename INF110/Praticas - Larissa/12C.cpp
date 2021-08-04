#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char palavra[201];
  char sigla[201];
  cin.getline(sigla, 201);
  cin.getline(palavra, 201);
  int j = 0;
  int valid = 0;

  for (int i = 0; sigla[i] != '\0'; i++) {
    for (; palavra[j] != '\0'; j++) {
      if (sigla[i] == palavra[j]) {
        valid++;
        j++;
        break;
      }
    }
  }

  if (valid == strlen(sigla)) {
    cout << "SIM" << endl;
  } else {
    cout << "NAO" << endl;
  }

  return 0;
}