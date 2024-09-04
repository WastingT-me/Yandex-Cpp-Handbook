#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<std::string> data;
    std::string line;

    while (std::getline(std::cin, line)) {
        data.push_back(line);
    }

    std::sort(data.begin(), data.end(), std::greater<std::string>());

    for (const auto& str : data) {
        std::cout << str << std::endl;
    }

    return 0;
}