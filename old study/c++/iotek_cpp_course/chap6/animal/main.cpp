#include "animal.h"



void func(Animal *panimal)
{
	panimal->makeSound();
}

int main()
{
	Animal *pcat = new Cat;

	func(pcat);

	delete pcat;

	return 0;
}
