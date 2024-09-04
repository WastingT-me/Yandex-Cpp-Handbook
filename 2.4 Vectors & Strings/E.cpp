#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, cleaned;
    getline(cin, s);

    for (char c : s) {
        if (c != ' ') {
            cleaned += c;
        }
    }

    int n = cleaned.length();
    bool is_palindrome = true;

    for (int i = 0; i < n / 2;++i) {
        if (cleaned[i] != cleaned[n - 1 - i]) {
            is_palindrome = false;
        }
    }
    if (is_palindrome) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}