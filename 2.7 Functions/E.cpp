#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();           
    int n = matrix[0].size();        
    std::vector<std::vector<int>> transposed(n, std::vector<int>(m));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}