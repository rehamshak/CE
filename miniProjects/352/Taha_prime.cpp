#include <stdio.h>0
// طه محمود فوزي حسن السوري     021102953
int prime(int x);
void main()
{while(1)
{int n;
int y;
printf("\nenter a real number to check if it's prime\n");
scanf("%d",&n);
if(n<=0)
{printf("error:not real number\n");
continue;}
y=prime(n);
if(y==1)
printf("number is not prime");
if(y==2)
printf("number is prime");
}}
int prime(int x)
{if(x==2)
return 2;
if((x%2)==0)
return 1;
for(int i=3;i<=7;i+=2)
{if(i==x)
continue;
else
if((x%i)==0)
return 1;}
return 2;}
