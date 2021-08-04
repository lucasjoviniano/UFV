#include <cmath>
#include <iostream>

using namespace std;
int espelhar(int n) {
  int uni, dez, cem, mil;
  uni = n % 10;
  n /= 10;
  dez = n % 10;
  n /= 10;
  cem = n % 10;
  n /= 10;
  mil = n % 10;
  return 1000 * uni + 100 * dez + 10 * cem + mil;
}

int main() {
  int num, esp;
  cin >> num >> esp;
  while (num != 0 && esp != 0) {
    if (esp == espelhar(num))
      cout << "espelho\n";
    else
      cout << "nao espelho\n";
    cin >> num >> esp;
  }
  return 0;
}
