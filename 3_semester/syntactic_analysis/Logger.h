//
// Created by aminjonshermatov on 9/25/2021.
//

#ifndef INFORMATICS_LOGGER_H
#define INFORMATICS_LOGGER_H

#include "sharedModule.h"

class Logger {
public:
    explicit Logger(std::ostream*);

    enum LogType { WARNING, ERROR };

    Logger operator()(LogType);
    Logger operator()(LogType, int);
    Logger operator()(LogType, int, int);
    Logger operator<<(int);
    Logger operator<<(const str&);
    Logger operator<<(const char&);

    void setOStream(std::ostream*);
private:
    std::ostream* _out;

    static inline str getLabel(LogType);
};


#endif //INFORMATICS_LOGGER_H
