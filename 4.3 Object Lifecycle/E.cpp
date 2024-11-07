#include "logger.h"

int main() {
    Logger log1;
    Logger log2;
    Logger log3;
    {
        Logger temp = std::move(log2);
    }
    return 0;
}