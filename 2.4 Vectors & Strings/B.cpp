#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string soundex(const string &word) {
    unordered_map<char, char> soundexMap = {
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'},
        {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'},
        {'l', '4'},
        {'m', '5'}, {'n', '5'},
        {'r', '6'}
    };

    string result = word.substr(0, 1);
    char previousDigit = '\0';

    for (size_t i = 1; i < word.size(); ++i) {
        char currentChar = word[i];
        
        if (soundexMap.find(currentChar) == soundexMap.end()) {
            continue;
        }

        char currentDigit = soundexMap[currentChar];
        
        if (currentDigit != previousDigit) {
            result += currentDigit;
            previousDigit = currentDigit;
        }
    }

    result = result.substr(0, 4);
    while (result.length() < 4) {
        result += '0';
    }

    return result;
}

int main() {
    string word;
    cin >> word;
    cout << soundex(word) << endl;
    return 0;
}