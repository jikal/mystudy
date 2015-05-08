#include "cstring.h"
#include <iostream>
using namespace::std;
using namespace::iotek;

int main(int argc, const char*argv[])
{
	String s1("hello");
	String s2 = s1;
	if(s1==s2){
		cout<< "s1==s2" << endl;
	};
	cout << "s2:" << s2.data() << endl;
	String s3 = "world";
	if(s1==s3){
		cout<< "s1==s3" << endl;
	}else{
		cout << "s1!=s3"<< endl;
	}
	s3 = s1;
	cout << "s3:" << s3.data() << endl;
	s3 = "world";
	s1 += s3;
	cout << "s1 = " << s1.data() << endl;
	s3 += "!";
	String s4 = s1 + s2;
	s4 = s1 + "hello";
	cout << "s3 = " << s3.data() << endl;
	cout << "s4 = " << s4.data() << endl;

	return 0;
}
