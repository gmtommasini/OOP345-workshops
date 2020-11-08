/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Book.h"

namespace sdds {
	Book::~Book() {	}
	Book::Book() {
		this->m_author = {};
		this->m_title = {};
		this->m_country = {};
		this->m_year = { 0 };
		this->m_price = { 0 };
		this->m_description = {};
	}

	Book::Book(const std::string& strBook) {
		std::string src = strBook; //strBook is const, src is not
		//AUTHOR, TITLE, COUNTRY, PRICE, YEAR, DESCRIPTION
		this->m_author = util::substring(src, ',');
		this->m_title = util::substring(src, ',');
		this->m_country = util::substring(src, ',');
		this->m_price = stod(util::substring(src, ','));
		this->m_year = stoi(util::substring(src, ','));
		this->m_description = util::trim(src);
	}

	const std::string& Book::title() const { return this->m_title; }
	const std::string& Book::country() const { return this->m_country; }
	const size_t& Book::year() const { return m_year; }
	double& Book::price() { return this->m_price; }

	//AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
	std::ostream& operator<<(std::ostream& os, const Book& b) {
		if (!b.title().empty()) {
			os << std::setw(20) << std::right << b.m_author
				<< " | " << std::setw(22) << b.title()
				<< " | " << std::setw(5) << b.country()
				<< " | " << std::setw(4) << b.year()
				<< " | " << std::setw(6) << std::fixed << std::setprecision(2) << b.m_price
				<< " | " << b.m_description << std::endl;
		}
		return os;
	}
}

//namespace util {
//
//	std::string& ltrim(std::string& src) {
//		src.erase(0, src.find_first_not_of(CharsToTrim));
//		return src;
//	};
//	std::string& rtrim(std::string& src) {
//		src.erase(src.find_last_not_of(CharsToTrim) + 1);
//		return src;
//	};
//	std::string& trim(std::string& str) {
//		return ltrim(rtrim(str));
//	};
//
//	std::string substring(std::string& src, const char C) {
//		int pos = src.find(C);
//		pos = pos > 0 ? pos : src.length();
//		std::string temp = src.substr(0, pos);
//		trim(temp);
//		src.erase(0, pos + 1);
//		return temp;
//	}
//}