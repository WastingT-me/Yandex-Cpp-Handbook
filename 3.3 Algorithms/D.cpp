#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> array1(n), array2(k);

    for (int i = 0; i < n; ++i) {
        std::cin >> array1[i];
    }

    for (int i = 0; i < k; ++i) {
        std::cin >> array2[i];
    }

    for (int i = 0; i < k; ++i) {
        int target = array2[i];
        auto lb = std::lower_bound(array1.begin(), array1.end(), target);

        if (lb == array1.begin()) {
            std::cout << *lb << '\n';
        } else if (lb == array1.end()) {
            std::cout << array1.back() << '\n';
        } else {
            int next_value = *lb;
            int prev_value = *(lb - 1);

            if (std::abs(target - prev_value) <= std::abs(next_value - target)) {
                std::cout << prev_value << '\n';
            } else {
                std::cout << next_value << '\n';
            }
        }
    }

    return 0;
}