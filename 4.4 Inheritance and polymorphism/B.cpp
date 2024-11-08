#include <string>

class NotifierBase {
public:
    virtual void Notify(const std::string& message) const = 0;  
    virtual ~NotifierBase() = default;  
};

class SmsNotifier : public NotifierBase {
public:
    explicit SmsNotifier(const std::string& number) : number_(number) {}

    void Notify(const std::string& message) const override {
        SendSms(number_, message);
    }

private:
    std::string number_;
};

class EmailNotifier : public NotifierBase {
public:
    explicit EmailNotifier(const std::string& email) : email_(email) {}

    void Notify(const std::string& message) const override {
        SendEmail(email_, message);
    }

private:
    std::string email_;
};