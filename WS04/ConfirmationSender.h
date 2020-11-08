#pragma once

#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender	{
		const Reservation** pa_reservation{nullptr};
		size_t quant{0};

	public:
		ConfirmationSender();
		ConfirmationSender(ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		~ConfirmationSender();

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		size_t getSize();

		friend std::ostream& operator<<(std::ostream&, ConfirmationSender&);
	};
}