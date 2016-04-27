	#include <iostream.h>
#include <fstream.h>

#include <stdio.h>
#include <string.h>
#include <alloc.h>
#include <process.h>
#include<stdlib.h>
#include<mem.h>

int main(){
 fstream File;

 char ch0;
 char ch1;
 int line=1;
 char s0='f';
 char s1='f';
 int seek=0;
 char *str;
 char tag[60];
  char ctag[60];
 int st;
 int i;
 int valid=1;

 File.open("f:/ccode.c", ios::in  );

		str = (char *) malloc(400) ;

	 memset(str, '\0', 400);
 while(!File.eof()){


  File.get(ch0);
  //	cout << ch0;
	 *(str+seek)=ch0;
	 seek++;

 }
  //	cout << str << "|";
	File.close();
  seek=0;


while(seek<=400){

ch0=*(str+seek);
ch1=*(str+seek+1);
  seek++;

if (ch0=='<' && ch1 !='/'){
	  s1='t'; st=seek+1;}

if (ch0 == '>' && s1=='t'){
	  memset(tag, '\0', 60);
		  (char *) memcpy(tag, str+st-1, seek-st);
			s1='f';  valid++;

			  for(i=seek+1;i<=strlen(str);i++){
			  ch0=*(str+i);
			  ch1=*(str+i+1);

			  if (ch0=='<' && ch1 == '/' ){
			  st= i+2;  s0='t';}

			  if (s0=='t' && ch0 == '>'){
					memset(ctag, '\0', 60);
					 (char *) memcpy(ctag, str+st, i-st);

					  if (strcmp(tag, ctag)==0){
							valid--  ;  cout << ctag << endl;goto end; }

						 s0='f';
					  }

			 }


			  }

		 end:
}

	if (valid==1)
		  cout << endl << "code valid"  ;
		  else {
		  cout << "error"      ;
			 cout << valid		;}
		 cin>>ch0;

	 return 0;


}









