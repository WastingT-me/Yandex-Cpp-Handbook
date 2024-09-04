#include <iostream>
#include <cmath>
int main() {
    int a;
    std::cin >> a;
    if (a % 400 == 0 || ((a % 4 == 0) && !(a % 100 == 0))) {
        std::cout << "YES\n"; 
    } else {
        std::cout << "NO\n";
    } 
    return 0;
}