#include <iostream> 
using namespace std;
class Shape  //定义抽象基类 Shape
{
public:
	virtual double area() const = 0;
};
  
class Rectangle:public Shape //定义 Rectangle(矩形)类 
{
public:  
	Rectangle(double w,double h)
		:width(w),height(h)
	{	
	}  
	virtual double area() const {
		return width*height;
	} 
	protected:  
		double width,height;                                           
};


class Triangle:public Shape//定义 Triangle(三角形)类 
{
public:  
	Triangle(double w,double h):width(w),height(h)
	{
	}  
	virtual double area() const {
		return 0.5*width*height;
	}
protected:  
	double width,height;
}; 
 
int main() {
	double areas;
	Triangle triangle(4.5,8.4);
	Rectangle rectangle(4.5,8.4); 
	Shape *pt[2]={&rectangle,&triangle};
	for(int i=0;i<2;i++){
		areas=areas+pt[i]->area();
	}  
	cout<<"totol of all areas="<<areas<<endl;   //输出总面积 
	return 0;
}

