#include <iostream>
#include <string>

class LoggerGuard {
public:
    LoggerGuard(const std::string& message, std::ostream& out = std::cout)
        : message_(message), out_(out) {}

    ~LoggerGuard() {
        out_ << message_ << "\n";
    }

private:
    std::string message_;   
    std::ostream& out_;    
};