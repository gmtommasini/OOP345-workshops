/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/11/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
#include "util.h"

namespace sdds{
	Vehicle* createInstance(std::istream& in);
}
#endif // !UTILITIES_H
