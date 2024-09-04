#include <iostream>
#include <cmath>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        std::cout << "YES\n"; 
    } else if (a + b > c && a + c > b && b + c > a) {
        std::cout << "NO\n";
    } else {
        std::cout << "UNDEFINED\n";
    }
    return 0;
}