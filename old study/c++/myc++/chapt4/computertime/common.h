#ifndef _COMMON_H_
#define _COMMON_H_
#include <string>
using namespace std;
namespace iotek{
class Common{
public:
	Common();
	virtual ~Common(){
	}
	virtual double Speed() = 0;
};


}
#endif
