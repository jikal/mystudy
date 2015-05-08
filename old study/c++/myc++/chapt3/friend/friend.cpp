#include <iostream>

using namespace::std;

class X;

class Y{
public:
	void f(X *);
private:
	X* px;
};
class X{
public:
	void initialize();
	friend void g(X *,int);
	friend void Y::f(X *);
	friend class Z;
	friend void h();
private:
	int i;
};
void X::initialize(){
	i = 0;
}

void g(X *x,int i){
	x->i = i;
}

void Y::f(X *x){
	x->i = 47;
}

class Z{
public:
	void initialize();
	void g(X *x);

private:
	int j;
};
void Z::initialize(){
	j = 99;
}
void Z::g(X *x){
	x->i += j; 
}
void h(){
	X x;
	x.i = 100;
}

int main(){
	X x;
	Z z;
	z.g(&x);
}
