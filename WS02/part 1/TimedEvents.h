/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H
#define _CRT_SECURE_NO_WARNINGS
//#include <string>
#include <fstream>
#include <iostream>
//#include <cstring>
#include <chrono>
#include "RecordSet.h"

using namespace std;
#define MAX_ 7

namespace sdds {
	class TimedEvents {
		struct {
			string eventName;
			string unitOfTime;
			std::chrono::steady_clock::duration duration;
		}records[MAX_];
		int nor{ 0 }; //number of records
		std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
		
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend ostream& operator<<(ostream&, TimedEvents&);
		/*  ```
  Execution Times:
  --------------------------
  EVENT_NAME DURATION UNITS
  EVENT_NAME DURATION UNITS
  ...
  --------------------------
  ```
*/

	};
}

#endif // TIMEDEVENTS_H
