#include <iostream>
using namespace std;
int main() {
  int n, c, s, e, p = 0;
  bool cap = false;
  cin >> n >> c;
  while (n > 0) {
    cin >> s >> e;
    p += e - s;
    if (p > c) {
      cap = true;
    }
    n--;
  }
  if (cap) {
    cout << "S\n";
  } else {
    cout << "N\n";
  }
  return 0;
}
