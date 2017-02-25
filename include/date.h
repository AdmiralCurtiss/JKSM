#ifndef DATE_H
#define DATE_H

#include <string>

enum class DateTimeFormat
{
    FORMAT_YDM,
    FORMAT_YMD,
    COUNT
};

char *GetDate(DateTimeFormat Format);
std::string RetTime();

#endif // DATE_H
