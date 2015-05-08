
#ifndef _BASEPLUS_H_
#define _BASEPLUS_H_

#include <string> 
#include "CommissionEmployee.h"
using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
   BasePlusCommissionEmployee( const string &, const string &, 
      const string &, double = 0.0, double = 0.0, double = 0.0 );
   
   void setBaseSalary( double );
   double getBaseSalary() const;

   double earnings() const;
   void print() const;
private:
   double baseSalary;
};

#endif
