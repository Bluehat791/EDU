#include <iostream>

class LoggerGuard
{
    std::string log; 
    std::ostream& out_;
public:
    LoggerGuard(const std::string& message, std::ostream& out = std::cout)
        : log(message), out_(out)
        {
        }

    ~LoggerGuard()
    {
        out_ << log << "\n";
    }
};


int SomeFunction()
{
    return 12;
}

int SomeOtherFunction()
{
    return 13;
}

int FinalFunction()
{
    return 14;
}

int Function() {
    LoggerGuard logger("Function completed");

    int value = 1;
    try {
        value = SomeFunction();
        if (value == 0) {
            return value;
        }

        value = SomeOtherFunction();
        if (value == 0) {
            return value;
        }

        value = FinalFunction();  // might throw an exception
    } catch (...) {
        throw;  // throws the exception further.
    }

    return value;
}

int main()
{
    Function();
}