#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

class bignum {
private:
  std::vector<int> v;
  const int base = 1000 * 1000 * 1000;

  void fix() {
    while (this->v.size() > 1u && this->v.back() == 0) {
      this->v.pop_back();
    }
  }

public:

  bignum(std::string s) {
      v.clear();

      for (int i = s.length()-1; i > 0; i -=9) {
          v.push_back(std::atoi(i >= 9 ? s[i - 1] : s)
      }
  }

  const bool operator<(const bignum &other) {
    if (v.size() != other.v.size())
      return this->v.size() < other.v.size();
    for (int i = this->v.size() - 1; i >= 0; i--) {
      if (this->v[i] != other.v[i])
        return this->v[i] < other.v[i];
    }
    return false;
  }


};
