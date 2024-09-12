#include <iostream>
#include <string>
#include <iterator>

template <typename Container>
void Print(const Container& container, const std::string& delimiter) {
    auto it = container.begin();
    if (it != container.end()) {
        std::cout << *it;  
        ++it;
    }
    while (it != container.end()) {
        std::cout << delimiter << *it; 
        ++it;
    }
    std::cout << "\n";  
}