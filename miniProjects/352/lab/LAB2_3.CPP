#include<iostream.h>
#include<conio.h>
long int factorial(long int);
long int factorial1(long int);
void main(){

int n,m,k;
double fact,fact1;
cout<<"Enter n ,m ,k : \n";
cin>>n>>m>>k;
if(n<0||m<0||k<0||n<m)
{cout<<"you entered a negetive numbers or n < m "<<endl;}
else{
fact=(double)(factorial(n)*factorial(m)*factorial(k))/(factorial(n-m)*factorial(k));
cout<<"the exeprition fact="<<fact<<endl;
fact1=(double)(factorial1(n)*factorial1(m)*factorial1(k))/(factorial1(n-m)*factorial1(k));
cout<<"the exeprition fact1="<<fact1<<endl;}
getch();
}
// not recursion factorial
long int factorial(long int fact){
	long int factorial=1;
	while(fact!=0){
		factorial=factorial*fact;
	    fact--;
	}
     return factorial;    
}
// recursion factorial
long int factorial1(long int fact){
	if(fact==1||fact==0)
		return 1;  
	else
		return fact*factorial(fact-1);    



}