#include <iostream>

#include "basepluscommissionemployee.h"
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &firstname,const string &lastname,const string &ssn, double sales,double rate,double salary)
	:CommissionEmployee(firstname,lastname,ssn,sales,rate){
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary){
	if(salary >= 0.0){
		baseSalary = salary;
	}else {
		cout << "Salary must be >= 0.0" << endl;	
	}
}

double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const{
	return getBaseSalary() + CommissionEmployee::earnings();
} 

void BasePlusCommissionEmployee::print() const {
	cout << "base - salaried";
	CommissionEmployee::print();
	cout << "\nbase salary: " << getBaseSalary();
}
