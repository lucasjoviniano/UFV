#include <iostream>
#include <string>
#include <vector>
using namespace std;

string generate_sequence(int n) {
  string ans = "";
  for (long int i = 1; i <= n; i++) {
    ans += to_string(i);
  }

  return ans;
}

vector<long long> group_by_digit(int n) {
  auto str = generate_sequence(n);

  vector<long long> digits(10, 0);

  for (int i = 0; i < str.length(); i++) {
    digits[str[i] - '0']++;
  }

  return digits;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long int c;
    cin >> c;

    auto ans = group_by_digit(c);

    for (int j = 0; j < ans.size() - 1; j++) {
      cout << ans[j] << " ";
    }

    cout << *(ans.end() - 1) << '\n';
  }

  return 0;
}
