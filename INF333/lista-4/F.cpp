#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
  while (true) {
    int n, d, in;
    cin >> n;

    if (n == 0)
      return 0;

    unsigned long long int price = 0;

    multiset<int> urn;

    for (int i = 0; i < n; i++) {
      cin >> d;

      for (int j = 0; j < d; j++) {
        cin >> in;
        urn.insert(in);
      }

      price += *(prev(urn.end())) - *urn.begin();
      auto it = urn.begin();
      urn.erase(it);
      it = prev(urn.end());
      urn.erase(it);
    }
    cout << price << endl;
  }
}
