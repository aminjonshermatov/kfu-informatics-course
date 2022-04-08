//
// Created by aminjonshermatov on 9/25/2021.
//

#include "Logger.h"

Logger::Logger(std::ostream *out)
: _out(out) { }

Logger Logger::operator()(Logger::LogType logType) {
    *this->_out << "[" << Logger::getLabel(logType) << "]:\t";
    return *this;
}

Logger Logger::operator()(Logger::LogType logType, int line) {
    *this->_out << "[" << Logger::getLabel(logType) << "] line " << line << ":\t";
    return *this;
}

Logger Logger::operator()(Logger::LogType logType, int line, int charAt) {
    *this->_out << "[" << Logger::getLabel(logType) << "] line " << line << ", character at " << charAt << ":\t";
    return *this;
}

Logger Logger::operator<<(int msg) {
    *this->_out << msg;
    return *this;
}

Logger Logger::operator<<(const str& msg) {
    *this->_out << msg;
    return *this;
}

Logger Logger::operator<<(const char &ch) {
    *this->_out << ch;
    return *this;
}

void Logger::setOStream(std::ostream *out) {
    this->_out = out;
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
