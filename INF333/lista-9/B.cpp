#include <bits/stdc++.h>
using namespace std;

#define NN 10000000

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

// BFS stuff
int q[NN], previous[NN];

int dinic(int n, int s, int t) {
  int flow = 0;

  while (true) {
    // find an augmenting path
    memset(previous, -1, sizeof(previous));
    int qf = 0, qb = 0;
    previous[q[qb++] = s] = -2;
    while (qb > qf && previous[t] == -1)
      for (int u = q[qf++], i = 0, v; i < deg[u]; i++)
        if (previous[v = adj[u][i]] == -1 && cap[u][v])
          previous[q[qb++] = v] = u;

    // see if we're done
    if (previous[t] == -1)
      break;

    // try finding more paths
    for (int z = 0; z < n; z++)
      if (cap[z][t] && previous[z] != -1) {
        int bot = cap[z][t];
        for (int v = z, u = previous[v]; u >= 0; v = u, u = previous[v])
          bot = min(bot, cap[u][v]);
        if (!bot)
          continue;

        cap[z][t] -= bot;
        cap[t][z] += bot;
        for (int v = z, u = previous[v]; u >= 0; v = u, u = previous[v]) {
          cap[u][v] -= bot;
          cap[v][u] += bot;
        }
        flow += bot;
      }
  }

  return flow;
}
