#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, set<string>> page_keywords;
    
    for (int i = 0; i < n; ++i) {
        string word;
        int page;
        cin >> word >> page;
        page_keywords[page].insert(word);
    }
    
    for (const auto& entry : page_keywords) {
        cout << entry.first;
        for (const auto& word : entry.second) {
            cout << " " << word;
        }
        cout << endl;
    }
    
    return 0;
}