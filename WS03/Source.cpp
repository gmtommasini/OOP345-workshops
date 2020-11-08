
#pragma once

#include <iomanip>
#include <iostream>
#include <string>


class Base {
	static int varA;
public:
	Base() {
		varA++;
	}
	static void set(int val) {
		varA = val;
	}
	static int get() {
		return varA;
	}
};

class Derived: public Base{

};
int Base::varA{ 3 };



int main(int argc, char* argv[])
{
	
	std::cout << "Valor Base: \n" << Base::get() << "\n end!"; 
	Base obj1;
	std::cout << "Valor Base: \n" << Base::get() << "\n end!";
	Base obj2;
	std::cout << "Valor Base: \n"<< Base::get() << "\n end!";
	Derived obj3;
	std::cout << "Valor Base: \n" << Base::get() << "\n end!";
	/*
	for (int i = 0; i < 3; i++) {
		static int var1;
		std::cout << ++var1<<std::endl;
	}
	/*
	std::cout << "Valor Base: \n" << Base::varA << "\n end!";
	std::cout << "Valor OBj1: \n" << obj1.get() << "\n end!";

	std::cout << "Valor OBj2: \n" << obj2.get()<< "\n end!";
	*/
}
