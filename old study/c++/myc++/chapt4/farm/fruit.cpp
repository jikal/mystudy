#include"fruit.h"

Fruit::~Fruit(){

}

Apple::Apple(){
	cout << "apple constructing" << endl;
}
Apple::~Apple(){
	cout << "apple destructing" << endl;
}
void Apple::plant(){
	cout << "apple planting" << endl;
}

void Apple::grow(){
	cout << "apple grow" <<endl;
}

void Apple::harvest(){
	cout << "apple harvest" << endl;
}

Grape::Grape(){
	cout << "grape constructing" << endl;
}

Grape::~Grape(){
	cout << "grape destructing" << endl;
}

void Grape::plant(){
	cout << "grape plant" << endl;
}

void Grape::grow(){
	cout << "grape grow" << endl;
}

void Grape::harvest(){
	cout << "grape harvest" << endl;
}
Gardener::Gardener(){
	apple = NULL;
	grape = NULL;
}
Gardener::~Gardener(){

}
Fruit* Gardener::getFruit(int type){
	Fruit* fruit = 0;
	if(type == APPLE){
		if(apple == NULL){
			apple = new Apple();
		}
		fruit = apple;
	}else if(type == GRAPE){
		if(grape == NULL){
			grape = new Grape();
		}		
		fruit = grape;
	}
	return fruit;
}

