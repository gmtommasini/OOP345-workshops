/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once
#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

extern size_t g_sysClock;

namespace sdds {
	class Event{
		char * description;
		size_t startTime;

	public:
		~Event();
		Event() ;
		Event(const Event&);
		Event& operator=(const Event&);

		void setEmpty();
		void clear();
		void setDescription(char* );

		void display() const;
		void printTime() const;
	};
}
#endif