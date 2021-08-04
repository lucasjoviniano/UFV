#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
void somafrac(int na, int da, int nb, int db, int &nr, int &dr) {
  int num = (na * db + nb * da);
  int den = (da * db);
  int mdc = 1;
  for (int i = 1; i <= (den < num ? den : num); i++) {
    if (num % i == 0 && den % i == 0)
      mdc = i;
  }
  nr = num / mdc;
  dr = den / mdc;
  return;
}
int main() {

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d;
  somafrac(a, b, c, d, e, f);
  cout << a << "/" << b << "+" << c << "/" << d << "=" << e << "/" << f << endl;
  return 0;
}
