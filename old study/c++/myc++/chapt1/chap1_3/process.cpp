#include"process.h"

#include <iostream>
using namespace std;

namespace iotek{

int get_age(){
	int age = 0;
	cout <<"please input your age:"<<endl;
	cin >> age;

	if(age < 0){
		age = 0;
	}
	if(age > 200){
		age = 200;
	}
	return age;
}

bool process_command_line(int argc, char *argv[]){
	bool ret = false;
	if(argc > 1){
		ret = true;
		return ret;
	}
}

void output_information(bool has_name,char *name){
	if(has_name){
		cout << "My name is " << name << ",";
	}else{
		cout << "My name is secret,";
	}
}
}
