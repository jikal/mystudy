#ifndef _DATA_H_
#define _DATA_H_

namespace iotek{
const int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Data{
public:
	Data();
	Data(int y,int m,int d);
	~Data();
	void Print();
	void IncreamentDay();
	bool LeapYear(int y);
	bool EndOfMonth(int d);
private : 
	int day;
	int month;
	int year;
};



}
#endif
