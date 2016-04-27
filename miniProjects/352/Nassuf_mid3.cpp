#include<iostream.h>
int g(int n);
void main()
{int n;
cout<<"enter n: ";cin>>n;cout<<"my result= "<<g(n);}
int g(int n)
{int result=0;
	for(int i=n;i>=0;i--)
		{result=result+i;}

	 return result;
}
