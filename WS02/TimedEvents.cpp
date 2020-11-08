/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "TimedEvents.h"
#include <iomanip>

using namespace std;

namespace sdds {
	TimedEvents::TimedEvents() {};
	void TimedEvents::startClock() {
		this->startTime= std::chrono::steady_clock::now(); 
	};
	void TimedEvents::stopClock() {
		this->endTime= std::chrono::steady_clock::now();
	};
	void TimedEvents::recordEvent(const char* en) {
		this->records[nor].eventName = en;
		this->records[nor].unitOfTime= "nanoseconds";
		this->records[nor].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		nor++;
	};
	ostream& operator<<(ostream& os, const TimedEvents& te) {
		os << "--------------------------" << endl; 
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < te.nor; i++) {
			os << std::setw(20) << te.records[i].eventName 
				<< std::setw(12) << std::right << te.records[i].duration.count() 
				<< " " << te.records[i].unitOfTime << endl;
		}
		os << "--------------------------" << endl;
		return os;
		/*  ```
		--------------------------
		Execution Times:
		--------------------------
		EVENT_NAME DURATION UNITS
		EVENT_NAME DURATION UNITS
		...
		--------------------------
				
		The **name** of the event should be in a field of size 20, aligned on the left; 
		the **duration** should be in a field of size 12, aligned on the right.
		*/
	};
}