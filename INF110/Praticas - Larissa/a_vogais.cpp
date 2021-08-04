#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  char palavra[31];
  int contvog = 0;
  cin >> palavra;

  for (int i = 0; palavra[i] != '\0'; i++) {
    if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' ||
        palavra[i] == 'o' || palavra[i] == 'u' || palavra[i] == 'A' ||
        palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' ||
        palavra[i] == 'U')
      contvog++;
  }
  cout << fixed << setprecision(0) << 100.0 * contvog / strlen(palavra) << "%"
       << endl;
  return 0;
}
