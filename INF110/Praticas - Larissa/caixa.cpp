#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int n, i, quociente;
  cin >> n;
  for (i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      quociente = n / i;
      cout << i << " x " << quociente << endl;
    }
  }
  return 0;
}
