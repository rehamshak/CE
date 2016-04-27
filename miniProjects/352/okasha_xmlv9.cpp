// xmlv8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <io.h>

#include <conio.h>
#include <fcntl.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>    
#include <bitset>
#include <process.h>

		  using namespace std;

long filelength(int handle);
long Sizefile(char *sc) ;

int XMLFILE( char * source,char cmd, char *buffer);
char * attr(string str,int handel);

int DEcrypt( char cmd, char *pathfile);



			// [table] share main data
		  char tag[50][60];
//		  char attr[50][20][60];
		  char value[50][60];
		  char content[50][100]  ;
		  int  offset[50];
		 
		  int    sz[50];
		  int handel=0;

int main()
{

 // args[2]='c'

		char args='c'; /* This parameter will define the work of the main program through it's three values 
	                   [c] Show tags and thir content and anlyze Xml file (Creat a table by properties of the content as the offset , lenght and handel) 
                        [e] Enycript the content of the specified tag and save data in file
                         [D] Dycript the Enycripted file and show in console then save in file          */
                                                                

		int seek=0;
		char *code;
		char buffer[64];
		// args[1]="f:\\ccode.c"
		char path[60]="f:\\ccode.c";
		char ch;
		long Size=Sizefile(path);

		fstream File(path,ios::out | ios::in | ios::binary);

		code = (char *) malloc((int)Size+10)  ;
		memset(code, '\0', (int)Size+10);

		// show file xml
        cout<< "-----------------------------------------------------"<<endl ;
		do{
		seek++;
		File.get(ch);
		cout << ch ;
	   *(code+seek-1) =  ch;
		}while (!File.eof());
	  // cout << code; show all code
		cout<<endl << "-----------------------------------------------------"<<endl;

		
		switch(args){

		case 'c' :
		case 'C' :

		XMLFILE(code,'cc',buffer); 
		getch();
		  break;
		case 'e' :
		case 'E' :
		 XMLFILE(code,'cc',buffer);

		DEcrypt( 'e', path);
		break;
		case 'd' :
		case 'D' :
		cout << "Enter the path of the encrypted file to use algorithm M1 for Decryption:" ;
		cin>> buffer;
		DEcrypt( 'd', buffer); break;


	}

 err:

	  File.close();


	 }


  long Sizefile (char *path){
	int file = open(path, O_CREAT);
	 long  tmpz=filelength(file);
		  close(file);

		 return  tmpz;

		 }


