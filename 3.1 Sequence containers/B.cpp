#include <iostream>
#include <deque>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::deque<std::string> stack;
    for (int i = 0; i < N; ++i) {
        std::string name, position;
        std::cin >> name >> position;
        if (position == "top") {
            stack.push_front(name);
        } else {
            stack.push_back(name);
        }
    }

    int M;
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        std::cin >> x;
        std::cout << stack[x - 1] << std::endl; 
    }

    return 0;
}