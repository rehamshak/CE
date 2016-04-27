#include<iostream.h>
#include<string.h>
#include<fstream.h>

// Check if a string is palindrome and reverce the string
void main(){
char c[150];

cin.getline(c,150);
int last =strlen(c)-1;
int pal=0;


	  for(int first=0;first<last;first++)
		  {
			  if(c[first]!=c[last]){
			  cout<<"word is not palindrome"<<endl;
			  break;  }
			  else pal++;

				last--;
		  }
		  if(pal>=strlen(c)/2)
		  cout<<"palindrome"<<endl;
        /// reverse the word
		for(int reverce=strlen(c)-1;reverce>=0;reverce--)
				  {cout<<c[reverce];}
		  }
