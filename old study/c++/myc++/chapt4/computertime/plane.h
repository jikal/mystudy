#ifndef _PLANE_H_
#define _PLANE_H_

#include "common.h"
using namespace iotek;
class Plane : public Common{
public:
	Plane(const string& tool,int a,int b,int c);
	~Plane(){
	}
	double Speed();
private:
	string toolname;
	int A;
	int B;
	int C;
};
#endif
