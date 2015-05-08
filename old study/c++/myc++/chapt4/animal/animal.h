#ifndef _ANIMAL_
#define _ANIMAL_
#include <iostream>
using namespace std;

class Animal{
public:
	Animal(){
		cout << "animal constructing" << endl; 
	}
	virtual~Animal(){
		cout << "animal destructing" << endl;
	}
	virtual void makesound() const = 0;
};

class Cat{
public: 
	Cat(){
		cout << "cat constructing" << endl;
	}
	~Cat(){
		cout << "cat destructing" <<endl;
	}

	void makesound() const{
		cout << "cat makesound" << endl;
	}

};

class Dog {
public:
	Dog(){
		cout << "dog constructing" << endl;
	}
	~Dog(){
		cout << "dog destructing" << endl;
	}
	void makesound() const{
		cout << "dog makesound" <<endl;
	}

};
#endif
