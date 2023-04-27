#include <bits/stdc++.h>
using namespace std;

bool bicolored(int beg, const vector<vector<int>> &g, vector<bool> &visited,
               vector<int> &color) {

  for (int u : g[beg]) {
    if (!visited[u]) {
      visited[u] = true;

      color[u] = 1 - color[beg];

      if (!bicolored(u, g, visited, color))
        return false;
    } else if (color[u] == color[beg]) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m, u, v;
  while (true) {
    cin >> n;
    if (n == 0)
      break;

    cin >> m;
    vector<vector<int>> g(n, vector<int>());

    for (int i = 0; i < m; i++) {
      cin >> u >> v;

      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> color(n, -1);

    if (!bicolored(0, g, visited, color)) {
      cout << "NOT ";
    }
    cout << "BICOLORABLE.\n";
  }
}
