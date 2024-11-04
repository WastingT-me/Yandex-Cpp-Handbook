#include <iostream>
#include <vector>
#include <utility>

template<typename T>
class Table {
public:
    Table(size_t rows, size_t cols) 
        : data(rows, std::vector<T>(cols)), rowCount(rows), colCount(cols) {}

    const std::vector<T>& operator[](size_t index) const {
        return data[index];
    }

    std::vector<T>& operator[](size_t index) {
        return data[index];
    }

    void resize(size_t newRows, size_t newCols) {
        std::vector<std::vector<T>> newData(newRows, std::vector<T>(newCols));
        for (size_t i = 0; i < std::min(rowCount, newRows); ++i) {
            for (size_t j = 0; j < std::min(colCount, newCols); ++j) {
                newData[i][j] = data[i][j];
            }
        }
        data = std::move(newData);
        rowCount = newRows;
        colCount = newCols;
    }

    std::pair<size_t, size_t> size() const {
        return {rowCount, colCount};
    }

private:
    std::vector<std::vector<T>> data;
    size_t rowCount;
    size_t colCount;
};