#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

// Ваш код будет вставлен здесь:

class NotifierBase
{    
public:
    NotifierBase()
    {}


    virtual void Notify(std::string message) const = 0;
    virtual ~NotifierBase()
    {}
};

class SmsNotifier : public NotifierBase
{
    std::string address;
public:
    SmsNotifier(std::string a)
        : address(a)
        {}

    void Notify(std::string message) const override
    {
        SendSms(address, message);
    }
};

class EmailNotifier : public NotifierBase
{
    std::string address;
public:
    EmailNotifier(std::string a)
        : address(a)
        {}

    void Notify(std::string message) const override
    {
        SendEmail(address, message);
    }
};

// Реализуйте в вашем решении классы NotifierBase, SmsNotifier и EmailNotifier,
// чтобы следующий код заработал как ожидается:

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}