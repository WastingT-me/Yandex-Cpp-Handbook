#include "logger.h"

int main() {
    Logger log1;
    Logger* log2 = new Logger;
    Logger log3;
    delete log2;
    return 0;
}