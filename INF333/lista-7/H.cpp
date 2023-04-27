#include <iostream>
#include <string>

using namespace std;

int ans, matrix[102][102], dp[102][102];

int best(int row, int col) {
  if (dp[row][col] != -1)
    return dp[row][col];

  // Try up, down, left and right
  int best_so_far = 0;
  if (matrix[row - 1][col] < matrix[row][col])
    best_so_far = max(best_so_far, 1 + best(row - 1, col));

  if (matrix[row + 1][col] < matrix[row][col])
    best_so_far = max(best_so_far, 1 + best(row + 1, col));

  if (matrix[row][col - 1] < matrix[row][col])
    best_so_far = max(best_so_far, 1 + best(row, col - 1));

  if (matrix[row][col + 1] < matrix[row][col])
    best_so_far = max(best_so_far, 1 + best(row, col + 1));

  ans = max(ans, best_so_far);

  return dp[row][col] = best_so_far;
}

int main() {
  int n, m, t;
  string name;
  cin >> t;

  while (t--) {
    cin >> name >> n >> m;

    ans = 0;

    for (int i = 0; i < 102; i++)
      for (int j = 0; j < 102; j++)
        matrix[i][j] = 200, dp[i][j] = -1;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> matrix[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        best(i, j);

    cout << name << ": " << 1 + ans << endl;
  }
  return 0;
}
