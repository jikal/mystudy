#include <iostream>
using namespace::std;

inline int max(int x,int y){
	return (x>y?x:y);
}

int main(int argc,char *argv[]){
	int a,b;
	int val;
	cout << "please input a,b:" <<endl;
	cin >> a;
	cin >> b;
	val=max(a,b);
	cout <<"max:"<<val<<endl;
}
