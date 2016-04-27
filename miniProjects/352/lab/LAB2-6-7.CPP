#include<iostream.h>
#include<conio.h>

void main(){


	int array[5];
	int *ptr=array;

	//enter 5 integer numbers
	cout <<"Enter 5 intefer numbers";
	  for(int i=0;i<5;i++){
		cin>>*ptr;
		ptr++;
	  }
	  // print the array in reverse
		for(int j=0;j<5;j++){
		ptr--;
		cout<<*ptr<<" , ";
	  }
	  cout<<endl;
     //print the array as it is
		for(int k=0;k<5;k++){
		cout<<*ptr<<" , ";
      ptr++;
	  }


getch();

}