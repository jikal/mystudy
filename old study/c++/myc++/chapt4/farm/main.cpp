#include "fruit.h"

int main(){
	Gardener Tom;
	Fruit* fruit = Tom.getFruit(APPLE);
	fruit -> plant();
	fruit -> grow();
	fruit -> harvest();
	delete fruit;
	return 0;
}
