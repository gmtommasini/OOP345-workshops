/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SpellChecker.h"
          

namespace sdds {

	SpellChecker::~SpellChecker() {}
	SpellChecker::SpellChecker() {}
	//SpellChecker::SpellChecker(SpellChecker& src) {		*this = src;	}
	//SpellChecker::SpellChecker(SpellChecker&& src) {	*this = src;}
	SpellChecker::SpellChecker(const char* filename) {
		//try-catch???
		std::ifstream file(filename);
		if (!file) {
			//std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			throw "Bad file name!";
		}
		std::string fileLine;
		unsigned count{ 0 };
		do {
			std::getline(file, fileLine);
			// if the previous operation failed, the "file" object is in error mode
			if (file) {
				this->m_badWords[count] = util::substring(fileLine, ' ');
				this->m_goodWords[count] = util::trim(fileLine);
				count++;
			}
		} while (file);
		file.close();
	}

	//SpellChecker& SpellChecker::operator=(SpellChecker& src) {
	//	if (this != &src) {
	//		for (int i = 0; i < SIZE; i++) {
	//			m_badWords[i] = src.m_badWords[i];
	//			m_goodWords[i] = src.m_goodWords[i];
	//		}
	//	}
	//	return *this;
	//}
	//SpellChecker& SpellChecker::operator=(SpellChecker&& src){
	//	if (this != &src) {
	//
	//	}
	//	return *this;
	//}

	void SpellChecker::operator()(std::string& text) const {
		for (int i = 0; i < SIZE; i++) {
			size_t pos;
			do {
				pos = text.find(m_badWords[i]);
				if (pos != std::string::npos) {
					text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				}
			} while (pos != std::string::npos);
		}
	}

}