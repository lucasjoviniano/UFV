#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int r;
    cin >> r;
    vector<int> v(r);

    for (int i = 0; i < r; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());

    const int median = v[v.size() / 2];

    long long sum =
        accumulate(v.begin(), v.end(), 0, [&median](const int a, const int b) {
          return a + abs(b - median);
        });

    cout << sum << endl;
  }

  return 0;
}
