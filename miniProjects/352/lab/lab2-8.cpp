#include<iostream.h>
#include<conio.h>
#include<cstring.h>
void main(){

  string names_array[4][1];
  // enter 4 names
  for(int i=0;i<4;i++){

	  for(int j=0;j<1;j++){
			getline(cin,names_array[i][j]);
  }
  }
  //print the names 
  cout<<"names :"<<endl;
	  for(int q=0;q<4;q++){

	  for(int w=0;w<1;w++){
			cout<<names_array[q][w]<<endl;
  }
  getch();
  }









}