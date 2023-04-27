#include <bits/stdc++.h>
using namespace std;

long long augment(long long n, long long v, long long m, long long s,
                  vector<long long> &p, vector<vector<long long>> &res) {
  long long f = 0;

  if (v == s) {
    f = m;
  } else {
    f = augment(n, p[v], min(m, res[p[v]][v]), s, p, res);
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }

  return f;
}

long long edmonds_karp(const vector<vector<long long>> &graph, long long s,
                       long long t, vector<long long> &p,
                       vector<vector<long long>> &res) {

  long long flow = 0, f;

  while (true) {
    vector<bool> visited(graph.size(), false);
    queue<long long> q;

    visited[s] = true;
    q.push(s);
    p.assign(graph.size(), graph.size());

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      if (u == t) {
        break;
      }

      for (long long v : graph[u]) {
        if (res[u][v] > 0 && !visited[v]) {
          visited[v] = true;
          q.push(v);
          p[v] = u;
        }
      }
    }

    f = augment(graph.size(), t, std::numeric_limits<long long>::max(), s, p,
                res);

    if (f == 0) {
      break;
    }

    flow += f;
  }

  return flow;
}

int main() {
  long long m, w;

  while (cin >> m >> w) {
    if (m == 0 && w == 0)
      break;

    long long n = 2 * m;
    long long s = 0, t = n - 1;

    vector<vector<long long>> graph(n, vector<long long>());
    vector<long long> p(n, n);
    vector<vector<long long>> res(n, vector<long long>(n, 0));

    graph[0].push_back(m);
    graph[m].push_back(0);

    graph[m - 1].push_back(2 * m - 1);
    graph[2 * m - 1].push_back(m - 1);

    res[0][m] = res[m - 1][2 * m - 1] = numeric_limits<long long>::max();

    for (long long i = 0; i + 2 < m; i++) {
      long long u, c;
      cin >> u >> c;

      u--;

      graph[u].push_back(m + 1);
      graph[m + 1].push_back(u);
      res[u][m + u] = c;
    }

    for (long long i = 0; i < w; i++) {
      long long u, v, c;

      cin >> u >> v >> c;

      u--;
      v--;

      graph[m + u].push_back(v);
      graph[v].push_back(m + u);

      graph[m + v].push_back(u);
      graph[u].push_back(m + v);

      res[m + u][v] = res[m + v][u] = c;
    }

    cout << edmonds_karp(graph, s, t, p, res) << endl;
  }
}
