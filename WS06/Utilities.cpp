/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* v = nullptr;
		std::string line;
		std::getline(in, line);
		util::trim(line);
		std::stringstream  input;
		input << line;
		if (in) {
			try {
				char vtype = line[0];
				switch (vtype) {
				case 'c':
				case 'C':
					v = new Car(input);
					break;
				case 'r':
				case 'R':
					//v = static_cast<Vehicle*>(static_cast<void*>(new Racecar(input)));
					v = new Racecar(input);
					break;
				default:
					throw vtype; // error of vehicle type
				}
			}
			catch (const std::string error) {
				throw error; //error thrown by the constructor
			}
		}
		return v;
	}
}
