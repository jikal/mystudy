#include "data.h"

#include<iostream>
using namespace std;

namespace iotek{
Data::Data()
	:year(1970),month(1),day(1)
{
}

Data::Data(int y,int m,int d)
{
	year = (y > 0) ? y : 1970;
	month = (m >= 1 && m <=12) ? m : 1;
	if(month == 2 && LeapYear(y)){
		day = (d >= 1 && d <= 29) ? d : 1;
	}else{
		day = (d >= 1 && d <= days[month])?d:1;
	}
}

Data::~Data()
{
}

void Data::Print(){
	cout <<year << "/" << month << "/" << day <<endl;
}
void Data::IncreamentDay(){
	if(EndOfMonth(day) && month == 12){
		day = 1;
		month = 1;
		++year;
	}else if(EndOfMonth(day)){
		day = 1;
		++month;
	}else{
		++day;
	}
}
bool Data::LeapYear(int y){
	if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		return true;
	else 
		return false;
}
bool Data::EndOfMonth(int d){
	if(month == 2 && LeapYear(year)){
		return d == 29;
	}else{
		return d == days[month];
	}	
}

}
