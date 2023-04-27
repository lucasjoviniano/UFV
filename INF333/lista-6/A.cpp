#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    int l, r;
    vector<pair<int, int>> v;

    while (cin >> l >> r) {
      if (l == 0 && r == 0)
        break;
      v.push_back(make_pair(l, r));
    }

    sort(all(v));
    vector<pair<int, int>> sol;

    int last = 0;
    bool covered = false;

    for (int i = 0; i < v.size() && !covered; i++) {
      if (v[i].first > last)
        break;

      pair<int, int> maxi = v[i];

      while (i < v.size() && v[i].first <= last) {
        if (v[i].second > maxi.second)
          maxi = v[i];
        i++;
      }

      if (i < v.size())
        i--;

      if (maxi.second > last) {
        last = maxi.second;
        sol.push_back(maxi);
      }

      if (last >= m)
        covered = true;
    }

    if (covered) {
      cout << sol.size() << endl;
      for (auto &p : sol)
        cout << p.first << " " << p.second << endl;
    } else
      cout << "0\n";

    if (n != 0)
      cout << endl;
  }
  return 0;
}
