#include <iostream>
#include <deque>
#include <string>

void MakeTrain() {
    std::deque<int> train;
    std::string command;
    
    while (std::cin >> command) {
        if (command[0] == '+') {
            int W;
            std::cin >> W;
            if (command == "+left") {
                train.push_front(W);
            } else if (command == "+right") {
                train.push_back(W);
            }
        } else if (command[0] == '-') {
            int N;
            std::cin >> N;
            if (static_cast<size_t>(N) >= train.size()) {
                train.clear();
            } else {
                if (command == "-left") {
                    train.erase(train.begin(), train.begin() + N);
                } else if (command == "-right") {
                    train.erase(train.end() - N, train.end());
                }
            }
        }
    }
    
    for (int wagon : train) {
        std::cout << wagon << " ";
    }
    std::cout << std::endl;
}