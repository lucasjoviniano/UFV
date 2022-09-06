#include <iostream>

int main() {
    int n;

    std::cin >> n;

    while (n != 0) {
        std::cout << n * (n + 1) * (3 * n - n + 1) / 6 << "\n";
        std::cin >> n;
    }

    return 0;
}
