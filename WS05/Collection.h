/*
Guilherme Matsumoto Tommasini
167561182
gmatsumoto-tommasini
gmatsumoto-tommasini@mysenca.ca
2020/10/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#pragma once
#include <string>

#include <iostream>

namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name{};
		T* collection{ nullptr };
		size_t m_size{ 0 };
		void (*observer)(const Collection<T>&, const T&) { nullptr };

	public:
		~Collection() {
			if (collection)
				delete[] collection;
			collection = nullptr;
			//delete observer;
			observer = nullptr;
		};
		Collection() {
			m_name = "";
			collection = nullptr;
			m_size = 0;
			observer = nullptr;
		};
		Collection(std::string name) { m_name = name; };
		Collection(Collection&) = delete;
		Collection(Collection&&) = delete;
		Collection& operator=(Collection&) = delete;
		Collection& operator=(Collection&&) = delete;

		const std::string& name() const { return m_name; }
		size_t size() const { return m_size; }

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool notfind = true;
			for (size_t i = 0; i < this->size() && notfind; i++) {
				if (this->collection[i].title() == item.title()) {
					notfind = false;
				}
			}
			if (notfind) {
				size_t s = this->size();
				T* temp = new T[s + 1];
				if (this->collection) {
					for (size_t i = 0; i < s; i++) {
						temp[i] = this->collection[i];
					}
					delete[] collection;
				}
				temp[s] = item; 
				collection = temp;
				this->m_size++;
				temp = nullptr;
				if (this->observer != nullptr)
					this->observer(*this, item);
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= this->m_size) {
				//std::string msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" +
				//	std::to_string(m_size) + "] items.";
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" +
					std::to_string(m_size) + "] items.");

			}
			return collection[idx];
		}

		T* operator[](std::string title) const {
			for (size_t i = 0; i < this->m_size; i++) {
				if (this->collection[i].title() == title) {
					return &this->collection[i];
				}
			}
			return nullptr;
		}

	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& col) {
		for (size_t i = 0; i < col.size(); i++)
			os << col[i];
		return os;
	}

}
