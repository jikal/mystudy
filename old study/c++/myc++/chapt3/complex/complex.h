#ifndef _COMPLEX_H_
#define _COMPLEX_H_


#include <iostream>
using namespace std;
namespace iotek{
class Complex {
    friend ostream& operator<<(ostream&, const Complex&);
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator+(int val, const Complex& a);
    friend Complex operator+(const Complex&, int val);
    friend Complex operator+(const Complex&, double val);
    friend Complex operator+(double val, const Complex& a);
public:
    Complex(double = 0.0, double = 0.0);
    ~Complex();
private:
    double real;
    double imag;
};
}
#endif
