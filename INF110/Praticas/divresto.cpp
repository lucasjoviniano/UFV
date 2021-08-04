#include <iostream>
using namespace std;
int main() {
  long int dividendo, divisor, resto, quociente;
  cin >> dividendo >> divisor;
  quociente = dividendo / divisor;
  resto = dividendo % divisor;
  cout << quociente << " " << resto << endl;
  if (quociente == 0 || resto == 0)
    cout << "indefinido";
  return 0;
}
