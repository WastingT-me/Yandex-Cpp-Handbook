#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> field(m, vector<char>(n, '0'));

    vector<pair<int, int>> mines(k);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        mines[i] = {x - 1, y - 1};
        field[x - 1][y - 1] = '*';
    }

    for (const auto& mine : mines) {
        int x = mine.first;
        int y = mine.second;

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] != '*') {
                    field[nx][ny]++;
                }
            }
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}