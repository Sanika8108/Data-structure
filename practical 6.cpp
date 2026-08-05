#include<iostream>
using namespace std;
int main()
{
	int a=20, b=10;
	int temp=a;
	a=b;
	b=temp;
	cout<<"after swapping:"<<endl;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	return 0;
}
