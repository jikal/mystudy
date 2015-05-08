#include <iostream>
using namespace std;

#include "data.h"
using namespace iotek;

int main(int argc , char *argv[]){
	Data data1,data2(2016,2,28);
	data1.Print();
	data2.Print();
	data2.IncreamentDay();
	data2.Print();
	return 0;
}
