#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string a, b;

  while (true) {
    cin >> a >> b;

    if (a == "0" && b == "0")
      break;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int vai = 0, cont = 0;

    if (a.size() < b.size())
      while (a.size() != b.size())
        a += '0';
    else
      while (a.size() != b.size())
        b += '0';

    for (int i = 0; i < a.size(); i++) {
      if (a[i] - '0' + b[i] - '0' + vai > 9) {
        cont++;
        vai = 1;
      } else {
        vai = 0;
      }
    }

    switch (cont) {
    case 0:
      cout << "No carry operation.\n";
      break;
    case 1:
      cout << "1 carry operation.\n";
      break;
    default:
      cout << cont << " carry operations.\n";
    }
  }

  return 0;
}
