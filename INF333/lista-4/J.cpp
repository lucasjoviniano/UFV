#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

#define all(x) x.begin(), x.end()
using namespace std;

int main() {
  while (true) {
    int n, m, aux;
    set<int> jack, jill, in;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      jack.insert(aux);
    }

    for (int i = 0; i < n; i++) {
      cin >> aux;
      jill.insert(aux);
    }

    set_intersection(all(jack), all(jill), inserter(in, in.begin()));

    cout << in.size() << endl;
  }
}
