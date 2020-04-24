#include<iostream>

using std::cout;
using std::endl;

// Объявления классов, без них ничего работать не будет, это C++
class A;
class B;
class A1;


class A1 {
private:
	// Указатель на родителя
	A* parent;
public:
	//NB: передаётся указатель на родителя через this (см 48)
	A1(int a, A* root) {
		cout << "A1: " << a << endl;
		parent = root;
	}

	A* getParent() {
		return parent;
	}

};

class A {

private:
	int number;
	// Ука на B, передаётся через A::addRef (см 44)
	B *refToB;

public:
	A(): number(1) {
		refToB = nullptr;
	}

	A(int aInit) : number(aInit) {
		refToB = nullptr;
	}
	// Передача указателя
	B* getRefToB() {
		return refToB;
	}
	// Передача ссылка на себя в конструкторе A1
	A1 createA1() {
		return A1(number, this);
	}

	void addRef(B* newRef) {
		refToB = newRef;
	}

};

class B {

public:
	void printToCout(const char* text) {
		cout << "B: " << text << endl;
	}

};

int main() {

	auto a = A(23);
	// Создадим B
	auto b = B();
	// Передадим указатель на него
	a.addRef(&b);

	auto a1 = a.createA1();
	// A1 -> A > B -> печать из B
	a1.getParent()->getRefToB()->printToCout("Hello, world!");

}