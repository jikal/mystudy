#include <iostream>
using namespace std;

#include "time.h"
using namespace iotek;
int main(int argc,char *argv[]){
	Time time1(23,10,59);
	Time time2(10,10,10);
	Time time3;
	time3 = time1 + time2;
	time3.Print();
	time1.ReduceTime(time2);
	time1.Print();
	//time1.ReduceTime(time2);
	
	return 0;
}
