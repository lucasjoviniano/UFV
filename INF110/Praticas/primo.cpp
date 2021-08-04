#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int n;
  bool primo = false;
  cin >> n;
  if (n == 2)
    cout << "Primo." << endl;
  else {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        primo = true;
        break;
      }
    }
    if (primo)
      cout << "Nao primo." << endl;
    else {
      cout << "Primo." << endl;
    }
  }

  return 0;
}
