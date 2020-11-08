
#include "Restaurant.h"

namespace sdds {

	Restaurant::~Restaurant() {
		if(a_reservations)
			delete[] a_reservations;
		a_reservations = nullptr;
	}
	Restaurant::Restaurant() {}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		//TODO
		this->a_reservations = new Reservation[cnt];
		size_t i{ 0 };
		for (; i < cnt; i++) {
			this->a_reservations[i] = *reservations[i];
		}
		numberOfResevations = i;
	}
	Restaurant::Restaurant(Restaurant& src) { //copy constructor
		if (src.numberOfResevations > 0) {
			this->a_reservations = new Reservation[src.size()];
			for (; numberOfResevations < src.size(); numberOfResevations++) {
				this->a_reservations[numberOfResevations] = src.a_reservations[numberOfResevations];
			}
		}
	}
	Restaurant::Restaurant(Restaurant&& src) { //move constructor
		if (src.numberOfResevations > 0) {
			this->a_reservations = src.a_reservations;
			this->numberOfResevations = src.size();
			src.a_reservations = nullptr;
			src.numberOfResevations= 0 ;
		}
	}
	size_t Restaurant::size() const { return numberOfResevations; };

	std::ostream& operator<<(std::ostream& os, Restaurant& res) {
		os << "--------------------------\nFancy Restaurant\n--------------------------\n";
		if (res.size()>0) {
			for (size_t i = 0; i < res.size();i++) {
				os << res.a_reservations[i];
			}
		}
		else {
			os << "The object is empty!\n";
		}
		os<<"--------------------------\n";
		return os;
	};
}