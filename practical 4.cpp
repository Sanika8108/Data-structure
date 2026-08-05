#include<iostream>
using namespace std;
int main()
{
	int marks;
	int *ptr;
	ptr =&marks;
	
	cout<<"enter the students marks :";
	cin>>*ptr;
	
	cout<<"the marks of the student is "<<*ptr<<endl;
	return 0;
}
