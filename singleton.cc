#include "singleton.h"
#include <iostream>

// First type of implementation.

Logger *Logger::getInstance()
    {
        if (logger == nullptr)
        {
            logger = new Logger();
            return logger;
        };
        return logger;
    }
void Logger::deleteInstance() {
    std::cout << "Deleted" << std::endl;
    if(logger != nullptr) delete logger;
}
void Logger::warn() const
    {
        std::cout << "Warn message" << std::endl;
    }

void Logger::info() const
    {
        std::cout << "Info message" << std::endl;
    }

// Static member variable: exists only one instance between all objects, cannot be initialized inside the constructor. Must be explicitly initialzied using this type of initialization.
Logger *Logger::logger = nullptr;



SingletonLogger& SingletonLogger::getInstance() {
    static SingletonLogger singletonLogger;
    return singletonLogger;
}
void SingletonLogger::warn() const
    {
        std::cout << "Warn message" << std::endl;
    }

void SingletonLogger::info() const
    {
        std::cout << "Info message" << std::endl;
    }
SingletonLogger::~SingletonLogger()  {
    std::cout << "Delete called" << std::endl;
}

int main()
{
    Logger *logger1{Logger::getInstance()};
    Logger *logger2{Logger::getInstance()};
    std::cout << logger1 << std::endl;
    std::cout << logger2 << std::endl;
    std::cout << (logger1 == logger2) << std::endl;
    logger1->info();
    logger1->warn();
    // explciitly calling delete;
    Logger::deleteInstance();
    // better way.
    SingletonLogger& slogger1{SingletonLogger::getInstance()};
    SingletonLogger& slogger2{SingletonLogger::getInstance()};
    std::cout << &slogger1 << std::endl;
    std::cout << &slogger2 << std::endl;
    std::cout << (&slogger1 == &slogger2) << std::endl;
    slogger1.info();
    slogger1.warn();

    return 0;
}