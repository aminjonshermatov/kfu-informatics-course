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

    Logger operator()(LogType logType, int line, int charAt);
    Logger operator<<(int msg);
    Logger operator<<(const str& msg);
    Logger operator<<(const char& ch);
private:
    std::ostream* out;

    inline str getLabel(LogType logType);
};


#endif //INFORMATICS_LOGGER_H
