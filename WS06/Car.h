/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Vehicle.h"
#include "util.h"

namespace sdds {
	enum class Condition {
		n, u, b
	};
	class Car : public Vehicle	{
		std::string m_maker{};
		Condition m_condition{ Condition::b };
		size_t m_topSpeed{ 0 };
	public:
		~Car();
		Car();
		Car(std::istream& in);
		Car(Car&);
		Car& operator=(Car&);

		void setEmpty();

		double topSpeed() const;
		void display(std::ostream&) const;
		std::string condition() const;

	};
}
#endif // !CAR_H
