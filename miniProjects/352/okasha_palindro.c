#include<stdio.h>
#include<conio.h>
#include<string.h>

const int max=20;

struct palend{

	char ch;

}stack[max];


 int pop(int *sp,char *ch);
 int push(int *sp,char ch);

int main (){

	int sp=-1;
				char ch='f';
				char pal[20];
				 char tpal[20];
				 int count=-1;
				 int ptr ;
		  printf("Enter palindrome word for check :");

		  memset(pal, '\0', 20);
		  memset(tpal, '\0', 20);

				 while(1){
				 count++;

				 ch=getch();
				 if (ch==13)
				 break;
				 pal[count]=ch;
				 printf("%c",ch) ;
				 push(&sp,ch);
				 }

             

				printf("\n")  ;


				  for (int i=0;i<count;i++){
					pop(&sp,&ch);
					printf("-%s-",ch);
					tpal[count]=ch;
				  }

				  /* strcmp example */
	ptr = strcmp(tpal, pal);
				 printf("-[%s][%s] = %d",tpal,pal,ptr);
			if (ptr==0)
				 printf("\nthis word is palindrom word : )" );
				 else
				 printf("\nthis word is not palindrom word  :(" );





	 /* push(&sp,c) ;
	  c='o';
		 push(&sp,c)     ;






							 */

return 0;
}

int pop(int *sp,char *ch) {

 if (*sp==-1){
		 printf("\n stack is empty! \n");
		 return 1 ;}

	*ch=	stack[(*sp)--].ch;





 return 0;
}

int push(int *sp,char ch) {

 if (*sp>=max-1 ){
		 printf("\n stack Over flow \n");
		 return 1 ;}

		stack[++*sp].ch= ch;





 return 0;
}
