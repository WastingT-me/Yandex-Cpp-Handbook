#include <iostream>
#include <cmath>
int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (std::abs(a - c) == std::abs(b - d) || a == c || b == d) {
        std::cout << "YES\n"; 
    } else {
        std::cout << "NO\n";
    }
    return 0;
}