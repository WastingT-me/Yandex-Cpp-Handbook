#include <vector>
#include <string>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string current;
    for (char ch : str) {
        if (ch == delimiter) {
            result.push_back(current);
            current.clear();
        } else {
            current += ch;
        }
    }
    result.push_back(current);
    return result;
}