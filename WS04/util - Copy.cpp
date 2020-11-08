#include "util.h"

namespace util {
    std::string& ltrim(std::string& src) {
        src.erase(0, src.find_first_not_of(CharsToTrim));
        return src;
    };
    std::string& rtrim(std::string& src) {
        src.erase(src.find_last_not_of(CharsToTrim) + 1);
        return src;
    };
    std::string& trim(std::string& str) {
        return ltrim(rtrim(str));
    };

    int subint(std::string& src, const char C) {
        int pos = src.find(C);
        pos = pos > 0 ? pos : src.length();
        int temp = std::stoi(src.substr(0, pos));
        src.erase(0, pos + 1);
        return temp;
    }
    std::string substring(std::string& src, const char C) {
        int pos = src.find(C);
        pos = pos > 0 ? pos : src.length();
        std::string temp = src.substr(0, pos);
        trim(temp);
        //std::cout << "\n--" << temp << "--\n";
        src.erase(0, pos + 1);
        return temp;
    }


}