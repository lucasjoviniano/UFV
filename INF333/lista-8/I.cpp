#include <bits/stdc++.h>

using namespace std;

void dfs(int beg, const vector<vector<int>> &g, vector<bool> &visited,
         vector<int> &topological) {
  visited[beg] = true;

  for (int u : g[beg]) {
    if (!visited[u])
      dfs(u, g, visited, topological);
  }

  topological.push_back(beg);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
  }
}
