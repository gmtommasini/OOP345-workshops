/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iomanip>
#include "util.h"

namespace sdds {
	class Movie {
		std::string m_title{};
		unsigned m_year{ 0 };
		std::string m_description{};

		//Add any other private member that is required by your design!
	public:
		~Movie();
		Movie();								//notes
		Movie(const std::string& strMovie);		//notes
		//Movie(const Movie&);					//big 5
		//Movie(Movie&&) noexcept;				//big 5
		//Movie& operator=(const Movie&);			//big 5
		//Movie& operator=(Movie&&) noexcept;		//big 5

		const std::string& title() const;		//notes

		template<class T> //
		void fixSpelling(T spellChecker) {
			spellChecker(this->m_title);
			spellChecker(this->m_description);
		};

		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}

#endif // !MOVIE_H
