#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

std::vector<double> partial_insertion_sort(const std::vector<double>& values, int k) {
    auto list = values;

    for (int i = 1; i < list.size(); i++) {
        int start = i > k - 1 ? k - 1 : i - 1;
        double elem = list[i];

        while (start >= 0 && elem < list[start]) {
            list[start + 1] = list[start];
            start--;
        }

        list[start + 1] = elem;
    }

    return list;
}

std::vector<double> partial_selection_sort(const std::vector<double>& values, int k) {
    auto list = values;
    for (int i = 0; i < k; i++) {
        int m = i;
        for (int j = i + 1; j < list.size(); j++) {
            if (list[j] < list[m]) m = j;
        }

        std::swap(list[i], list[m]);
    }

    return list;
}

int main() {

    std::vector<double> v(10);
    std::iota(v.begin(), v.end(), 1);

    auto test = v;
    std::shuffle(test.begin(), test.end(), std::mt19937{std::random_device{}()});

    auto ins = partial_insertion_sort(test, 10);
    auto sel = partial_selection_sort(test, 10);

    for (auto &i: ins) std::cout << i << " ";
    std::cout << std::endl;

    for (auto &i: sel) std::cout << i << " ";
    std::cout << std::endl;
}