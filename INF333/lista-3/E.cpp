#include <iostream>
using namespace std;

long long reverse(long long num) {
  long long reversed = 0;
  while (num > 0) {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }
  return reversed;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int count = 0;
    long long num;
    cin >> num;
    auto rev = reverse(num);
    while (num != rev) {
      num += rev;
      rev = reverse(num);
      count++;
    }

    cout << count << ' ' << num << endl;
  }

  return 0;
}
