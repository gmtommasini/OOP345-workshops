#pragma once

#include <iostream>
#include <string>


#define CharsToTrim "\t\n\v\f\r "

namespace util {
    std::string& ltrim(std::string& src);
    std::string& rtrim(std::string& src);
    std::string& trim(std::string& str);

    int subint(std::string& src, const char C);
    std::string substring(std::string& src, const char C);
}