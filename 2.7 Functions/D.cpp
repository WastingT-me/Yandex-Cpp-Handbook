#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    if (tokens.empty()) {
        return "";
    }
    
    std::string result = tokens[0];
    
    for (size_t i = 1; i < tokens.size(); ++i) {
        result += delimiter;
        result += tokens[i];
    }
    
    return result;
}