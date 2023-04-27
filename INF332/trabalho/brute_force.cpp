#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

struct Point {
  int x, y;
};

double distance2(const Point &p, const Point &q) {
  int x = p.x - q.x;
  int y = p.y - q.y;

  return std::sqrt(x * x + y * y);
}

double euclidean_distance(const std::vector<Point> &values,
                          const std::vector<int> &indexes) {

  double ans = 0;
  for (int i = 0; i < indexes.size(); i++) {
    if (i == 0 || i == indexes.size() - 1) {
      ans += distance2(values[0], values[i]);
      continue;
    }
    ans += distance2(values[indexes[i]], values[indexes[i - 1]]);
  }

  return ans;
}

int main() {
  int n;

  std::cin >> n;

  std::vector<Point> points(n);

  for (int i = 0; i < n; i++) {
    std::cin >> points[i].x >> points[i].y;
  }

  std::vector<int> indexes(n - 1);

  std::iota(indexes.begin(), indexes.end(), 1);

  Point origin = points[0];

  auto start = std::chrono::high_resolution_clock::now();
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  double best_distance = std::numeric_limits<double>::max();
  std::vector<int> cycle(indexes);

  while (std::next_permutation(indexes.begin(), indexes.end()) &&
         duration.count() < 3600000) {

    double dist = euclidean_distance(points, indexes);

    if (dist < best_distance) {
      best_distance = dist;
      cycle = indexes;
    }

    end = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  }

  std::cout << "Distance: " << best_distance << std::endl;
  for (int i : cycle) {
    std::cout << points[i].x << " " << points[i].y << std::endl;
  }

  std::cout << "Time: " << duration.count() << " ms" << std::endl;

  return 0;
}
