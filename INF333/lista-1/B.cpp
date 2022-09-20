#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, B, H, W;

  while (cin >> N >> B >> H >> W) {
    int min = B + 1;
    for (int i = 0; i < H; i++) {
      int p;
      cin >> p;
      for (int j = 0; j < W; j++) {
        int a;
        cin >> a;
        if (a >= N && p * N <= min) {
          min = p * N;
        }
      }
    }

    if (min <= B)
      cout << min << "\n";
    else
      cout << "stay home\n";
  }
}