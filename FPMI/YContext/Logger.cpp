#include <iostream>

class Logger {
private:
    inline static int counter = 0;

    const int id;

public:
    Logger() : id(++counter) 
    {
        std::cout << "Logger(): " << id << "\n";
    }

    Logger(const Logger& other) : id(++counter)
    {
        std::cout << "Logger(const Logger&): " << id << " " << other.id << "\n";
    }

    Logger& operator = (const Logger& other)
    {
        std::cout << "Logger& operator = (const Logger&) " << id << " " << other.id << "\n";
        return *this; 
    }

    ~Logger()
    {
        std::cout << "~Logger() " << id << "\n";
    }
};