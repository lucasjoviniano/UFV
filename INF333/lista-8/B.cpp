#include <bits/stdc++.h>

using namespace std;

void dfs(int beg, const vector<vector<int>> &g, vector<bool> &visited) {
  visited[beg] = true;

  for (int u : g[beg]) {
    if (!visited[u])
      dfs(u, g, visited);
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    char c;
    cin >> c;
    int n = c - 'A' + 1;

    cin.ignore();

    vector<vector<int>> g(n, vector<int>());
    string s;

    while (getline(cin, s)) {
      if (s.empty())
        break;

      g[s[0] - 'A'].push_back(s[1] - 'A');
      g[s[1] - 'A'].push_back(s[0] - 'A');
    }

    vector<bool> visited(n, false);
    int cont = 0;

    for (int i = 0; i < g.size(); i++) {
      if (!visited[i]) {
        cont++;
        dfs(i, g, visited);
      }
    }

    cout << cont << endl;

    if (t)
      cout << endl;
  }
}
