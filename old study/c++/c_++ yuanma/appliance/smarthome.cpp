#include "smarthome.h"

#include <stdio.h>

SmartHomaManager* SmartHomaManager::manager = NULL;

SmartHomaManager::SmartHomaManager()
{
}

SmartHomaManager::~SmartHomaManager()
{
}

SmartHomaManager* SmartHomaManager::getInstance()
{
	if(manager == NULL){
		manager = new SmartHomaManager();		
	}

	return manager;
}

void SmartHomaManager::setApplianceStatus(Appliance* gadget, bool status)
{
	if(status){
		gadget->on();
	}else{
		gadget->off();
	}
}
