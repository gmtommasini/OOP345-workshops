#pragma once
/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef RECORDSET_H
#define RECORDSET_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>
//#include <iostream>
//#include <cstring>
#include <fstream>

using namespace std;

namespace sdds {
	class RecordSet {
		string* array = nullptr;
		size_t nor{ 0 };// number of objects
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(RecordSet&);
		RecordSet& operator=(RecordSet&);
		~RecordSet();
		size_t size();
		string getRecord(size_t);
	};
}

#endif // !RECORDSET_H
