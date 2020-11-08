/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef UTIL_H
#define UTIL_H

#include <string>

#define CharsToTrim "\t\n\v\f\r "
namespace util {
	//std::string& ltrim(std::string& );
	//std::string& rtrim(std::string& );
	//std::string& trim(std::string& );
	//std::string substring(std::string& , const char );
	//inline
	//inline extern
	//extern inline
	inline std::string& ltrim(std::string& src) {
		src.erase(0, src.find_first_not_of(CharsToTrim));
		return src;
	};
	inline std::string& rtrim(std::string& src) {
		src.erase(src.find_last_not_of(CharsToTrim) + 1);
		return src;
	};
	inline std::string& trim(std::string& str) {
		//return ltrim(rtrim(str));
		return str.erase(str.erase(0, str.find_first_not_of(CharsToTrim)).find_last_not_of(CharsToTrim) + 1);
	};

	inline std::string substring(std::string& src, const char C) {
		int pos = src.find(C);
		pos = pos > 0 ? pos : src.length();
		std::string temp = src.substr(0, pos);
		trim(temp);
		src.erase(0, pos + 1);
		return temp;
	}
}

#endif // !UTIL_H