#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> v(1000, 0);
  long long int ans, cur, mid;

  int n, q, cs = 1;
  while (cin >> n) {
    if (n == 0)
      break;
    cout << "Case " << cs++ << ":\n";

    for (int i = 0; i < n; i++)
      cin >> v[i];

    cin >> q;

    while (q--) {
      cin >> mid;
      ans = v[0] + v[1];
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          cur = v[i] + v[j];
          if (abs(ans - mid) > abs(cur - mid))
            ans = cur;
        }
      }
      printf("Closest sum to %lld is %lld.\n", mid, ans);
    }
  }
  return 0;
}
