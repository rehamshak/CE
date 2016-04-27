#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define MIN -1
struct Stack {int array[MAX];
 int top;
  };
	void push(Stack *,int);
	 int pop(Stack *);
	  void initializeStack(Stack *);
		int main()
		{ Stack s;
		int stackop,x;
		 initializeStack(&s);
		 while(1){
		  printf("\nto puch in the stack press 1 to pop from stack press 2\n");
		  scanf("%d",&stackop);
		  switch(stackop){
		  case 1:printf("\nenter data you want to push\n");
		  {scanf("%d ",&x);
					push(&s,x);
					break;}
			case 2:{printf("%d is popped",pop(&s));
			break;}}}

			return 0;}
				 void initializeStack(Stack *s)
				  { (*s).top=MIN;
					}
					void push(Stack *s,int number)
					{ if( (*s).top == MAX -1 )
					{ printf("\nArray is Full") ;
               

					 }
					 (*s).top+=1;
					 (*s).array[(*s).top]=number;
					 }
					  int pop(Stack *s)
					  { if( (*s).top == MIN )
					  { printf("\nArray is Empty");
					   }
						int n=(*s).array[(*s).top];
						(*s).top--; return n; }
