#include "logger.h"

int main() {
    Logger log1;
    Logger log2 = std::move(log1);
    return 0;
}