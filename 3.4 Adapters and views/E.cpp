#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    int k;
    std::cin >> k;
    std::cin.ignore();

    std::unordered_map<std::string, int> word_count;
    std::string line, word;

    while (std::getline(std::cin, line)) {
        std::istringstream stream(line);
        while (stream >> word) {
            word_count[word]++;
        }
    }

    std::vector<std::pair<std::string, int>> words(word_count.begin(), word_count.end());

    std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });

    for (size_t i = 0; i < static_cast<size_t>(k) && i < words.size(); ++i) {
        std::cout << words[i].first << '\t' << words[i].second << '\n';
    }

    return 0;
}