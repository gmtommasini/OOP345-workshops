/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		~Autoshop();
		Autoshop();
		Autoshop(Autoshop&);
		Autoshop(Autoshop&&);

		Autoshop& operator=(Autoshop&);
		Autoshop& operator=(Autoshop&&);

		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template<class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (size_t i = 0; i < m_vehicles.size(); i++){
				if (test(m_vehicles[i])) {
					vehicles.push_back(m_vehicles[i]);
				}
			}
		}
	};
}

#endif // !AUTOSHOP_H
