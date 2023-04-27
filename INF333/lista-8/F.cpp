#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void dfs(int beg, const vector<vector<int>> &g, vector<bool> &visited,
         stack<int> &order) {
  visited[beg] = true;

  for (int u : g[beg]) {
    if (!visited[u])
      dfs(u, g, visited, order);
  }

  order.push(beg);
}

void dfs(int beg, const vector<vector<int>> &g, vector<bool> &visited) {
  visited[beg] = true;

  for (int u : g[beg]) {
    if (!visited[u])
      dfs(u, g, visited);
  }
}

int main() {
  int t, n, m, u, v;
  int c = 1;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());

    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      u--;
      v--;

      g[u].push_back(v);
      // g[v].push_back(u);
    }

    vector<bool> visited(n, false);
    stack<int> order;

    for (int i = 0; i < visited.size(); i++) {
      if (!visited[i])
        dfs(i, g, visited, order);
    }

    fill(visited.begin(), visited.end(), false);
    int cont = 0;

    while (!order.empty()) {
      int w = order.top();
      order.pop();

      if (!visited[w]) {
        dfs(w, g, visited);
        cont++;
      }
    }

    cout << "Case " << c++ << ": " << cont << endl;
  }
}
