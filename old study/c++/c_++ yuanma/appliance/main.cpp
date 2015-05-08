#include "smarthome.h"

#include "fan.h"
#include "light.h"

#include <iostream>
using namespace std;


int main()
{
	Appliance* light = new Light(1500,WHITE);
	Appliance* fan = new Fan(2000,10);

	SmartHomaManager::getInstance()->setApplianceStatus(light,true);
	SmartHomaManager::getInstance()->setApplianceStatus(fan,true);

	cout << light->toString() << endl;
	cout << fan->toString() << endl;

	SmartHomaManager::getInstance()->setApplianceStatus(light,false);
	cout << light->toString()<< "," << light->getStatus() << endl;
	cout << fan->toString() << endl;


	delete light;
	delete fan;

	return 0;
}
