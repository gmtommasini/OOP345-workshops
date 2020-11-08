
#include "Reservation.h"

using namespace std;
using namespace sdds;

Reservation::Reservation()
{
	id[0] = '\0';
	name = "";
	email = "";
	numberOfPeople = 0;
	day = 0;
	hour = 0;
}

Reservation::Reservation(const std::string& res) {
	string temp = res;

	//removing all the whitespace
	temp.erase(std::remove_if(temp.begin(), temp.end(), std::isspace), temp.end());

	strcpy_s(id, temp.substr(0, temp.find(':')).c_str());
	temp.erase(0, temp.find(':') + 1);
	name = temp.substr(0, temp.find(','));
	temp.erase(0, temp.find(',') + 1);
	email = temp.substr(0, temp.find(','));
	temp.erase(0, temp.find(',') + 1);
	numberOfPeople = stoi(temp.substr(0, temp.find(',')));
	temp.erase(0, temp.find(',') + 1);
	day = stoi(temp.substr(0, temp.find(',')));
	temp.erase(0, temp.find(',') + 1);
	hour = stoi(temp);
}

Reservation::~Reservation()
{
}


ostream& sdds::operator<<(ostream& os, const Reservation& r)
{
	string suitableMeal;

	if (r.hour >= 6 && r.hour <= 9)
	{
		suitableMeal = "Breakfast";
	}
	else if (r.hour >= 11 && r.hour <= 15)
	{
		suitableMeal = "Lunch";
	}
	else if (r.hour >= 17 && r.hour <= 21)
	{
		suitableMeal = "Dinner";
	}
	else
	{
		suitableMeal = "Drinks";
	}

	os << "Reservation "<< r.id << ":" << right << setw(10) << r.name  << "  "<< left << setw(20) << "<" + r.email + ">" << "    " << suitableMeal << " on day " << r.day << " @ " << r.hour << ":00 for " << r.numberOfPeople << " people." << endl;

	return os;
}
