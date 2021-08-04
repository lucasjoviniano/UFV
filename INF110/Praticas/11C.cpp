#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char palavra[201];
  cin.getline(palavra, 201);

  for (int i = 0; palavra[i] != '\0'; i++) {
    if (isupper(palavra[i])) {
      cout << palavra[i];
    }
  }

  cout << endl;

  return 0;
}