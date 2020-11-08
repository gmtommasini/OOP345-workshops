#pragma once

#include "util.h"
//#include <typeinfo>

namespace util {
    //template<typename T>
    //T substring(std::string& src, const char C) {
    //    int pos = src.find(C);
    //    pos = pos > 0 ? pos : src.length();
    //    T temp =  std::stold(src.substr(0, pos) ); 
    //    src.erase(0, pos + 1);
    //    return temp;
    //}
   
    int subint(std::string& src, const char C) {
        int pos = src.find(C);
        pos = pos > 0 ? pos : src.length();
        int temp = std::stoi(src.substr(0, pos));
        src.erase(0, pos + 1);
        return temp;
    }

    //template<>
    //overloading function
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