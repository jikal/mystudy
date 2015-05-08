#include "plane.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[]){
	
	Common* plane = new Plane(argv[1],10,10,10);
	cout << plane->Speed()<<endl;

	return 0;
}




