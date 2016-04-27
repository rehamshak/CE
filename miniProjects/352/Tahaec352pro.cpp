#include<stdio.h>
void main()
{int year,day,month,y,m,a,d;
int daysinmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
printf("Enter date in the following format  dd mm yyyy\n");
scanf("%d %d %d",&day,&month,&year);
a=(14-month)/12;
y=year-a;
m=month+12*a-2;
d=(day+y+y/4-y/100+y/400+31*m/12)%7;
switch(d)
{case 0:
{printf("Sunday\n");
break;}
case 1:
{printf("Monday\n");
break;}
case 2:
{printf("Tuseday\n");
break;}
case 3:
{printf("Wednesday\n");
break;}
case 4:
{printf("Thursady\n");
break;}
case 5:
{printf("Friday\n");
break;}
case 6:
{printf("Saturday\n");
break;}
}
if((year%4==0)&&(year%100!=0)||(year%400==0))
daysinmonth[2]=29;
int n=daysinmonth[month];


printf("sun mon tue wed thur fri sat\n");
for(day=1;day<=n;day++)
{d=(day+y+y/4-y/100+y/400+31*m/12)%7;
if((d!=0)&&(day==1))
{for(int i=1;i<=d;i++)
{printf("    ");}}
if(d==0)
printf("\n");
printf("  %2d",day);
}}


