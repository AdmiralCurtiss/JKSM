#ifndef DATE_H
#define DATE_H

#include <string>

enum class DateTimeFormat
{
    FORMAT_YDM,
    FORMAT_YMD,
    FORMAT_DMY,
    FORMAT_MDY,
    COUNT
};

std::string GetDateTimeFormatString(DateTimeFormat format);
std::string GetDate(DateTimeFormat Format);
std::string RetTime();

#endif // DATE_H
