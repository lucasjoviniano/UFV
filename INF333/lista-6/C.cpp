#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
  int n, m, aux;

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    vector<int> d(n);
    vector<int> k(m);

    for (int i = 0; i < n; i++)
      cin >> d[i];

    for (int i = 0; i < m; i++)
      cin >> k[i];

    sort(all(d));
    sort(all(k));

    int cost = 0;
    bool flag = true;

    for (int i = 0, j = 0; i < n && flag; i++) {
      while (j < m && k[j] < d[i])
        j++;

      if (j == m)
        flag = false;
      else
        cost += k[j++];
    }

    if (flag)
      cout << cost << endl;
    else
      cout << "Loowater is doomed!\n";
  }
}
