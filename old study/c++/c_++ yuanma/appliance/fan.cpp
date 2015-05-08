#include "fan.h"
#include <stdio.h>

#include <iostream>
using namespace std;

Fan::Fan(int price, int speed)
	:Appliance("Fan",price,false),m_speed(speed)
{
	
}

Fan::~Fan()
{
}

void Fan::on()
{
	Appliance::on();
	cout << "fan roll" << endl;
}

void Fan::off()
{
	Appliance::off();
	cout << "fan stop" << endl;
}

string Fan::toString()
{
	char speed[32] = {0};
	snprintf(speed,32,"%d",m_speed);
	string msg = Appliance::toString();
	msg+=",speed:";
	msg+=speed;

	return msg;
}
