#include<conio.h>
#include<iostream.h>
#include<stdio.h>
void search(float[][5]);
void main (){

	float a[5][5]={
					  {1,2,3,1,5},
					  {7.6,5.2,10.5,4,2.8 },
					  {9,4.7,3.9,2,3.8},
					  {12,3,6.5,5.4,13},
					  {4,7.1,14.2,15,6},
					 };
	float b[5][5]={
					  {4,5.6,7.7,5,3},
					  {3,1.2,4.5,4,9.4 },
					  {2,4.7,6.3,6,3.1},
					  {6,3,8.5,5.2,9},
					  {1,7.1,12.2,18,4},
					  };
	float c[5][5];
	float rightDiagonal=0;
	float leftDiagonal=0;
	float diagonalsSum=0;
	float average=0;
	float largest=a[0][0];

	// matrix a transpose and diagonals sum
	cout<<"matrix a transpose is :\n";
	 for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)
				  { average+=a[i][j];
					 if(largest<a[i][j])
					 largest=a[i][j];
					 if(i==j)
					 leftDiagonal=leftDiagonal+a[i][j];
					  if(i+j==4)
					 rightDiagonal=rightDiagonal+a[i][j];

				  printf("%.1f	",a[j][i]);
				  } //end for

		  cout<<endl;
	 } //end for
	 // multiply  a * b
		 int col=0;
		 int row=0;
		 for(int rows=0;rows<5;rows++){
		 for(col=0;col<5;col++){
		 for(int cols=0;cols<5;cols++){
			 c[rows][col]=c[rows][col]+(a[rows][cols]*b[cols][col]);
		 }//end for
		 }//end for
		 }//end for
	diagonalsSum=leftDiagonal+rightDiagonal;
	average/=25;
	cout<<"the diagonals sum = "<<diagonalsSum<<endl;
	cout<<"the right diagonals sum = "<<rightDiagonal<<endl;
	cout<<"the left diagonals sum = "<<leftDiagonal<<endl;
	cout<<"the average of a = " <<average<<endl;
	cout<<"the largest number in matrix a = "<<largest<<endl;
	//search for a number
	search(a);
	cout<<"sum of a & b = "<<endl;
	//sum of a + b matrixs
	 for(int q=0;q<5;q++){
			for(int w=0;w<5;w++){
			a[q][w]+=b[q][w];
			printf("%.1f	",a[q][w]);}
			cout<<endl;}
	 // print c
	 cout<<"the multiple of a & b= \n " ;
	 for(row=0;row<5;row++){
			for(int col=0;col<5;col++){
			printf("%.3f	",c[row][col]);}
			cout<<endl;}

getch();
}//end main function
//search for a number in a matrix
	void search(float f[][5])
	{  	float s;
			cout<<"search for a number :";
			cin>>s;
			for(int row=0;row<5;row++){
			for(int col=0;col<5;col++){
			if(s==f[row][col])
			printf("the number is in a[%d][%d]\n",row,col);}
			cout<<endl;}
			}
