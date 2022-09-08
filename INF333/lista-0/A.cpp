#include <iostream>
#include <vector>

int main() {
    int dinners, alumni, presence;

    std::cin >> alumni >> dinners;

    while (dinners != 0 && alumni != 0) {
        std::vector<int> v(alumni, 0);

        for (int i = 0; i < dinners; i++) {
            for (int j = 0; j < alumni; j++) {
                std::cin >> presence;

                v[j] += presence;
            }
        }
        
        bool perfect = false;

        for (int i = 0; i < alumni; i++) {
            if (v[i] == dinners) perfect = true;
        }

        if (perfect) std::cout << "yes\n";
        else std::cout << "no\n";

        std::cin >> alumni >> dinners;
    }

    return 0;
}
