
#include <io.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include<stdlib.h>
#include <process.h>

void Sizefile(char *st, long * ds);
long filelength(int handle);
 void Analiyzor(char *hh,char * sda);
 int isKeyWord(char *word);
char last_Keywords[17]  ;

 char Keywords[62][17]= {"int","for","asm","auto","bool","break","case","catch","char","class"
"const","const_cast","continue","default" ,"delete","do","double","dynamic_cast","else","enum"
,"explicit" ,"extern","false","float","for","goto","if","inline","int","long","mutable","new"
,"operator","private","protected" ,"namespace" ,"public","register","reinterpret_cast","short"
,"signed","sizeof","static","static_cast","struct","return","switch","template","this", "true"
, "try", "throw", "typedef", "typeid", "typename" ,"union","unsigned","using","virtual","void"
,"volatile","wchar_t","while"};

int main(void)
{
	FILE *file;
	char path_file[50]="f:\\code.c";


	  char ch ;
	  long pE;
	  long *Size =&pE;

		int seek=0;
		char *code ;
		char *memTmp;

		 Sizefile(path_file,Size);

	 code = (char *) malloc((int)*Size+1)  ;
		memTmp  = (char *) malloc((int)*Size+1)  ;
			memset(code, '\0', (int)*Size-1);
			 memset(memTmp, '\0', (int)*Size-1);
	 if (code== NULL)
	 printf("No Enough Heap Memory \a");
	 else
	 printf("Preparation Program ...\n");



	file = fopen(path_file, "a+");
		fseek(file, 0, SEEK_SET);
		 printf("\n\nOpening file ...\n");
	  printf("+----------------------------------------------------+\n");
	do
	{



		ch = fgetc(file);
		*(code+seek) =ch;
			seek++;


	} while (seek != *Size);
 //	printf(">%s<",code)  ;
	 printf("\n+----------------------------------------------------+\n");
	 //	printf("%d",*Size) ;
		 Analiyzor(code,memTmp);

		free(code);
	fclose(file);



	return 0;
}





 void Sizefile (char *path, long *Size){
	int file = open(path, O_CREAT);


		 *(Size)=	 filelength(file);
		  close(file);
		 }





  void Analiyzor(char *code,char *memTmp){


	char  ch0;
	char  ch1;
	int indx1=0;
	int indx2=1;
	int i=0;
	 int g=0;
	do{
	 ch0=*(code+i);
	 ch1= *(code+i+1);

	 i++;
	 if ((ch0 >7 && ch0<33 )&&  (ch1<8 || ch1>32 ) ){            // [][*]
		indx1=i;
		 g=0;
		}
		 else if(((ch0<8 || ch0>32 ) ) && ( (ch1 >7 && ch1<33  ) || i==strlen(code))) {           // [*][]
		  strncat(memTmp, (code+indx1), indx2);
		  memset(last_Keywords, '\0', 17);
		  strncat(last_Keywords, (code+indx1), indx2);
if ( isKeyWord(last_Keywords) ==1) {
printf("\n this Word[%s] is KeyWord",last_Keywords ) ;

}

			 indx2=1;
				;}
			else if (( (ch0<8 || ch0>32 ) && (ch0<8 || ch0>32 ))){ //   [*][*]
		 indx2=++indx2+g;
		 }
		  // **********



	//printf(" [%d -%c-] ",ch0,ch0) ;
	}while(i!=strlen(code))  ;

	// printf(">%s<",memTmp) ;

		  free(memTmp);

  }








 int isKeyWord(char *word){
  int i;
  for (i=0;i<=61;i++){
	if ( !strcmp(word, Keywords[i]) )
		return 1 ;
  }
 }

