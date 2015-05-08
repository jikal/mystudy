#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "data.h"

class Employee{
public:
	Employee(char *name,char *adress,char *postcode,int,int,int,int,int,int);
	void display();
	char *getName(){
		return name;
	}
	char *getAdress(){
		return adress;
	}
	char *getPostcode(){
		return postcode;
	}
	void changeName();
	//void changeAdress();
	//void changePostcode();
	~Employee();
private:
	char name[32];
	char adress[32];
	char postcode[32];
	const Data hiredate;
	const Data birthdate;
};
#endif
