// Algoritmo Edmons - Karp implementado por mim na disciplina INF333

#include <bits/stdc++.h>
#include <limits>

using namespace std;

int edmons_karp(int s, int t, vector<vector<int>> &graph) {
  int sum = 0;

  vector<int> parent(graph.size(), 0);
  vector<vector<int>> flow(graph.size(), vector<int>(graph.size(), 0));

  while (true) {
    vector<int> capacity(graph.size());

    capacity[s] = numeric_limits<int>::max();

    queue<int> q;
    q.push(s);

    while (!q.empty() && capacity[t] == 0) {
      int curr = q.front();
      q.pop();

      for (int i = 1; i < graph.size(); i++) {
        if (capacity[i] == 0 && graph[curr][i] > flow[curr][i]) {
          q.push(i);
          parent[i] = curr;
          capacity[i] = min(capacity[curr], graph[curr][i] - flow[curr][i]);
        }
      }
    }

    if (capacity[t] == 0)
      break;

    for (int c = t; c != s; c = parent[c]) {
      flow[parent[c]][c] += capacity[t];
      flow[c][parent[c]] -= capacity[t];
    }
    sum += capacity[t];
  }
  return sum;
}

int main() {
  int t, shirts, m;
  string s, u, v;

  map<string, int> sizes;

  sizes["XXL"] = 1;
  sizes["XL"] = 2;
  sizes["L"] = 3;
  sizes["M"] = 4;
  sizes["S"] = 5;
  sizes["XS"] = 6;

  cin >> t;

  while (t--) {
    cin >> shirts >> m;
    int n = m + 12 + 2;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 1; i <= 6; i++) {
      graph[0][i] = numeric_limits<int>::max();
      graph[i][i + 6] = shirts / 6;
    }

    cin.ignore();

    for (int i = 1; i <= m; i++) {
      getline(cin, s);
      stringstream ss(s);
      ss >> u >> v;
      graph[sizes[u] + 6][12 + i] = 1;
      graph[sizes[v] + 6][12 + i] = 1;
      graph[i + 12][n - 1] = 1;
    }

    int ans = edmons_karp(0, n - 1, graph);

    if (ans >= m)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
