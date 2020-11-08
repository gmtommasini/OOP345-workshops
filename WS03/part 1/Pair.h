#pragma once
//#include<iostream>
using namespace std;
namespace sdds {

	template<typename K = int, typename V = int>
	class Pair {
		K k{ 0 };
		V v{ 0 };
	public:
		Pair() {};
		Pair(const K& key, const V& value) {
			this->k = key;
			this->v = value;
		}
		const K& key() const { return k; }
		const V& value() const { return v; }
		void display(std::ostream& os) const {
			os << this->key() << " : " << this->value() << endl;
		}
	};

	template<typename K = int, typename V = int>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}