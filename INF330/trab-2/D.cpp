#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void tarjan(int u, const vector<vector<int>> &adj, vector<int> &dfsParent,
            vector<int> &dfsNum, vector<int> &dfsLow,
            vector<bool> &isArticulation, vector<pair<int, int>> &bridges,
            int &dfsCount, int &rootChildren, int dfsRoot) {
  dfsLow[u] = dfsNum[u] = ++dfsCount; // dfsLow[u] <= dfsNum[u]
  for (int v : adj[u]) {
    // vertices nao descobertos tem tempo de descoberto (dfsNum) 0
    if (dfsNum[v] == 0) {
      dfsParent[v] = u; // pai de v e' u (v foi descoberto por u)
      if (u == dfsRoot) // caso especial... precisamos contar quantas vezes
                        // descobrimos vertices a partir da raiz para descobrir
                        // se raiz e' articulacao...
        rootChildren++;

      tarjan(v, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges,
             dfsCount, rootChildren, dfsRoot);

      if (dfsLow[v] >= dfsNum[u]) // apos visitar v recursivamente, conseguimos
                                  // chegar em um vertice em v ou antes passando
                                  // por u? (sem voltar pela aresta v,u)
        isArticulation[u] = true; // store this information first
      if (dfsLow[v] > dfsNum[u])  // ponte?
        bridges.push_back(make_pair(u, v));
      dfsLow[u] = min(dfsLow[u], dfsLow[v]); // update dfsLow[u]
    } else if (v != dfsParent[u]) // cheguei de volta em um vertice ja
                                  // descoberto... se nao passei pela aresta v,u
                                  // de volta --> ciclo...
      dfsLow[u] = min(dfsLow[u], dfsNum[v]); // atualize dfsLow...
  }
}

void tarjan(const vector<vector<int>> &adj, vector<bool> &isArticulation,
            vector<pair<int, int>> &bridges) {
  int nv = adj.size();
  isArticulation = vector<bool>(nv, false);
  bridges.resize(0);

  vector<int> dfsParent(nv, -1);
  vector<int> dfsLow(nv, 0);
  vector<int> dfsNum(nv, 0);
  int dfsCount = 0;

  // para multiplos CCs ...
  for (int i = 0; i < nv; i++) {
    if (dfsNum[i] == 0) {
      int rootChildren = 0; // resete para cada CC!!
      tarjan(i, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges,
             dfsCount, rootChildren, i);
      isArticulation[i] = rootChildren > 1;
    }
  }
}

int main() {
  int n;
  int u, t, v;
  char c;

  while (cin >> n) {
    vector<vector<int>> g(n, vector<int>());
    vector<bool> isArticulation;
    vector<pair<int, int>> bridges;

    for (int i = 0; i < n; i++) {
      cin >> u;
      cin >> c >> t >> c;
      for (int j = 0; j < t; j++) {
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }

    tarjan(g, isArticulation, bridges);

    for (auto &bridge : bridges) {
      if (bridge.first > bridge.second)
        swap(bridge.first, bridge.second);
    }

    sort(bridges.begin(), bridges.end());

    cout << bridges.size() << " critical links\n";

    for (auto &bridge : bridges) {
      cout << bridge.first << " - " << bridge.second << endl;
    }
    cout << endl;
  }

  return 0;
}
