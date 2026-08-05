#include<iostream>
using namespace std;
void test (int &x , int y)
{
	x+=5;
	y*=2;
	cout<<x<<y;
}
int main()
{
	 int a=3 , b=4;
	 test (a,b);
	 cout<<a<<b;
	 return 0l;
}
