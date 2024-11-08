#include <iostream>
#include <string>
#include <vector>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string& item) = 0;
    virtual void EndArray() = 0;
    virtual ~Serializer() = default;  
};

class JsonSerializer : public Serializer {
public:
    void BeginArray() override {
        if (!first_item_) {
            std::cout << ",";
        }
        std::cout << "[";
        first_item_ = true;
        contexts_.push_back(Context::Array);
    }

    void AddArrayItem(const std::string& item) override {
        if (!first_item_) {
            std::cout << ",";
        }
        std::cout << "\"" << item << "\"";
        first_item_ = false;
    }

    void EndArray() override {
        std::cout << "]";
        contexts_.pop_back();
        first_item_ = contexts_.empty() ? true : false;
    }

private:
    enum class Context { Array };
    std::vector<Context> contexts_;  
    bool first_item_ = true;         
};