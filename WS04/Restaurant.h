#pragma once

#include <iostream>
#include "Reservation.h"
 
namespace sdds {
	class Restaurant	{
		Reservation* a_reservations{nullptr};
		size_t numberOfResevations{ 0 };

	public:
		Restaurant();
		~Restaurant();
		Restaurant(Restaurant&); 
		Restaurant(Restaurant&&);
		Restaurant(Reservation* reservations[], size_t cnt);//copies

		size_t size() const; //count reservations in the restaurant

		friend std::ostream& operator<<(std::ostream&, Restaurant&);
	};
}