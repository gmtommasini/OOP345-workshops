/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
2020/10/01

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "event.h"

using namespace std;
extern size_t g_sysClock;
static int counter = 1;

namespace sdds {
	Event::~Event() {
		if (description != nullptr)
			delete[] description;
		description = nullptr;
		this->startTime = 0;
	};
	Event::Event() {
		setEmpty();
	};
	Event::Event(const Event &Ev) {
		this->description = nullptr;
		*this = Ev;
	};

	Event& Event::operator=(const Event& Ev) {
		if (this != &Ev) {
			clear();
			this->setDescription(Ev.description);
			this->startTime = Ev.startTime;
		}
		return *this;
	};

	void Event::setEmpty() {
		description = nullptr;
		this->startTime = 0;
	}
	void Event::clear() {
		if (description != nullptr)
			delete[] description;
		setEmpty();
	}
	void Event::setDescription(char* src) {
		if (src != nullptr && src[0] != '\0') {
			if (description != nullptr)
				delete[] description;
			description = new char[strlen(src) + 1];
			strcpy(this->description, src);			
		}
		else {
			clear();
		}
		this->startTime = g_sysClock;
	};

	void Event::display() const {
		cout.width(3);
		//cout.fill('0');
		cout << counter++ << ". ";
		if (description  == nullptr)
			cout << "[ No Event ]" << endl;
		else {
			printTime();
			cout << " -> " << this->description << endl;		
		}
	};
	void Event::printTime() const {
		int h = startTime / 3600;
		int rest = startTime % 3600;
		int m = rest / 60;
		int s = rest % 60;
		printf("%02d:%02d:%02d", h, m, s);
	}

	/*  
  1. 00:02:55 -> Computer Starting
  2. 00:02:55 -> Computer Starting
  3. [ No Event ]
  4. 01:15:34 -> User logging in
  5. 01:20:09 -> User logging in
  6. 09:01:04 -> Browser closed
  7. 17:33:33 -> User checks email
*/

}