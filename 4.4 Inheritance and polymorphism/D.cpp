#include <vector>
#include <stdexcept>
#include <iterator>
#include <cmath>

template <typename T>
class AdvancedVector {
public:
    AdvancedVector() = default;

    AdvancedVector(const AdvancedVector& other) = default;  // Конструктор копирования

    template <typename Iterator>
    AdvancedVector(Iterator first, Iterator last) : data_(first, last) {}  // Шаблонный конструктор

    AdvancedVector& operator=(const AdvancedVector& other) = default;  // Оператор присваивания

    bool operator==(const AdvancedVector& other) const {
        return data_ == other.data_;
    }

    bool operator!=(const AdvancedVector& other) const {
        return !(*this == other);
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }

    void push_back(const T& value) {
        data_.push_back(value);
    }

    void pop_back() {
        data_.pop_back();
    }

    const T& operator[](int index) const {
        return AccessElement(index);
    }

    T& operator[](int index) {
        return AccessElement(index);
    }

private:
    std::vector<T> data_;

    T& AccessElement(int index) const {
        if (index >= 0) {
            if (static_cast<size_t>(index) >= data_.size()) {
                throw std::out_of_range("Index out of range");
            }
            return const_cast<T&>(data_[index]);
        } else {
            if (static_cast<size_t>(-index) > data_.size()) {
                throw std::out_of_range("Index out of range");
            }
            return const_cast<T&>(data_[data_.size() + index]);
        }
    }
};