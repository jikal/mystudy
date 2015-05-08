#include "plane.h"
Plane::Plane(const string& tool,int a,int b,int c)
	:toolname(tool),A(a),B(b),C(c)
{

}

double Plane::Speed(){
	return 1000/(A+B+C);
}
