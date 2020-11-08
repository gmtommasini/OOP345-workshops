/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/07

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once
#include<iostream>

namespace sdds {

	template<typename K, typename V>
	class Pair {
		K k;
		V v;
	public:
		Pair() :k{}, v{} { };
		Pair(const K& key, const V& value) {
			this->k = key;
			this->v = value;
		};
		const K& key() const { return k; }
		const V& value() const { return v; }
		virtual void display(std::ostream& os) const {
			os << this->key() << " : " << this->value() << std::endl;
		}
	};

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}