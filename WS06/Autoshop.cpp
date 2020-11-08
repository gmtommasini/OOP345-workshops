/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Autoshop.h"

namespace sdds {
	Autoshop::~Autoshop()	{
		while(!m_vehicles.empty()){
			delete m_vehicles.back();
			m_vehicles.pop_back();
		}
	}
	Autoshop::Autoshop() {	}
	Autoshop::Autoshop(Autoshop& src)	{
		*this = src;
	}
	Autoshop::Autoshop(Autoshop&& src)	{
		*this = std::move(src);
	}
	Autoshop& Autoshop::operator=(Autoshop& src)	{
		if(this!=&src){
			this->m_vehicles = src.m_vehicles;
		}
		return *this;
	}
	Autoshop& Autoshop::operator=(Autoshop&& src)	{
		if (this != &src) {
			this->m_vehicles = std::move(src.m_vehicles);
		}
		return *this;
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const {
		std::cout << "--------------------------------"<<std::endl
			<<"| Cars in the autoshop!        |"<<std::endl
			<<"--------------------------------" << std::endl;
		for (size_t i = 0; i<this->m_vehicles.size(); i++) {
			this->m_vehicles[i]->display(out);
			out << std::endl;
		}
		std::cout << "--------------------------------" << std::endl;
	}
}
