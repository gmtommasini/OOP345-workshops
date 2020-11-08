/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Car.h"

namespace sdds {
	Car::~Car() {	}
	Car::Car() {
		setEmpty();
	}
	Car::Car(std::istream& in) {
		std::string token;
		std::getline(in, token, ','); //getting rid of first token: vehicle type

		std::getline(in, token, ',');
		this->m_maker = util::trim(token);

		std::getline(in, token, ',');
		token = util::trim(token);
		char condition = token[0];
		switch (condition)
		{
		case '\0':
		case 'n':
			this->m_condition = Condition::n;
			break;
		case 'u':
			this->m_condition = Condition::u;
			break;
		case 'b':
			this->m_condition = Condition::b;
			break;
		default:
			setEmpty();
			std::string error = "Invalid record!";
			throw error;
		}
		std::getline(in, token, ',');
		try {
			this->m_topSpeed = std::stoi(util::trim(token));
		}
		catch (std::invalid_argument&) {
			setEmpty();
			std::string error = "Invalid record!";
			throw error;
		}
	}
	Car::Car(Car& src) {
		*this = src;
	}
	Car& Car::operator=(Car& src)	{
		if (this != &src) {
			this->m_maker = src.m_maker;
			this->m_condition = src.m_condition;
			this->m_topSpeed = src.m_topSpeed;
		}
		return *this;
	}
	void Car::setEmpty() {
		this->m_maker = "";
		this->m_condition = Condition::b;
		this->m_topSpeed = { 0 };
	}
	double Car::topSpeed() const { return this->m_topSpeed; }

	//| MAKER | CONDITION | TOP_SPEED |
	void Car::display(std::ostream& os) const {
		if (this->m_topSpeed != 0) {
			os << "| " << std::setw(10) << std::right << this->m_maker <<
				" | " << std::setw(6) << std::left << this->condition() <<
				" | " << std::fixed << std::setprecision(2) << this->topSpeed() << " |";
		}
	}

	std::string Car::condition() const {
		switch (this->m_condition) {

		case Condition::n:
			return "new";
		case Condition::u:
			return "used";
		case Condition::b:
			return "broken";
		default:
			throw "Error: Condition not found!\n";
		}
	}
}

