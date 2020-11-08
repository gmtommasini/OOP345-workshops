/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono> //for time measuring
#include "RecordSet.h"

using namespace std;
#define MAX_ 7

namespace sdds {
	class TimedEvents {
		struct {
			string eventName;
			string unitOfTime;
			std::chrono::steady_clock::duration duration{};
		}records[MAX_];
		int nor{ 0 }; //number of records
		std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
		
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend ostream& operator<<(ostream&, const TimedEvents&);
	};
}

#endif // TIMEDEVENTS_H
