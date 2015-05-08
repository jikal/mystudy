#include "time.h"
#include <iostream>
using namespace std;

namespace iotek{
Time::Time()
	:hour(0),min(0),sec(0)
{
}

Time::Time(int h,int m,int s)
{
	hour = (h > 0 && h <= 24 ) ? h : 6;
	min = (m >= 0 && m <= 60 ) ? m : 0;
	sec = (s >= 0 && s <= 60 ) ? s : 0;
}
Time::~Time()
{
}

void Time::Print(){
		//IncreamentTime();
		cout << hour << ":" << min << ":" << sec << endl;
		if(hour > 12){
			cout << "pm "<< hour-12 << ":" << min << ":" << sec <<endl;
		}else{ 
			cout << "am "<< hour << ":" << min << ":" << sec <<endl;
		}
}
void Time::SetHour(int h){
	hour=h;
}
void Time::SetMin(int m){
	min=m;
}
void Time::SetSec(int s){
	sec=s;
}
int Time::GetHour(){
	return hour;		
}
int Time::GetMin(){
	return min;		
}
int Time::GetSec(){
	return sec;		
}
void Time::IncreamentTime(){
	if(sec == 59 && min == 59){
		sec = 0;
		min = 0;
		++hour;
	}else if(sec == 59){
		sec =0;
		++min;
	}else{
		++sec;
	}
}
int Time::ReduceTime(Time& temp){
	int s;
	s=(hour-temp.GetHour())*3600+(min-temp.GetMin())*60+(sec-temp.GetSec());
	cout << s << endl;
	return s;
}
Time Time::operator+(const Time& other){
	Time result;
	result.sec = (this->sec + other.sec);
	cout << result.sec << endl;
	if((result.sec) > 60){
		result.sec = result.sec - 60;
		++result.min;
	}
	result.min = (result.min + this->min + other.min);
	if(result.min > 59){
		result.min = result.min - 60;
		++result.hour;
	}
	result.hour = (result.hour + this->hour + other.hour);
	if(result.hour > 24){
		result.hour = result.hour - 24;
	}
	return result;
} 
}
