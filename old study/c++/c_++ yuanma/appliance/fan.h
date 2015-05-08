#ifndef _FAN_H_
#define _FAN_H_

#include "appliance.h"

class Fan : public Appliance
{
public:
	Fan(int price, int speed);
	~Fan();

	void on();
	void off();
	string toString();

private:
	int m_speed;
};


#endif
