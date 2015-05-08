#include "light.h"

#include <iostream>
#include <stdio.h>
using namespace std;

Light::Light(int price, int color)
	:Appliance("Light",price,false),m_color(color)
{
}

Light::~Light()
{
}

void Light::on()
{
	Appliance::on();
	cout << "light on" << endl;
}

void Light::off()
{
	Appliance::off();
	cout << "light off" << endl;
}

string Light::toString()
{
	char color[32] = {0};
	snprintf(color,32,"%d",m_color);
	string msg = Appliance::toString();
	msg+=",color:";
	msg+=color;

	return msg;
}
