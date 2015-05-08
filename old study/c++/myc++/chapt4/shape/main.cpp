#include <iostream>
using namespace::std;
#define PI 3.1415927
class Shape{
public:
	Shape(){
		
	}
	virtual ~Shape(){
		cout << "shape" << endl;
	}
	virtual double GetArea() = 0;
	virtual double GetPerim() = 0;

};

class Rectangle:public Shape{
public:
	Rectangle(double a_a, double b_b)
	{
	a=a_a;
	b=b_b;
	}
	~Rectangle()
	{
	cout << "rectangle"<<endl;
	}
	virtual double GetArea() { 
		return a * b; 
	}	 
	virtual double GetPerim(){
		return 2*( a + b ); 	
	}
private:
	double a;
	double b;
};

class Circle:public Shape{
public:
	Circle(double r_r){
	r = r_r;
	}
	 ~Circle() {
	 	cout << "rectangle"<<endl;
	}

	virtual double GetArea(){
		return r*r*PI;
	}
	virtual double GetPerim(){
		return 2*r*PI;
	}
private:
	double r;
};

int main(int argc,char* argv[]){
	/*
	double length, width;
	cout << "输入长和宽: ";
	cin >> length >> width;
	Rectangle rect(length, width);
	cout << "面积是："<< rect.GetArea() << endl<<"周长是："<<rect.GetPerim()<<endl;
	*/
	Shape *shape = new Circle(10);
	cout << "s=" << shape->GetArea() << ";C=" << shape->GetPerim() << endl;
	delete shape;
	return 0;

}
