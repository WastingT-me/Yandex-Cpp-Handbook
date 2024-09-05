#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    int sum = 0;
    while (n >= 10) {
        sum += n % 10;
        n /= 10;
    }
    std::cout << sum + n;

    return 0;
}