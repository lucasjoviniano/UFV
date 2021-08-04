#include <iostream>
using namespace std;

int main() {

  int x;
  cin >> x;

  if (x % 2 == 0)
    cout << x << " e' par\n";
  else
    cout << x << " e' impar\n";

  return 0;
}
