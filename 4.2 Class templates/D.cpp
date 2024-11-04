#include <cstddef>
#include <vector>
#include <stdexcept>

template <typename T>
class Deque {
private:
    std::vector<T> head;
    std::vector<T> tail;

public:
    bool Empty() const {
        return head.empty() && tail.empty();
    }

    size_t Size() const {
        return head.size() + tail.size();
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator[](size_t i) const {
        if (i < head.size()) {
            return head[head.size() - 1 - i];
        } else {
            return tail[i - head.size()];
        }
    }

    T& operator[](size_t i) {
        if (i < head.size()) {
            return head[head.size() - 1 - i];
        } else {
            return tail[i - head.size()];
        }
    }

    const T& At(size_t i) const {
        if (i >= Size()) {
            throw std::out_of_range("Index out of range");
        }
        return (*this)[i];
    }

    T& At(size_t i) {
        if (i >= Size()) {
            throw std::out_of_range("Index out of range");
        }
        return (*this)[i];
    }

    const T& Front() const {
        if (head.empty()) {
            return tail.front();
        } else {
            return head.back();
        }
    }

    T& Front() {
        if (head.empty()) {
            return tail.front();
        } else {
            return head.back();
        }
    }

    const T& Back() const {
        if (tail.empty()) {
            return head.front();
        } else {
            return tail.back();
        }
    }

    T& Back() {
        if (tail.empty()) {
            return head.front();
        } else {
            return tail.back();
        }
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};