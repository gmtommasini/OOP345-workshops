#pragma once

#include <string>
//#include "utils.h"

namespace sdds {
	class Reservation
	{
	public:
		Reservation();
		~Reservation();
		Reservation(const std::string&);

		friend std::ostream& operator<<(std::ostream&, Reservation&);
	private:
		std::string id{}; //array of characters
		std::string name{};
		std::string email{};
		int partySize{ 0 };
		int day{ 0 };//number between 1 and 31
		int hour{ 0 }; //number between 1 and 24
	};


}

#define CharsToTrim "\t\n\v\f\r "

namespace util {
	std::string& ltrim(std::string& src);
	std::string& rtrim(std::string& src);
	std::string& trim(std::string& str);

	int subint(std::string& src, const char C);
	std::string substring(std::string& src, const char C);
}