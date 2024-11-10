#include "address.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    
    while (getline(std::cin, line)) {
        try {
            Address address;
            Parse(line, &address);
            Unify(&address);
            std::cout << Format(address) << "\n";
        } catch (...) {
            std::cout << "exception\n";
        }
    }
}