#include <iostream>
using namespace std;
int main() {
  int p0, g, cont = 1;
  unsigned long long int v1, v2 = 0;
  cin >> p0 >> g;
  v1 = (1 + g) * p0;
  while (v2 < 1000000000) {
    v2 = v1 * (1 + g);
    cont++;
    v1 = v2;
  }
  cout << cont << endl;
  return 0;
}
