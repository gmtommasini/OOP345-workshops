#include "Reservation.h"

#include <iomanip>

namespace sdds{
	Reservation::Reservation() {};

	Reservation::~Reservation() {};

	Reservation::Reservation(const std::string& res) {
		std::string src = res; //res is const, src is not
		this->id = util::substring(src, ':');
		this->name = util::substring(src, ',');
		this->email = util::substring(src, ',');
		this->partySize = util::substring<int>(src, ',');
		this->day = util::substring<int>(src, ',');
		this->hour = util::substring<int>(src, ',');
	};
	   
	std::ostream& operator<<(std::ostream& os, const Reservation& Res) {
		std::string meal = "Drinks on day ";
		if (Res.hour >= 6 && Res.hour <= 9) {
			meal = "Breakfast on day ";
		}
		else if (Res.hour >= 11 && Res.hour <= 15) {
			meal = "Lunch on day ";
		}
		else if (Res.hour >= 17 && Res.hour <= 21) {
			meal = "Dinner on day ";
		}
		os.fill(' ');
		os << "Reservation " << Res.id << ": "
			<< std::setw(10) << std::right << Res.name << "  "
			<< std::setw(24) << std::left << "<" + Res.email + ">" <<
			meal << Res.day << " @ ";
		os << std::right << Res.hour
			<< ":00 for " << Res.partySize << " people." << std::endl;
		return os;
	}
}

namespace util { //this should be on its own module, but the the script does not allow it
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

	//overloading the function substring for strings - refer to header file
	std::string substring(std::string& src, const char C) {
		int pos = src.find(C);
		pos = pos > 0 ? pos : src.length();
		std::string temp = src.substr(0, pos);
		trim(temp);
		src.erase(0, pos + 1);
		return temp;
	}
}