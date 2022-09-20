#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> allSubstrings(const string &base) {
  vector<string> subs;
  for (int beg = 0; beg <= base.size(); beg++) {
    for (int end = 0; end <= base.size() - beg; end++) {
      subs.push_back(base.substr(beg, end));
    }
  }
  return subs;
}

bool is_palindrome(const string &st1) {
  return st1 == string(st1.cbegin(), st1.cend());
}

int main() {
  string s;
  getline(cin, s);
  auto subs = allSubstrings(s);
  vector<string> not_palindromes;

  copy_if(subs.begin(), subs.end(), back_inserter(not_palindromes),
          [](string x) { return !is_palindrome(x); });

  if (not_palindromes.empty()) {
    cout << "0\n";
    return 0;
  }

  auto largest = max_element(
      not_palindromes.begin(), not_palindromes.end(),
      [](const auto &a, const auto &b) { return a.size() < b.size(); });

  cout << largest->size() << endl;
  return 0;
}
