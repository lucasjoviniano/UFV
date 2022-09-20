#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool balanced(std::string s) {
  std::stack<char> closing;
  std::unordered_map<char, char> m({{'(', ')'}, {'[', ']'}});
  std::unordered_set<char> b({')', ']'});

  for (auto c : s) {
    if (m.find(c) != m.end()) {
      closing.push(c);
    } else if (b.find(c) != b.end()) {
      if (closing.empty() || m[closing.top()] != c) {
        return false;
      }
      closing.pop();
    }
  }

  return closing.empty();
}

int main() {
  int n;

  std::cin >> n;
  std::string s;
  getline(std::cin, s);

  for (int i = 0; i < n; i++) {
    getline(std::cin, s);
    if (s.size() == 0) {
      std::cout << "Yes\n";
      continue;
    }
    if (balanced(s)) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }

  return 0;
}