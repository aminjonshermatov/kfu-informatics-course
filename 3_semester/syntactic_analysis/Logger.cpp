//
// Created by aminjonshermatov on 9/25/2021.
//

#include "Logger.h"

Logger::Logger(std::ostream *out) : out(out) { }

Logger Logger::operator()(Logger::LogType logType, int line, int charAt) {
    *this->out << "[" << this->getLabel(logType) << "] line " << line << ", character at " << charAt << ":\t";
    return *this;
}

Logger Logger::operator<<(int msg) {
    *this->out << msg;
    return *this;
}

Logger Logger::operator<<(const str& msg) {
    *this->out << msg;
    return *this;
}

Logger Logger::operator<<(const char &ch) {
    *this->out << ch;
    return *this;
}


str Logger::getLabel(Logger::LogType logType) {
    switch (logType) {
        case LogType::WARNING:
        default:
            return "WARNING";
        case LogType::ERROR:
            return "ERROR";
    }
}
