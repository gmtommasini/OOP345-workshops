/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "util.h"

#define SIZE 5
namespace sdds {
	class SpellChecker	{
		std::string	m_badWords[SIZE]{};
		std::string m_goodWords[SIZE]{};

	public:
		~SpellChecker();
		SpellChecker();
		//SpellChecker(SpellChecker&);
		//SpellChecker(SpellChecker&&);
		SpellChecker(const char* filename); 

		//SpellChecker& operator=(SpellChecker&);
		//SpellChecker& operator=(SpellChecker&&);

		void operator()(std::string& text) const;
	
	};
}

#endif // !SPELLCHECKER_H