/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "RecordSet.h"

using namespace std;

namespace sdds {
	RecordSet::RecordSet() {

	};

	RecordSet::RecordSet(const char* fileName ) {
		ifstream file(fileName);
		int count = 0;
		while (file) {
			string temp;
			getline(file, temp , ' ');
			count++; //worked
		}
		file.close();
		//cout << "palavras: "<< count;
		this->array = new string[count+1];
		count = 0;
		ifstream file2(fileName);
		while (file2) {
			getline(file2, this->array[count], ' ');
			count++;
		}
		this->nor = count-1;
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
	RecordSet::~RecordSet() {
		delete[] array;
	};
	size_t RecordSet::size() {
		return nor;
	};
	string RecordSet::getRecord(size_t pos) {
		if (nor == 0 || pos > nor) 
			return "";
		else
			return this->array[pos];	
	};
}