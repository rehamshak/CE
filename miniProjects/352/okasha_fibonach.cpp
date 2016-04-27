#include<iostream.h>

void fibonachi(int n,int l,int p);
int main()
{
	 int num;
	 cout << " Enter Number fibonachi :"  ;
	 cin >> num;

	 fibonachi(num,0,0);


 return 0;
}


 void fibonachi(n,l,p) {
  int ne;
 if (p==0) {
 cout<< "1 ,";
  p=1;
 }

 if (p+l<n) {
 ne=p+l ;
 cout << ne << " ,";
 l=p;
 p=ne;
 fibonachi(n,l,p);
  }else if (p+l==n) {
				cout << p+l << " ,";
 }


  }










