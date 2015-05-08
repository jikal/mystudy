#ifndef _SMART_HOME_H_
#define _SMART_HOME_H_

#include "appliance.h"

class SmartHomaManager{
public:
	~SmartHomaManager();

	static SmartHomaManager* getInstance();

	void setApplianceStatus(Appliance* gadget, bool status);

private:
	SmartHomaManager();

	static SmartHomaManager *manager;
};


#endif
