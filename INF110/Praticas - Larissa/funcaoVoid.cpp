#include <iostream>
using namespace std;

void linha(int n) {
  for (int i = 0; i < n; i++)
    cout << "*";
  cout << "\n";
}

int main() {
  int x;
  cin >> x;
  for (int i = 1; i < x; i++)
    linha(i);

  return 0;
}
