/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Movie.h"

namespace sdds {
	Movie::~Movie() {}
	Movie::Movie() {
		this->m_title = {};
		this->m_year = { 0 };
		this->m_description = {};
	}
	
	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;
		this->m_title = util::substring(temp, ',');
		this->m_year = std::stoi(util::substring(temp, ','));
		this->m_description = util::trim(temp);
	};

	//Movie& Movie::operator=(const Movie& src) {
	//	if (this != &src) {
	//		this->m_title = src.m_title;
	//		this->m_year = src.m_year;
	//		this->m_description = src.m_description;
	//	}
	//	return *this;
	//}

	const std::string& Movie::title() const { return this->m_title; }

	std::ostream& operator<<(std::ostream& os, const Movie& mv) {
		if (!mv.m_title.empty()) {
			os << std::setw(40) << std::right << mv.title() << " | " << std::setw(4) << mv.m_year
				<< " | " << mv.m_description << std::endl;
		}
		return os;
	}
}

