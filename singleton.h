#ifndef __SINGLETON__H__
#define __SINGLETON__H__

class Logger {
    static Logger* logger;
    Logger() {};
    public: 
        // delete copy, move constructor
        Logger(const Logger& logger) = delete;
        Logger(const Logger&& logger) = delete;
        // delete copy, move assignment
        Logger& operator=(const Logger& logger) = delete;
        Logger& operator=(const Logger&& logger) = delete;
        static Logger* getInstance();
        static void deleteInstance();
        void warn() const;
        void info() const;
};
// V2: prendre avantage de static à l'intérieur d'une fonction, qui est instantié une seule fois même si la fonction est appelé plusieurs fois.
class SingletonLogger {
    SingletonLogger() {};
    public:
        static SingletonLogger& getInstance();
        // delete copy, move constructor
        SingletonLogger(const Logger& logger) = delete;
        SingletonLogger(const Logger&& logger) = delete;
        // delete copy, move assignment
        SingletonLogger& operator=(const Logger& logger) = delete;
        SingletonLogger& operator=(const Logger&& logger) = delete;
        void warn() const;
        void info() const;
        ~SingletonLogger();
};
#endif