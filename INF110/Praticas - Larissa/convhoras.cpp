#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
// Converte seg segundos em h horas m minutos s segundos
void convhoras(int seg, int &h, int &m, int &s) {
  h = seg / 3600;
  seg = seg % 3600;
  m = seg / 60;
  seg = seg % 60;
  s = seg;
  return;
}
int main() {
  int seg;
  int hor, min, sec;
  cin >> seg;
  convhoras(seg, hor, min, sec);
  cout << setw(2) << setfill('0') << hor << ":";
  cout << setw(2) << setfill('0') << min << ":";
  cout << setw(2) << setfill('0') << sec << "\n";
  return 0;
}
