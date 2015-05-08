#include "complex.h"


namespace iotek{
Complex::Complex(double r, double i)
    :real(r),imag(i)
{
}
Complex::~Complex()
{
}
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real << " + " << c.imag << "i" << endl;
    return out;
}

Complex operator+(const Complex& a, const Complex& b)
{
    return Complex(a.real + b.real,a.imag + b.imag);
}
Complex operator+(const Complex& a, int val)
{
    return Complex(a.real + val, a.imag);
}
Complex operator+(int val,const Complex& a)
{
    return Complex(a.real + val, a.imag);
}
Complex operator+(const Complex& a, double val)
{
    return Complex(a.real + val, a.imag);
}
Complex operator+(double val,const Complex& a)
{
    return Complex(a.real + val, a.imag);
}
}
