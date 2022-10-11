#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
  int n, xa, xb, aux;
  cin >> n;

  while (n--) {

    multiset<int> a, b, diff;
    cin >> xa >> xb;

    for (int i = 0; i < xa; i++) {
      cin >> aux;
      a.insert(aux);
    }

    for (int i = 0; i < xb; i++) {
      cin >> aux;
      b.insert(aux);
    }

    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                     inserter(diff, diff.begin()));



    cout << (a.size() - diff.size()) + (b.size() - diff.size()) << endl;
  }

  return 0;
}
