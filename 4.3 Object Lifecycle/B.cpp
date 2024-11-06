#include "logger.h"

int main() {
    Logger log1;
    { 
        Logger log2 = log1;
    }
    return 0;
}