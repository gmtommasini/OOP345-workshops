/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "RecordSet.h"

using namespace std;

namespace sdds {
	RecordSet::RecordSet() {};

	RecordSet::RecordSet(const char* fileName ) {
		ifstream file(fileName);
		if (file.is_open()) {
			int count = 0;
			while (file) {
				string temp;
				getline(file, temp, ' ');
				count++; //worked
			}
			file.clear();
			file.seekg(0);
			this->array = new string[count-1]; //count is increased one time more than needed in the while loop
			count = 0;
			while (file) {
				getline(file, this->array[count++], ' ');
			}
			this->nor = count - 1;	
			file.close(); 
		}
	};
	RecordSet::RecordSet(RecordSet& source) {
		this->array = new string[source.nor + 1];
		this->nor = source.nor;
		for (size_t i = 0; i < this->nor; i++) {
			this->array[i] = source.array[i];
		}
	};

	RecordSet& RecordSet::operator=(RecordSet& source) {
		if (this != &source) {
			if (this->array)
				delete[] array;
			this->array = new string[source.nor+1];
			this->nor = source.nor;
			for (size_t i = 0; i < this->nor; i++) {
				this->array[i] = source.array[i];
			}
		}
		return *this;
	};

	RecordSet::RecordSet(RecordSet&& source) {
		*this = std::move(source);
	};
	RecordSet& RecordSet::operator=(RecordSet&& source) {
		if (this != &source) {
			if (this->array)
				delete[] array;
			this->array = source.array;
			source.array = nullptr;
			this->nor = source.nor;
			source.nor = 0;
		}
		return *this;
	};
	RecordSet::~RecordSet() {
		delete[] array;
		array = nullptr;
	};
	size_t RecordSet::size() {
		return nor;
	};
	string RecordSet::getRecord(size_t pos) {
		return (nor == 0 || pos > nor) ? "" : this->array[pos];
	};
}