#include "appliance.h"

#include <stdio.h>

Appliance::Appliance(const string& name, int price,bool status)
	:m_name(name),m_price(price),m_status(status)
{
}

Appliance::~Appliance()
{
}

void Appliance::on()
{
	setStatus(true);
}

void Appliance::off()
{
	setStatus(false);
}

string Appliance::toString()
{
	char price[32] = {0};
	snprintf(price,32,"%d",m_price);
	string status(m_name+",status:");
	if(m_status){
		status+="on";
	}else{
		status+="off";
	}

	status+=",price:";
	status+=price;

	return status;
}
