#include<conio.h>
#include<stdio.h>
#define size 10

 struct queue
{
int n;
int front;
int back;
char *data;


} car[size];

 void push(char *data);
	void pop(char *data);
int main(){

char *data;

for(int i=0;i<=10;i++) {
car[i].front=-1;
car[i].back=-1;
}



	printf("Enter the name of cars :");
	for(int j=0;j<=10;j++){
	scanf("%s",data);
	 push(data)  ;
	}
		 getch();

	  return 0;
  }

		void push( char *data){
			 for (int n=0;n<=size;n++){

			if (car[n].front==-1 && car[n].front ==-1){
			car[n].data=data;
			printf("%s",*car[n].data);
				break;
				}


		}



		 }








