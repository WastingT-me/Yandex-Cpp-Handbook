#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string word;
    std::set<char> common_letters;
    bool first_word = true;

    while (std::cin >> word) {
        std::set<char> current_word_letters(word.begin(), word.end());
        if (first_word) {
            common_letters = current_word_letters;
            first_word = false;
        } else {
            std::set<char> intersection;
            std::set_intersection(common_letters.begin(), common_letters.end(),
                                  current_word_letters.begin(), current_word_letters.end(),
                                  std::inserter(intersection, intersection.begin()));
            common_letters = intersection;
        }
    }

    for (char letter : common_letters) {
        std::cout << letter;
    }

    std::cout << std::endl;

    return 0;
}