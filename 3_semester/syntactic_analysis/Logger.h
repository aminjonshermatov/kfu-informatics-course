//
// Created by aminjonshermatov on 9/25/2021.
//

#ifndef INFORMATICS_LOGGER_H
#define INFORMATICS_LOGGER_H

#include "sharedModule.h"

class Logger {
public:
    Logger(std::ostream* out);

    enum LogType { WARNING, ERROR };

    Logger operator()(LogType logType);
    Logger operator()(LogType logType, int line);
    Logger operator()(LogType logType, int line, int charAt);
    Logger operator<<(int msg);
    Logger operator<<(const str& msg);
    Logger operator<<(const char& ch);

    void setOStream(std::ostream* out);
private:
    std::ostream* _out;

    inline str getLabel(LogType logType);
};


#endif //INFORMATICS_LOGGER_H
