#include<stdio.h>
#include<conio.h>
#include<string.h>

const int size=20;

struct palend{

	char ch;

}stack[size];

enum _operator {
  plus =0,
  minus=0 ,
	cross=1 ,
	dev =1,
	expo =2




};

 int pop(int *sp,char *ch);
 int push(int *sp,char ch);

 int infixTopostfix(char *infix,char  *postfix);
 float evaluatepostfix(char *postfix);
 float Evaluate (char ch ,int s4hift ,int s2hift ,float *val,float ans);
int main (){




				char infix[20];
				 char postfix[20];
					 // float value[3]={5,6,8};  // for test
					  //	 printf("\n Evaluate  postfix = %f",Evaluate('+',"ab",value));

				// int count=-1;
				// int ptr ;
		  printf("Write infix expression for convert to postfix and evalute :");

		  scanf("%s",infix);

			 memset(postfix, '\0', 20);
		  infixTopostfix(infix,postfix);

		  printf("\n	postfix Exprestion :%s",postfix) ;

	 float var=	  evaluatepostfix(postfix);
		  printf("\n Evaluate  postfix = %f",var);
				  //  	 printf("\n Enter value of %c",infix[i]) ;
			// scanf("%f",value[i]) ;


				getch();





return 0;
}

int pop(int *sp,char *ch) {

 if (*sp==-1){
	  //	 printf("\n stack is empty! \n");
		 return 1 ;}

	*ch=	stack[(*sp)--].ch;





 return 0;
}

int push(int *sp,char ch) {

 if (*sp>=size-1 ){
		 printf("\n stack Over flow \n");
		 return 1 ;}

		stack[++*sp].ch= ch;





 return 0;
}





int infixTopostfix(char *infix,char *postfix){

		int sp=-1;
	 int shift=-1;
		char testvar;
		enum  _operator toprtr , ttoprtr ;


for(int i=0;i<strlen(infix);i++){


	 if ((infix[i]<='z' && infix[i]>='a' ) || (infix[i]<='Z' && infix[i]>='A')) {
	 // operand

		postfix[++shift]=infix[i];
		}else if(infix[i]=='(')   {                     // operator

			push(&sp,infix[i]);
	  } else if(infix[i]==')') {

		while(!pop(&sp, &postfix[++shift])) {
		// ^_^
        if (postfix[shift]=='(')
			  shift--;
		}

		if (postfix[--shift]=='(') {

		  postfix[shift]=='\0';
		  shift--;

		  }

		}else if((infix[i]>41 && infix[i]<48 ) || infix[i]==94) {


	 int test=		pop(&sp,&testvar);

				 if (test==1)
				 goto jmp1;

				 push(&sp,testvar);

			switch(testvar){
			 case '+' :
			  case '-' :
			 ttoprtr=0;
			 break;
			 case '*' :
			 case '/' :
			 ttoprtr=1;
			 break ;
			 case '^':
			 ttoprtr=2;

			}


				switch(infix[i]){
			 case '+' :
			  case '-' :
			 toprtr=0;
			 break;
			 case '*' :
			 case '/' :
			 toprtr=1;
			 break ;
			 case '^' :
			 toprtr=2;

			}

			jmp1:
			if(testvar=='(' || test==1 ||  (ttoprtr - toprtr < 0  )){

			push(&sp,infix[i]) ;
			}else if (ttoprtr - toprtr >= 0) {
			pop(&sp,&postfix[++shift]);

			  push(&sp,infix[i]);
			}




	 } // loop





} // main if




 while((pop(&sp,&postfix[++shift])-1)){
	  // ^_^

	 }
		\
	  postfix[shift]='\0';







 return 0;
}


float  evaluatepostfix(char *postfix){

		float value=0;
		double ans;

		int shift_var=-1;
		int j=0;
		int var[size] ;
		float val[size];
		int shift_sub=-1;


for(int i=0;i<strlen(postfix);i++){

		if ((postfix[i]<='z' && postfix[i]>='a' ) || (postfix[i]<='Z' && postfix[i]>='A')){
		 ++shift_var;
		 if (shift_sub==-1 )
		 shift_sub=shift_var;

			 for(j=shift_var;j>=0;j--){

			  if (var[j]==postfix[i]){
					val[shift_var]==val[j];
					goto jmp1;
					}

			}

			 var[shift_var] =   postfix[i];
			 printf("\n	Enter value of variable %c=",var[shift_var]);
			 scanf("%f",&val[shift_var]) ;





		jmp1:

		}else {


			if(postfix[i]>41 && postfix[i]<48) {

			ans=Evaluate(postfix[i],shift_sub,shift_var,val,ans) ;


			shift_sub= -1;

			}

		}




 }











return ans;
}


float Evaluate(char ch,int shift_sub, int shift_var,  float *val,float ans ){
	  float iVal=0;
		float eqval=0;
		  float pVal=0;


 // for (int i=shift_sub;i<shift_var;i++){

	pVal=val[shift_var];

      if  (shift_sub== shift_var)
		 pVal=0;

	 switch(ch){





	 case '+':
	ans=  ans + val[shift_sub]+pVal;
	// val[i]=val[i]+eqval  ;
	 iVal=ans;

	  break;
	  case '-':
	//	val[i]=val[i]-eqval  ;   // pval = pval -C !
 pVal=pVal   + val[1];
iVal=pVal;
	  break;
	 case '*':
	 pVal=pVal*val[1]  ;
	 iVal=pVal;
	 break;
	 case '/':
	 pVal=pVal/val[1]  ;
	 iVal=pVal;
	 break;
	}

	//  printf("	*[%f]",iVal)
 //	}




return iVal;
}
