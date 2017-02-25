#include <time.h>
#include <stdio.h>
#include <string>

#include "date.h"

std::string GetDateTimeFormatString(DateTimeFormat format)
{
    switch (format)
    {
        case DateTimeFormat::FORMAT_YDM: return "YYYY-DD-MM";
        case DateTimeFormat::FORMAT_YMD: return "YYYY-MM-DD";
        case DateTimeFormat::FORMAT_DMY: return "DD-MM-YYYY";
        case DateTimeFormat::FORMAT_MDY: return "MM-DD-YYYY";
        default: return "UNKNOWN";
    }
}

//This returns the date as a string
std::string GetDate(DateTimeFormat Format)
{
    char Ret[24];

    time_t Raw;
    time(&Raw);
    tm *Time = localtime(&Raw);

    switch(Format)
    {
        case DateTimeFormat::FORMAT_YDM:
            {
                sprintf(Ret, "%04d-%02d-%02d_%02d-%02d-%02d", Time->tm_year + 1900, Time->tm_mday, Time->tm_mon + 1, Time->tm_hour, Time->tm_min, Time->tm_sec);
                break;
            }
        case DateTimeFormat::FORMAT_YMD:
        default:
            {
                sprintf(Ret, "%04d-%02d-%02d_%02d-%02d-%02d", Time->tm_year + 1900, Time->tm_mon + 1, Time->tm_mday, Time->tm_hour, Time->tm_min, Time->tm_sec);
                break;
            }
        case DateTimeFormat::FORMAT_DMY:
            {
                sprintf(Ret, "%02d-%02d-%04d_%02d-%02d-%02d", Time->tm_mday, Time->tm_mon + 1, Time->tm_year + 1900, Time->tm_hour, Time->tm_min, Time->tm_sec);
                break;
            }
        case DateTimeFormat::FORMAT_MDY:
            {
                sprintf(Ret, "%02d-%02d-%04d_%02d-%02d-%02d", Time->tm_mon + 1, Time->tm_mday, Time->tm_year + 1900, Time->tm_hour, Time->tm_min, Time->tm_sec);
                break;
            }
    }

    return std::string(Ret);
}

//this returns the time for the top bar
std::string RetTime()
{
    time_t Raw;
    time(&Raw);
    tm *Time = localtime(&Raw);

    char Tmp[32];

    sprintf(Tmp, "%02d:%02d", Time->tm_hour, Time->tm_min);

    return std::string(Tmp);
}
