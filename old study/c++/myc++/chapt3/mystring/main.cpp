#include "cstring.h"

#include <assert.h>
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace iotek;

int main(int argc, char *argv[]){
	const char *p = NULL;
	
	char c = 0;

	String s1;
	String s2(true);
	String s3(2);
	String s4(2.1);
	String s5("hello");
	String s6('a');
	
	bool ret = s2.toBool();
	assert(ret = true);

	int val = s3.toInt();
	assert(val == 2);
	
	double val2 = s4.toDouble();
	cout << val2 << endl;

	String s7 = s5;
	String s8(s2);

	s1.append('a');
	s1.display();

	s5.append('c');
	s5.display();

	s5.append(p);
	s5.display();

	s5.append("world");
	s5.display();

	s5.append(s3);
	s5.display();
	if(s5.chomp(c)){
		cout << c <<endl;
	}
	s5.display();

	return 0;
}
