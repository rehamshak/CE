// cNode_linked_list.cpp : Defines the entry point for the console application.
//


#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<conio.h>

int const  MAXSIZE =10;




class Node {
public:
	int info;
	Node *next;
	Node():next(0) {}
	Node(int el, Node *n = 0) {
		info = el;
		next = n;
	}
};


int show_all(Node *head);
Node * reverse(Node *head);

int main()
{
	Node *q[MAXSIZE+1];


	for(int i=0;i<=MAXSIZE;i++){
     q[i]= new Node(i);
	}
	for(i=0;i<MAXSIZE;i++){
     q[i]->info=i;
		q[i]->next=q[i+1];
	}

	q[MAXSIZE]->next=NULL;

	
show_all(q[0]);

show_all(reverse(q[0]));

	/*
    q[0]->info=0;
	q[1]->next=q[2];
	q[1]->info=1;
	q[2]->next=q[3];
	q[2]->info=2;
	q[3]->next=NULL;
	q[3]->info=3;
	*/

    

	 

	getch();
	return 0;
}

Node * reverse(Node *head){
	
	Node *p=head;
	Node *r;
	Node *q;

	q=0;

	while(p!=0){
		r=q; // r follows q

		q=p; // q follows p
		p=p->next; // p moves to next node
		q->next=r; // link q to previous node


	}
return q;

}


int show_all(Node *head){

	Node *current =head;

while(current!=NULL){
		 delay(500);
		 textcolor(12);
		  cprintf("--->")
		 cprintf("[%s]",current->info);
			current=current->next;
	 }



	return 0;

}
