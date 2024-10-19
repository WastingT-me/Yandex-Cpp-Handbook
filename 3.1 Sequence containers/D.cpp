#include <iostream>
#include <vector>
#include <string>

using namespace std;

void text_editor(vector<string>& file_lines, const vector<string>& commands) {
    size_t cursor = 0; 
    string clipboard = "";

    for (const string& command : commands) {
        if (command == "Down") {
            if (cursor < file_lines.size() - 2) { 
                cursor++;
            }
        } else if (command == "Up") {
            if (cursor > 0) {
                cursor--;
            }
        } else if (command == "Ctrl+X") {
            if (!file_lines[cursor].empty()) {
                clipboard = file_lines[cursor];
                file_lines.erase(file_lines.begin() + cursor);
                if (cursor >= file_lines.size()) {
                    cursor = file_lines.size() - 1;
                }
            }
        } else if (command == "Ctrl+V") {
            if (!clipboard.empty()) {
                file_lines.insert(file_lines.begin() + cursor, clipboard);
                cursor++;
            }
        }
    }

    for (size_t i = 0; i < file_lines.size() - 1; ++i) {
        cout << file_lines[i] << endl;
    }
}

int main() {
    vector<string> file_lines;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            file_lines.push_back(line);
            break;
        }
        file_lines.push_back(line);
    }

    vector<string> commands;
    while (getline(cin, line)) {
        commands.push_back(line);
    }

    text_editor(file_lines, commands);

    return 0;
}