#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "appliance.h"

#define WHITE 1
#define GREEN 2

class Light : public Appliance{
public:
	Light(int price, int color);
	~Light();

	void on();
	void off();
	string toString();

private:
	int m_color;
};


#endif
