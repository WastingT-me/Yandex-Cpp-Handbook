#include "logger.h"

int main() {
    Logger log1;
    Logger log2;
    log1 = log2;
    log1 = std::move(log2);
    return 0;
}