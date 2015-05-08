#include "process.h"
using namespace iotek;

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	int age = 0;
	bool has_name = false;
	char *name = NULL;

	has_name = process_command_line(argc, argv);	

	age = get_age();

	if(has_name)
	{
		name = argv[1];
	}

	output_information(has_name, name);

	cout << age << " years old.\n";
	return 0;
}
