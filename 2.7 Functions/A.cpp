#include <iostream>
#include <vector>
#include <limits>
#include <utility>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    size_t max_row = 0;
    size_t max_col = 0;
    int max_value = std::numeric_limits<int>::min();

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > max_value || 
               (matrix[i][j] == max_value && std::make_pair(i, j) < std::make_pair(max_row, max_col))) {
                max_value = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    return {max_row, max_col};
}