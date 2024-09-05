#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    double sum = 0;
    double curr = 1;
    for (int i = 1; i <= n;++i) {
        sum+=curr;
        double sign = -(std::signbit(curr) - 0.5) * 2;
        curr = static_cast<double>(1) / (i + 1) * (-1) * sign;
    }
    std::cout << sum;

    return 0;
}