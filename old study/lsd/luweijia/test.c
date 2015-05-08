#include <stdio.h>
#include <time.h>


int main(){
	time_t start,end;
	double cons;
	time(&start);
	
	sleep(1);
	
	time(&end);
	
	cons = difftime(end,start);
	
	printf("%lf\n",cons);

	return 0;
	
}
