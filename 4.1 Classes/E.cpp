#include <iostream>
#include <vector>

class TicTacToe {
public:
    const size_t N; 
    const size_t K;  

private:
    std::vector<std::vector<int>> Table;

    int currentPlayer;

public:
    TicTacToe(size_t n, size_t k) : N(n), K(k), Table(n, std::vector<int>(n, 0)), currentPlayer(1) {}

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return currentPlayer;
    }

    bool Set(size_t i, size_t j) {  
        if (Table[i][j] != 0) return false; 
        Table[i][j] = currentPlayer;
        bool wins = CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
        currentPlayer = currentPlayer % 2 + 1;
        return wins;
    }

private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 1;
        while (j >= d1 && Table[i][j - d1] == Table[i][j]) ++d1;

        size_t d2 = 1;
        while (j + d2 < N && Table[i][j + d2] == Table[i][j]) ++d2;

        return d1 + d2 - 1 >= K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        size_t d1 = 1;
        while (i >= d1 && Table[i - d1][j] == Table[i][j]) ++d1;

        size_t d2 = 1;
        while (i + d2 < N && Table[i + d2][j] == Table[i][j]) ++d2;

        return d1 + d2 - 1 >= K;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        size_t d1 = 1;
        while (i >= d1 && j >= d1 && Table[i - d1][j - d1] == Table[i][j]) ++d1;

        size_t d2 = 1;
        while (i + d2 < N && j + d2 < N && Table[i + d2][j + d2] == Table[i][j]) ++d2;

        return d1 + d2 - 1 >= K;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        size_t d1 = 1;
        while (i >= d1 && j + d1 < N && Table[i - d1][j + d1] == Table[i][j]) ++d1;

        size_t d2 = 1;
        while (i + d2 < N && j >= d2 && Table[i + d2][j - d2] == Table[i][j]) ++d2;

        return d1 + d2 - 1 >= K;
    }
};

std::ostream& operator<<(std::ostream& out, const TicTacToe& field) {
    for (size_t i = 0; i != field.N; ++i) {
        for (size_t j = 0; j != field.N; ++j) {
            switch (field(i, j)) {
                case 0:
                    out << '.';
                    break;
                case 1:
                    out << 'X';
                    break;
                case 2:
                    out << 'O';
                    break;
            }
        }
        out << "\n";
    }
    return out;
}