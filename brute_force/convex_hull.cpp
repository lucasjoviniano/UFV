#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

struct Point {
  int x, y;
};

bool cmp(const Point &p, const Point &other) {
  if (p.x == other.x)
    return p.x < other.x;
  return p.y < other.y;
}

int which_side_of_line(Point a, Point b, Point p) {
  return (p.x - a.x) * (b.y - a.y) - (p.y - a.y) * (b.x - a.x);
};

std::vector<Point> convex_hull(const std::vector<Point> &v) {
  std::vector<Point> ans;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (i == j)
        continue;
      bool flag = true;

      for (int k = 0; k < v.size(); k++) {
        if (k == i || k == j)
          continue;

        int d = which_side_of_line(v[i], v[j], v[k]);
        if (d < 0) {
          flag = false;
          break;
        }
      }

      if (flag) {
        ans.push_back(v[i]);
        ans.push_back(v[j]);
      }
    }
  }

  std::sort(ans.begin(), ans.end(), cmp);
  auto it = std::unique(ans.begin(), ans.end(), [](Point &a, Point &b) {
    return a.x == b.x && a.y == b.y;
  });

  ans.resize(std::distance(ans.begin(), it));

  return ans;
}

int main() {
  std::vector<Point> v(20);

  for (int i = 0; i < 20; i++) {
    std::cin >> v[i].x >> v[i].y;
  }

  auto ans = convex_hull(v);

  for (auto &i : ans)
    std::cout << i.x << " " << i.y << std::endl;
}
