#include <iostream>

#include "employee.h"

using namespace std;

int main(int argc , char *argv[]){
	char name1[32] = "kevin";
	char adress1[32] = "jiangsu";
	char postcode1[32] = "200000";
	Employee a(name1,adress1,postcode1,1990,5,24,2015,3,15);
	a.display();
	a.changeName();
	a.display();
	return 0;
}
