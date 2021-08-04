#include <cmath>
#include <iostream>

using namespace std;
int main() {
  int i, contc = 1;
  char c, aux;
  cin >> c;
  aux = c;
  for (i = 1; true; i++) {
    cin >> c;
    if (c == '.')
      break;
    if (c == aux) {
      contc++;
    } else {
      cout << contc++ << aux;
      contc = 1;
    }
    aux = c;
  }
  cout << contc++ << aux << '0' << endl;
  return 0;
}
