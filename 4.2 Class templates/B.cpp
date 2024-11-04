#include <deque>
#include <utility>

template <typename T, typename Container = std::deque<T>>
class Queue {
public:
    Queue() = default;

    const T& front() const {
        return container.front();
    }

    T& front() {
        return container.front();
    }

    void pop() {
        container.pop_front();
    }

    void push(const T& value) {
        container.push_back(value);
    }

    size_t size() const {
        return container.size();
    }

    bool empty() const {
        return container.empty();
    }

    bool operator==(const Queue& other) const {
        return container == other.container;
    }

    bool operator!=(const Queue& other) const {
        return !(*this == other);
    }

private:
    Container container;
};