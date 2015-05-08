#include <iostream>
using namespace std;

#include <string.h>
#include <stdio.h>
#include "employee.h"

Employee::Employee(char *hname,char *hadress,char *hpostcode,int by,int bm,int bd,int hy,int hm,int hd)
	:hiredate(hy,hm,hd),birthdate(by,bm,bd)
{
	int len = strlen(hname);
	len = (len < 31) ? len : 31;
	memset(name,0,32);
	strncpy(name,hname,len);

	len = strlen(hadress); 
	len = (len < 31) ? len : 31;
	memset(adress,0,32);
	strncpy(adress,hadress,32);

	len = strlen(hpostcode);
	len = (len < 31) ? len : 31;
	memset(postcode,0,32);
	strncpy(postcode,hpostcode,32);

}

void Employee::display(){
	cout << "name: " << name << " /adress: " << adress << " /postcode: " << postcode << " ";
	cout << "/birthdate: ";
	birthdate.Print();
	cout << "/hirdate: ";
	hiredate.Print();
	cout << endl;
}
void Employee::changeName(){
	char name[32] = {0};
	memset(name,0,32);
	cout << "please input new name : " << endl;
	cin >> name;
	if(name != NULL){
		strcpy(this->name,name);
	}
	char adress[32] = {0};
	memset(adress,0,32);
	cout << "please input new adress: " << endl;
	cin >> adress;
	if(adress != NULL){
		strcpy(this->adress,adress);
	}
	char postcode[32] = {0};
	memset(postcode,0,32);
	cout << "please input new postcode: " << endl;
	cin >> postcode;
	if(adress != NULL){
		strcpy(this->postcode,postcode);
	}		
}
Employee::~Employee(){

}
