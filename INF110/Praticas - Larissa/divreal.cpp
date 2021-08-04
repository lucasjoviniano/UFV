#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double dividendo, divisor, quociente;
  cin >> dividendo >> divisor;
  quociente = dividendo / divisor;
  // printf("%.2lf\n",quociente);
  cout << fixed << setprecision(2) << quociente << endl;
  return 0;
}
