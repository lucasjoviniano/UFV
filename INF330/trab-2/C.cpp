#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int beg, const vector<vector<int>> &g, vector<bool> &visited) {
  visited[beg] = true;

  for (auto u : g[beg])
    if (!visited[u])
      dfs(u, g, visited);
}

double distance(const pair<int, int> &a, const pair<int, int> &b) {
  double d = pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
  return sqrt(d);
}

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0)
      break;

    vector<pair<double, int>> pos(n);

    for (int i = 0; i < n; i++)
      cin >> pos[i].first >> pos[i].second;

    auto beg = pos[0];

    sort(pos.begin(), pos.end());

    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++) {
      vector<pair<double, int>> dis;

      for (int j = 0; j < n; j++) {
        if (i != j)
          dis.emplace_back(distance(pos[i], pos[j]), j);
      }

      sort(dis.begin(), dis.end());

      g[i].push_back(dis.begin()->second);
      g[i].push_back(next(dis.begin())->second);
    }

    int u;

    for (int i = 0; i < n; i++) {
      if (pos[i] == beg) {
        u = i;
        break;
      }
    }

    vector<bool> visited(g.size(), false);
    dfs(u, g, visited);

    if (any_of(visited.begin(), visited.end(), [](bool x) { return !x; })) {
      cout << "There are stations that are unreachable.\n";
    } else {
      cout << "All stations are reachable.\n";
    }
  }
}
