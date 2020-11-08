#pragma once

#include <string>

namespace sdds {
	class Reservation	{
		std::string id{};
		std::string name{};
		std::string email{};
		int partySize{ 0 };
		int day{ 0 };//number between 1 and 31
		int hour{ 0 }; //number between 1 and 24
	public:
		Reservation();
		~Reservation();
		Reservation(const std::string&);

		friend std::ostream& operator<<(std::ostream&, const Reservation&);

	};
}

namespace util {
#define CharsToTrim "\t\n\v\f\r "
	std::string& ltrim(std::string& src);
	std::string& rtrim(std::string& src);
	std::string& trim(std::string& str);

	template<typename T>
	T substring(std::string& src, const char C) {
    int pos = src.find(C);
    pos = pos > 0 ? pos : src.length();
    T temp =  std::stold(src.substr(0, pos) ); //narrowing
    src.erase(0, pos + 1);
    return temp;
}
	
	//overloading for string
	std::string substring(std::string& src, const char C);

	//int subint(std::string& src, const char C);
}