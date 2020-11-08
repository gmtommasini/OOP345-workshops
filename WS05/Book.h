/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef BOOK_H
#define BOOK_H


#include <string>
#include <iomanip>
#include <iostream>
#include "util.h"

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;

		//Add any other private member that is required by your design!
	public:
		~Book();
		Book();								//notes
		Book(const std::string& strBook);		//notes
		//Book(const Book&);					//big 5
		//Book(Book&&) noexcept;				//big 5
		//Book& operator=(const Book&);			//big 5
		//Book& operator=(Book&&) noexcept;		//big 5

		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		template<class T>
		void fixSpelling(T spellChecker) {
			spellChecker(this->m_title);
			spellChecker(this->m_description);
		}

		friend std::ostream& operator<<(std::ostream&, const Book&);

	};
}

#endif // !BOOK_H