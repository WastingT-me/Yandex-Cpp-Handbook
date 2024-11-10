#include <exception>
#include <functional>
#include <optional>

void Sleep(int ms);

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
                                  int retryCount, int sleepTime, bool throwLast) {
    for (int attempt = 0; attempt <= retryCount; ++attempt) {
        try {
            return func();
        } catch (const Exception& ex) {
            if (attempt == retryCount) {
                if (throwLast) {
                    throw;
                } else {
                    return std::nullopt;
                }
            }
            Sleep(sleepTime);
        }
    }
    return std::nullopt; 
}