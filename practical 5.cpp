#include<iostream>
using namespace std;
int main()
{
	int a=10, b=20;
	int *p1=&a;
	int *p2=&b;
	if (*p1>*p2)
	cout<<"higher value="<<*p1<<endl;
	else
	cout<<"higher value="<<*p2<<endl;
    return 0;	
}
