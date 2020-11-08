/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/11

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once

#include <iomanip>
//#include <string>
#include "Pair.h"

using namespace std;

namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V initial;
		static size_t minWidth; 

	public:
		PairSummable() {
			minWidth = 0;
		}
		PairSummable(const K& key, const  V& value = initial) : Pair<K,V>(key, value) {
			if (key.size() > minWidth) 
				minWidth = key.size();
		}
		void display(ostream& os) const {
			os << left << setw(minWidth);
			this->Pair<K,V>::display(os);
			os << right;
		}
		PairSummable<K,V>& operator+=(const PairSummable& src) {
			if (this != &src && this->key() == src.key()) {
				*this =PairSummable(this->key(), this->value() + src.value());
			}
			return *this;
		}
	};

	//initializing initial
	template<typename K, typename V>
	V PairSummable<K, V>::initial{ 0 };
	//initializing minWidth
	template<typename K, typename V>
	size_t PairSummable<K, V>::minWidth = 0 ;
	//initializing specialization for <string, string>
	template<>
	string PairSummable<string, string>::initial = "";	
	//initializing specialization for <string, int>
	template<>
	int PairSummable<string, int>::initial = 0;

	//specialization for <string, string>
	template<>
	PairSummable<string, string>& PairSummable<string, string>::operator+=(const PairSummable& src) {
		if (this != &src && this->key() == src.key()) {
			*this = PairSummable(this->key(), (this->value() == "" ? "" : this->value() + ", ") + src.value());
		}
		return *this;
	}
}