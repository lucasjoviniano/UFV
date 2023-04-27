#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, u;
  cin >> n;

  vector<vector<long long>> graph(n, vector<long long>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  vector<long long> x(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> x[i];
    x[i]--;
  }

  vector<long long> dp(n, 0);

  for (int k = n - 1; k >= 0; k--) {
    long long v = x[k];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][v] + graph[v][j] < graph[i][j]) {
          graph[i][j] = graph[i][v] + graph[v][j];
        }
      }
    }

    for (int i = k; i < n; i++) {
      for (int j = k; j < n; j++) {
        sum += graph[x[i]][x[j]];
      }
    }

    dp[k] = sum;
  }

  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }

  cout << endl;
}