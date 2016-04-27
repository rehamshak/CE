	 #include<iostream.h>
	 #include<math.h>
	 void xyz(int [],int);

	 void main(){int i;int a[]={10,20,30,40,3};
	 for(i=0;i<5;i++)xyz(a,i);
	 for(i=4;i>=0;i--)cout<<a[i]<<",";
	 cout<<endl;
	 }

	 void xyz(int a[],int aa){
	 if (aa%2)a[aa]=sqrt(a[aa]);
	 else a[aa]=pow(a[aa],aa);}
