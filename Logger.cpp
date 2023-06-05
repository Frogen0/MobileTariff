#include "Logger.h"

Logger::Logger() {
    logfile.open("log.txt", std::ios::app);
}

Logger::~Logger() {
    if (logfile.is_open()) {
        logfile.close();
    }
}

void Logger::log(const std::string& message) {
    if (logfile.is_open()) {
        logfile << message << std::endl;
    }
}