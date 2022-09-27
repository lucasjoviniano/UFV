#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int i, line, sum = 0;
    for (i = 1;; i++) {
      sum += i;
      if (sum >= n) {
        line = i;
        break;
      }
    }
    cout << "TERM " << n << " IS ";
    if (line & 1)
      cout << 1 + sum - n << "/" << line - (sum - n) << '\n';
    else
      cout << line - (sum - n) << "/" << 1 + sum - n << '\n';
  }
  return 0;
}
