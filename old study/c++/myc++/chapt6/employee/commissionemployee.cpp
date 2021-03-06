#include <iostream>
#include "commissionemployee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const string& firstname,const string& lastname,const string& ssn,double sales,double rate )
	:firstName(firstname),lastName(lastname),socialSecurityNumber(ssn){
	setGorssSales(sales);
	setCommissionRate(rate);
}

void CommissionEmployee::setFirstName(const string& firstname){
	firstName = firstname;
}

string CommissionEmployee::getFirstName() const{
	return firstName;
}

void CommissionEmployee::setLastName(const string& lastname){
	lastName = lastname;
}

string CommissionEmployee::getLastName() const{
	return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string& ssn){
	socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const{
	return socialSecurityNumber;
}

void CommissionEmployee::setGorssSales(double sales){
	grossSales = sales;
}

double CommissionEmployee::getGrossSales() const{
	return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate){
	commissonRate = rate;
}

double CommissionEmployee::getCommissionRate() const{
	return commissonRate;
}
double CommissionEmployee::earnings() const{
	return getCommissionRate() * getGrossSales();
}
void CommissionEmployee::print() const{
	cout << "commission employee:"
		<< getFirstName() << ' ' << getLastName()
		<< "\n social security number: " << getSocialSecurityNumber()
		<< "\ngross sales:" << getGrossSales()
		<< "\ncommission rate:" << getCommissionRate() << endl;
}


