
#include <iostream>
#include <string>
using namespace std;
bool checkPassword(const string& password) {
    if (password.length() < 8 || password.length() > 14) {
        return false;
    }
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char ch : password) {
        if (ch < 33 || ch > 126) {
            return false; 
        }
        if (islower(ch)) {
            hasLower = true;
        } else if (isupper(ch)) {
            hasUpper = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        } else {
            hasSpecial = true;
        }
    }
    int classesCount = hasLower + hasUpper + hasDigit + hasSpecial;
    return classesCount >= 3;
}
int main() {
    string password;
    cin >> password;
    if (checkPassword(password)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}