int  XMLFILE(  char * source,char cmd,char *buffer)
{
  //	struct _CXML xml ;
	char ch0;
	char ch1;
	int fs,fs1;
	int ss,ss1;

	 int j;
	 int k=0;
     int l=0;
	 int b=0;
	char f1='f';// flag 1 for state open and close tag
	char f2='f' ;  // flag 2 for state snipe content
	int f3=1 ; // flag 3 for check code is a valid
    int seek;

		  char tmp[100];

	int size=strlen(source)-1;

	 switch(cmd){
	  case 'c':

  /*Count characters*/
	* buffer=size; cout <<endl <<" Number of characters :"<<size<<endl ;

	  /*Count of lines*/
	int numline=0;

		for (j=0;j<=size;j++){

				ch0=*(source+j);

				if (ch0=='\n'){
					numline++; }

					}
				  * buffer=numline; cout <<" Number of lines :"<<(numline+1)<<endl;


  cout <<" analyze the Code :";

    start:


	/////////////////////////////|  Checking .. file xml is a valid  |\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	memset(sz, -1, 20);
	for (j=0;j<=size;j++){

	  ch0=*(source+j);
	  ch1=*(source+j+1);

			 if (ch0=='<' && ch1 !='/'  ){

				fs=j+1;
				f1='t';
				f3-- ;


			 }else if (ch0==' ' && f1=='t'){  k=0;
				

				 while(ch0!='>'  ){
					 if (k==size)
						 goto err1;
                 k++;
		        ch0=*(source+k+j);
				 }
            
             string osrc(source);
			 int xsize=osrc.size();
			 string tattr(source+j,0,k);

           osrc.erase(j,k);  
             source=attr(tattr,handel+1);
			 cout << "osrc.size : " << xsize << " Source :"<<size;
          memset(source,'\0',xsize);
			 memcpy(source,osrc.c_str(),xsize);

         
// cout <<endl<<endl<< osrc.c_str();

			 // return 0; // test
			 cout<<"  *" <<*(source+j);
j--;

			 } else if (ch0=='>'  && f1=='t'  ){

				ss=j;
				
                  handel++;

				

			//	attr(handel,source,ps1,k)
             
               
				offset[handel]=j+1;
				
				memset(tag[handel], '\0', 60);
                f1='c';
				(char *) memcpy(tag[handel], source+fs, ss-fs+1); // copy tag into source 


/*   this part of code check if a code valid or not */

	for ( k=j+1;k<=size;k++){

		ch0=*(source+k);
		ch1=*(source+k+1);

	  if ( ch0=='<' && ch1 =='/' ){

		memset(tmp, '\0', 60);


		  (char *) memcpy(tmp, source+k+2, strlen(tag[handel]));


			if (   strcmp(tmp, tag[handel])==0 && f1=='c'){

		  //	d= offset[handel]-offset[handel-1];

			for (int m=handel-1;m>=0;m--){

				if( sz[m]==k -1  ){
				 	goto jmp1;}

			}
				if  (sz[handel] <=0)
				  f3++;

				  sz[handel]=k-1 ;

				}

			  f1='c' ;

			  }else if ( ch0=='<' && ch1 !='/' && sz[handel] >0){

			f1='s'; goto jmp1; 
	  }
			}

			}
jmp1:;
			}

err1:
	if (f3==1 )
	cout << "The code is valid "<<endl ;
	else {
	cout << "There are errors !"<<endl;
	cout << f3; goto err;}

///////////////////////////////////////////////////////

//  set attributes  //

  
	// -- //



	/* Here the content is captured and linked to some */
handel=0;
		f1= 'f';
		fs=0;ss=0;

	for ( j=0;j<=size;j++){
		ch0=*(source+j);
		ch1=*(source+j+1);

		if (ch0=='<' && ch1 !='/'  ){
		fs=j+1;
		 f1='t';
		  f2='f';

	  //	 xml[hndl].handel=  hndl;
		 }else if (ch0=='>' && f1=='t'  ){
		  ss=j;
			f1='f';


			 handel++;

			 cout << endl << handel <<" j="<<j    ; // this output special to debug
		
			 memset(content[handel], '\0', 100);

	memset(tag[handel], '\0', 60);

	(char *) memcpy(tag[handel], source+fs, ss-fs);


		fs=j+1;
		fs1=j+1;

 //	cout << " j-"<< j<< "| ";

		for ( k=j+1;k<=size;k++){
		ch0=*(source+k);
		ch1=*(source+k+1);

		 //	 if ( ch0=='<' )
		  //	 cout << "#" ;


	  if  (  ch0=='<' && ch1 !='/' ){

			 // cout << "r"  ;

			if (f2=='t'){

				memset(tmp, '\0', 100);
			  (char *) memcpy(tmp, source+fs1, k-fs1);
				strcat(content[handel], tmp);}
				f1='t';

		  }	 else if ( f2=='t' && ch0=='<' && ch1 =='/' ){


					f1='t';
					f2='f';

					memset(tmp, '\0', 100);
					(char *) memcpy(tmp, source+k+2, strlen(tag[handel]));



			if (   strcmp(tmp, tag[handel])==0 && k-1==sz[handel]){


			 cout << "r";

			 memset(tmp, '\0', 100);
			(char *) memcpy(tmp, source+fs1, k-fs1);

		  //  cout <<"?|"<<content[handel]<<"?|"  ;
			 strcat(content[handel], tmp);

		  // fs1=k+3+strlen(tmp);

			goto end;

			} else {
					memset(tmp, '\0', 100);
			(char *) memcpy(tmp, source+fs1, k-fs1);

			  strcat(content[handel], tmp);

			}


			} else if (ch0=='>'  && f1=='t'  ){
			fs1=k+1;f1='f'; }



			// for snipe content
		 if ( (ch0 <7 || ch0>33) && f1=='f'  ) {

			f1='s' ;
			 f2='t';


			}

	}
	 end :
	 f1='f';
			f2= 'f' ;
}

}


	  cout  <<endl ;
		 for(j=1;j<=handel;j++) {

			cout <<endl<<j <<":" ;
			cout<<tag[j]<<" :>"<<content[j];
		 }



		 return 1;


 }
 err:
		return -1;
		 }




 int DEcrypt( char cmd, char *pathfile){
	 int i=0;
	// int byte[7];
	  int seek=0;
	  char byte;
	  char key[6]={'2','5','v','z','A','w'}; // key or password or  Hash #
	 
	  int ord;
		char path[60];
		char ch=0;
		int lenght;
		char *tmp ;
	  long Size=Sizefile(pathfile); // In practice the param will be pointer "pathfile" rather than fixed value 
	 
	  fstream File(pathfile);
	      ofstream sFile;
		 
 tmp = (char *) malloc(Size)  ;
	  memset(tmp, '\0', Size);

  switch(cmd){
	 case 'e':
cout<<endl<< "-----------------------------------------------------"<<endl ;

	  cout  << "* Enter the the tag number to encrypt it's content :"<<endl ;
	  cout <<endl;
	  for(i=1;i<=handel;i++) {

	  cout<<" ["<<i<<"] "<<tag[i];}
	  cout <<endl<<" :>" ;
	  cin >>ord;

	  if ( !isdigit(ord) && (ord < 0 || ord > 20) ) {
			  cout <<endl<< " Invalid value " ;
			  goto err;
		  }




	 

	  cout <<endl<< "Content :" << content[ord];
	  start:

	  cout <<endl<< "* Enter key :"  ;
	  cin>>key;

		

		seek=0;
i=-1;

lenght=strlen(content[ord])-1;
	 do{

 // ebyte._Array=	

		 bitset<8> ebyte (content[ord][seek]);
	 
   i++;
   if (i==6)
	   i=0;

(ebyte ^= key[i] );
(ebyte << key[i] );

byte = (char) ebyte.to_ulong();  
cout  <<byte;
*(tmp+seek)=byte;
 seek++;
	

	}while (seek <=lenght);

		 cout <<endl<< "Enter a path to save the encrypted data :" ;
		cin>> path;
		File.close();
File.open(path, ios::out);
  // File<<byte;
		 for(i=0;i<=seek-1;i++){
	        File<<*(tmp+i);}
File.close();

break;
case 'd':
case 'D':
seek=0;

cout << Size;
cout <<endl<< "* Enter the key for number ""6"" or an alphabet :"  ;
	  cin>>key;

		

	
i=-1;
while(!File.eof()){
 
 // cout << " | >" <<File.seekp(
 // ebyte._Array=	
File.get(ch);

  if (File.eof())
	  goto end;

 bitset<8> ebyte (ch);
	 
   i++;
   if (i==6)
	   i=0;

(ebyte >> key[i] );

(ebyte ^= key[i] );


byte = (char) ebyte.to_ulong();  


*(tmp+seek)=byte;
	seek++;

// cout << !File.eof() << " byte " << byte <<endl;
cout <<byte;
}
 end:

cout <<endl<< "Enter a path to save the decrypted file :" ;
		cin>> path;
		
sFile.open(path, ios::out);
for(i=0;i<=seek-1;i++){
	sFile<<*(tmp+i);
}
sFile.close();
break;


 }
// cout<<tmp;

 







cout<<endl<< " File Saved Succesfuly.. " << path;

err:

getch();
 

  return 0;
 }



char * attr(string content,int handel){

//int size =content.size();
char *u;


u = (char *) malloc(content.size()-1);
 memset(u,'\0',content.size()-1);
  
 // memcpy(tmp,content.c_str(),2);


cout << "\n attr:" << content.c_str()<<endl;
return u;
}


