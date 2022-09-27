#include <iostream>
#include <set>
using namespace std;

int main() {
  int p;
  cin >> p;

  while (p--) {
    int c, m;
    cin >> c >> m;

    cout << c << " " << (m + 1) / 2 << '\n';

    int a;
    int cont = 0;
    multiset<int> r;
    for (int i = 0; i < m; i++) {
      cin >> a;
      r.insert(a);
      if (i % 2 == 0) {
        set<int>::iterator it = r.begin();
        advance(it, i / 2);
        cout << *it;
        cont++;
        if (cont != 10 && i != m - 1) {
          cout << ' ';
        }

        if (cont == 10)
          cont = 0;
      }
      if ((i + 1) % 20 == 0 && i != m - 1)
        cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}
