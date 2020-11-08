#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender(){}
	ConfirmationSender::ConfirmationSender(ConfirmationSender& src) {
		if (src.quant > 0) {
			this->quant = src.quant;
			//this->pa_reservation = src.pa_reservation;
			this->pa_reservation = new const Reservation * [quant];
			for (size_t i = 0; i < quant; i++) {
				this->pa_reservation[i] = src.pa_reservation[i];
			}
		}
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src){
		if (src.quant > 0) {
			this->quant = src.quant;
			this->pa_reservation = src.pa_reservation;
			src.quant = 0;
			src.pa_reservation = nullptr;
		}
	}
	ConfirmationSender::~ConfirmationSender(){
		if (this->pa_reservation) {
			delete[] pa_reservation;
			pa_reservation= nullptr ;
		}			
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& toAdd) {
		bool found{ false };
		for (size_t i = 0; i < this->quant && !found; i++) { //finding if the reservation is already included
			if (this->pa_reservation[i] == &toAdd) 				
				found = true;
		}
		if (!found) { //if not already included -> INCLUDE!!
			const Reservation** temp = new const Reservation * [this->getSize() + 1];
			for (size_t i= 0; i < this->quant; i++) {
				temp[i] = this->pa_reservation[i]; //storing in temp location
			}
			quant++;
			temp[this->getSize() -1] = &toAdd;
			if (pa_reservation)
				delete [] pa_reservation;
			pa_reservation = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& toDel) {
		bool found{ false };
		for (size_t position = 0 ; position < this->getSize() && !found; position++) {
			if (this->pa_reservation[position] == &toDel) {
				found = true;						//stoping the loop
				this->pa_reservation[position] = nullptr;
				this->quant--;

				/**** Cleaning - resizing the array ****/
				const Reservation** temp = new const Reservation * [this->getSize()];
				for (size_t i=0, j=0; j < this->getSize(); i++, j++) { //has to be j<quant, because j is the index of the old array
					if (j == position) {	//skiping deleted one
						temp[i] = pa_reservation[++j];
					}
					else {
						temp[i] = pa_reservation[j];	//storing in temp location
					}
				}
				delete[] this->pa_reservation;
				this->pa_reservation = temp; //repointing
			}
		}
		return *this;
	}
	size_t ConfirmationSender::getSize(){ return quant; }

	std::ostream& operator<<(std::ostream& os, ConfirmationSender& res) {
		os << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (res.getSize() > 0) {
			for (size_t i = 0; i < res.getSize(); i++) {
				if (res.pa_reservation[i]) // we don't really need this here (because of resizing)... it just a safeguard
					os << *(res.pa_reservation[i]);
				else
					os << "********* error! printing null!! *********\n";
			}
		}
		else {
			os << "The object is empty!\n";
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}