#include<iostream.h>
#include<conio.h>
void search(int a[], int beg, int end, int item,int n)    // Function to Search Element
		{  for(int i=0;i<n;i++){
		if(beg==end && item!=a[beg])
			  {cout<<"item not found";
			  break;}
		else if(item==a[beg])
			 {cout<<"item found in position :"<<beg;
			  break;}
		else if(item==a[end])
			 {cout<<"item foundin position :"<<end;
			  break;}
		else {int mid=(beg+end)/2;
					if(item==a[mid])
					{cout<<"item found in position :"<<mid;
					break;}
					else if(item<a[mid])
					{end=mid;}
					else{beg=mid;}
			  }
	}
	} //end search

void main(){clrscr();
				int a[100],item,n,beg,end,loc;
				cout<<"\n------- Binary Search using Recursion -------\n\n";
				cout<<"Enter the number of Elements : ";
				cin>>n; cout<<"\nEnter the elements :\n";
				for(loc=0;loc<n;loc++) {
												 cin>>a[loc]; }
				cout<<"\nEnter the Element to be searched : ";
				cin>>item;
				beg=0;
				end=n-1;
				search(a,beg,end,item,n);          // Function Call in Main  Function
				getch();
				}
