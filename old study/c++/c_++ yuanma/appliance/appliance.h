#ifndef _APPLIANCE_H_
#define _APPLIANCE_H_

#include <string>
using namespace std;

class Appliance{
public:
	Appliance(const string& name, int price,bool status);
	virtual ~Appliance() = 0;

	virtual void on() = 0;
	virtual void off() = 0;
	virtual string toString();

	void setName(const string& name) 
	{
		m_name = name;
	}

	string getName() const
	{
		return m_name;
	}

	int getPrice() const 
	{
		return m_price;
	}

	void setPrice(int price)
	{
		m_price = price;
	}

	bool getStatus() const 
	{
		return m_status;
	}

	void setStatus(bool status)
	{
		m_status = status;
	}


protected:
	string m_name;
	int m_price;

	bool m_status;
};


#endif
