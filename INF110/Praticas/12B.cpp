#include <cstring>
#include <iostream>

using namespace std;
int main() {
  char p1[101];
  char p2[101];
  cin.getline(p1, 101);
  cin.getline(p2, 101);
  int cont = 0;
  if (strlen(p1) != strlen(p2)) {
    cout << "NAO" << endl;
    return 0;
  } else {

    for (int i = 0; p1[i] != '\0'; i++) {
      if (p1[i] != p2[i]) {
        cont++;
      }
      if (cont > 1) {
        break;
      }
    }
    if (cont == 1) {
      cout << "SIM" << endl;
    } else {
      cout << "NAO" << endl;
    }

    return 0;
  }
}