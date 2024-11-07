#include "logger.h"
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<Logger*> loggers;
    for (int i = 0; i < n; ++i) {
        loggers.push_back(new Logger());
    }

    for (int i = n - 1; i >= 0; --i) {
        delete loggers[i];
    }

    return 0;
}