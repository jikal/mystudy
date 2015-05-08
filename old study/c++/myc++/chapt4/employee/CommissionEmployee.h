#ifndef _COMMISSION_H_
#define _COMMISSION_H_

#include <string> 
using namespace std;

class CommissionEmployee
{
public:
   CommissionEmployee( const string &, const string &, const string &, 
      double = 0.0, double = 0.0 );
   
   void setFirstName( const string& ); 
   string getFirstName() const; 

   void setLastName( const string& ); 
   string getLastName() const; 

   void setSocialSecurityNumber( const string& );
   string getSocialSecurityNumber() const;

   void setGrossSales( double );
   double getGrossSales() const;

   void setCommissionRate( double );
   double getCommissionRate() const;

   double earnings() const;
   void print() const;
private:
   string firstName;
   string lastName;
   string socialSecurityNumber;//社保号码
   double grossSales;//销售总额
   double commissionRate;//佣金率
};

#endif

