#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

long long int fatorial(int n) {
  if (n > 1)
    cout << n << " x ";
  if (n == 1)
    cout << n << " = ";
  if (n <= 1)
    return 1;
  else
    return n * fatorial(n - 1);
}
int main() {
  int n;
  cin >> n;
  cout << n << "! = ";
  cout << fatorial(n) << endl;
  return 0;
}
