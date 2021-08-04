#include <iostream>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (x == 0 && y == 0) {
    cout << "ORIGEM\n";
  } else {
    if (x == 0)
      cout << "EIXO Y\n";
    if (y == 0)
      cout << "EIXO X\n";
    if (x > 0 && y > 0)
      cout << "QUADRANTE 1\n";
    if (x < 0 && y > 0)
      cout << "QUADRANTE 2\n";
    if (x < 0 && y < 0)
      cout << "QUADRANTE 3\n";
    if (x > 0 && y < 0)
      cout << "QUADRANTE 4\n";
  }
  return 0;
}
