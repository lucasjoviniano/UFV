#include <iostream>
using namespace std;
int main() {
  short int i, n;
  unsigned long long int fib = 1, fn1 = 1, fn2 = 1;
  cin >> n;
  if ((n == 0) || (n == 1)) {
    cout << n << endl;
  } else {
    for (i = 2; i < n; i++) {
      fib = fn1 + fn2;
      fn2 = fn1;
      fn1 = fib;
    }
    cout << fib << endl;
  }
  return 0;
}
