#include <iostream>
using namespace std;
#include "complex.h"


using namespace iotek;
int main(int argc, char *argv[])
{
    Complex c(1,1);
    cout << c << endl;
    Complex a(2,2);
    Complex b = a + 4.1;
    cout << b << endl;
    b = 4 + a;
    cout << b << endl;
    return 0;
}
