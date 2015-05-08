#ifndef _FRUIT_H_
#define _FRUIT_H_

#include <iostream>

using namespace std;

class Fruit{
public:
	virtual ~Fruit() = 0;
	virtual void plant() = 0;
	virtual void grow() = 0;
	virtual void harvest() = 0;
};

class Apple:public Fruit{
public: 
	Apple();
	~Apple();
	void plant();
	void grow();
	void harvest();
};

class Grape:public Fruit{
public:
	Grape();
	~Grape();
	void plant();
	void grow();
	void harvest();
};

class Gardener{
public:
	Gardener();
	~Gardener();
	Fruit* getFruit(int);
private:
	Apple* apple;
	Grape* grape;
};
enum{
 APPLE = 0,
 GRAPE = 1
};
#endif
