#ifndef _TIME_H_
#define _TIME_H_

namespace iotek{
class Time{
public : 
	Time();
	Time(int h,int m,int s);
	~Time();
	void Print();
	void SetHour(int h);
	void SetMin(int m);
	void SetSec(int s);
	int GetHour();
	int GetMin();
	int GetSec();
	int ReduceTime(Time& temp);
	void IncreamentTime();
	Time operator+(const Time&);

private :
	int hour;
	int min;
	int sec;
};

}
#endif
