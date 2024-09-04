#include <iostream>
#include <vector>

std::vector<int> findInversePermutation(const std::vector<int>& permutation) {
    int n = permutation.size();
    std::vector<int> inverse(n);

    for (int i = 0; i < n; ++i) {
        inverse[permutation[i] - 1] = i + 1;
    }

    return inverse;
}

int main() {

    std::vector<int> permutation;
    int x;
    int n;
    std::cin >> n;
    while (std::cin >> x) { 
        permutation.push_back(x);  
    }
    std::vector<int> inverse = findInversePermutation(permutation);

    for (size_t i = 0; i < inverse.size(); ++i) {
        std::cout << inverse[i] << " ";
    }

    return 0;
}