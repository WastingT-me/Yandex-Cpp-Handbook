#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> seen_numbers;
    int number;

    while (std::cin >> number) {
        if (seen_numbers.count(number)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
            seen_numbers.insert(number);
        }
    }

    return 0;
}