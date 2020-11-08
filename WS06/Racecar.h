/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef RACECAR_H
#define RACECAR_H

#include <iostream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car	{
		double m_booster;// 0 < boost < 1

	public:
		~Racecar();
		Racecar();
		Racecar(std::istream& in);

		Racecar(Racecar&);
		Racecar& operator=(Racecar&);

		void display(std::ostream& out) const;
		double topSpeed() const;
	};

}
#endif // !RACECAR_H