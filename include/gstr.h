#ifndef GSTR_H
#define GSTR_H

#include <string>

std::string GetString(const char *hint, bool allowAutoFilename);
int getInt(const char *hint, int init, int maxValue);

#endif // GSTR_H
