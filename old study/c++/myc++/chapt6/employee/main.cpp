#include "commissionemployee.h"
#include "basepluscommissionemployee.h"

int main(){
	CommissionEmployee *commissionemployeeptr = NULL;
	BasePlusCommissionEmployee basepluscommissionemployee("bob","lewis","333-33-3333",50000,0.04,300);
  	commissionemployeeptr = &basepluscommissionemployee;
	//string firstName = commissionemployeeptr->getFirstName();
	//string lastName = commissionemployeeptr->getLastName();
	//string socialSecurityNumber = commissionemployeeptr->getSocialSecurityNumber();
	//double grossSales = commissionemployeeptr->getGrossSales();
	//double commissionRate = commissionemployeeptr->getCommissionRate();
	
	commissionemployeeptr->print(); 
}

