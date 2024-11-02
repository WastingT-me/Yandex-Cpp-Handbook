#include <iostream>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int> pq;
    std::string command;

    while (std::cin >> command) {
        if (command == "ADD") {
            int n;
            std::cin >> n;
            pq.push(n);
        } else if (command == "EXTRACT") {
            if (!pq.empty()) {
                std::cout << pq.top() << std::endl;
                pq.pop();
            } else {
                std::cout << "CANNOT" << std::endl;
            }
        } else if (command == "CLEAR") {
            while (!pq.empty()) {
                pq.pop();
            }
        }
    }

    return 0;
}