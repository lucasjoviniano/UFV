#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, t = 0;

  while (true) {
    cin >> n >> m;

    if (n == 0 && m == 0)
      break;

    vector<vector<int>> graph(n, vector<int>(n, INT_MIN));

    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;

      graph[u][v] = graph[v][u] = w;
    }

    int beg, end, p;
    cin >> beg >> end >> p;
    beg--;
    end--;

    // Programação Dinâmica
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          graph[j][k] = max(graph[j][k], min(graph[j][i], graph[i][k]));

    int res = ceil((double)p / (double)(graph[beg][end] - 1));

    cout << "Scenario #" << ++t << endl;
    cout << "Minimum Number of Trips = " << res << endl << endl;
  }
  return 0;
}
