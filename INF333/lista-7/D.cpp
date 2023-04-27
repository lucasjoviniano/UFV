#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
  long long n;
  vector<vector<long long>> m(101, vector<long long>(101, 0));

  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        cin >> m[i][j];
        m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
      }

    long long ans = INT_MIN;
    for (int i0 = 0; i0 <= n; i0++)
      for (int j0 = 0; j0 <= n; j0++)
        for (int i1 = i0 + 1; i1 <= n; i1++)
          for (int j1 = j0 + 1; j1 <= n; j1++)
            ans = max(ans, m[i1][j1] + m[i0][j0] - m[i0][j1] - m[i1][j0]);

    cout << ans << endl;
  }

  return 0;
}
