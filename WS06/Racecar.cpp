/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Racecar.h"

namespace sdds {
	Racecar::~Racecar() {}
	Racecar::Racecar() { this->m_booster = { 0 }; }
	Racecar::Racecar(std::istream& in) 
		try :Car(in) {
		std::string line;
		std::getline(in, line);
		this->m_booster = (this->Car::topSpeed() ? std::stod(util::trim(line)) : 0);
	}catch (const char msg){
		throw msg;
	}
	Racecar::Racecar(Racecar& src)	{
		*this = src;
	}
	Racecar& Racecar::operator=(Racecar& src)	{
		if (this != &src) {
			Car::operator=(src);
			this->m_booster = src.m_booster;
		}
		return *this;
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
			out<<"*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + this->m_booster);
	}
}
