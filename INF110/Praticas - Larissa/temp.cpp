#include <cmath>
#include <cstdio>  /* printf */
#include <cstdlib> /* abs */
#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  char escala;
  double temperatura, convCtoF, convFtoC;
  const double c1 = 5.0, c2 = 9.0, c3 = 32.0;
  cin >> temperatura >> escala;
  if (escala == 'F') {
    convFtoC = (c1 / c2) * (temperatura - c3);
    cout << fixed << setprecision(1) << convFtoC << " C" << endl;
  } else {
    if (escala == 'C') {
      convCtoF = (c2 / c1) * temperatura + c3;
      cout << fixed << setprecision(1) << convCtoF << " F" << endl;
    }
  }
  return 0;
}
