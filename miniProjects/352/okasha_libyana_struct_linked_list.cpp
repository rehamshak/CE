// linked_list_e.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int num = 2;

 struct libyana_node{

	 char name[20];
	 int id;
	 float balance;
	 char number_phone[9];

	 struct libyana_node* next;
 };

 struct libyana_node * Generation();
 int show_all(struct libyana_node * head);
 int add(struct libyana_node * head);
struct libyana_node * udelete(struct libyana_node * head,char nump[9]);


int main()
{
	char ch;
	char NumberPhone[9];

	 struct libyana_node * head = Generation();

	 show_all(head);

edit:
	 cout<<"\n\n	do you want add new user? type 'a' ";
	 ch=getch();
	 if(ch=='a' || ch=='A' )
	 {
add(head);
show_all(head);
goto edit;
	 }

_delete:

	 cout<<"\n\n	do you want delete any user? type 'd'";
	 ch=getch();
	 if (ch=='d' || ch=='D'){
		 cout << " Enter number phone :";
 cin>>NumberPhone;
 head=   udelete(head,NumberPhone);
   show_all(head);
    goto _delete;
	 }





	getch();

	return 0;
}


int  show_all(struct libyana_node * head) {

	 struct libyana_node * current = head;

	 for(;current != NULL;){

              //  cout<<"\n id account "<<current->id<<
				printf("\n id account %d user name %s ",current->id,current->name);
					printf("\n balance %f ",current->balance);
						printf("\n Number Phone %s \n",current->number_phone);

				current=current->next;

			   }





  return 0;



}




struct libyana_node * Generation()
{

///////


	struct libyana_node *new_node[num+1] ;
	int i;

//-------------------------/////////

for(i=1;i<=num;i++){

new_node[i] =( libyana_node * ) malloc(sizeof(struct libyana_node));

if (new_node[i]==NULL)
goto err;

}


for(i=1;i<=num;i++){

//randomize();
new_node[i]->id= i+1;                   //random (500+);

cout<<"\nPlease enter your name :";
			cin>>new_node[i]->name;

cout<<" Enter your number phone :";
			cin>>new_node[i]->number_phone;


new_node[i]->balance=rand()*10;
new_node[i]->next=new_node[i+1];

}
   new_node[num] ->next=	NULL;


return new_node[1];


err:

printf("\n	Error! in generation process , not enough memory ");

return 	NULL;
}

int add(struct libyana_node * head){

struct libyana_node *current=head;
struct libyana_node *newNode;


newNode=( libyana_node * ) malloc(sizeof(struct libyana_node));
	 for(;current->next != NULL;){

				current=current->next;

			   }

current->next=newNode;
newNode->next=NULL;

/////////////////////


newNode->id= current->id+1;                   //random (500+);


cout<<"\nPlease enter your name :";
			cin>>newNode->name;


cout<<" Enter your number phone :";
			cin>>newNode->number_phone;


newNode->balance=rand()*10;


	return 0;
}


struct libyana_node * udelete(struct libyana_node *node,char nump[9]){

	struct libyana_node *current=node;
	struct libyana_node *tmp=NULL;
	struct libyana_node *head;
	struct libyana_node *tail;

	int count=0;


	while(current!=NULL){
count++;
		if (strcmp(current->number_phone,nump)==0){
			tmp=current;
break;
		}
		tail=current;
current=current->next;
	}

	if (count==NULL){
		cout<<"\n\n list empty!";
return node;
	}else if(tmp==NULL){
		cout<<"\n\n	Number phone "<< nump<<" not found in list !";

	return NULL;
	}



	 if( count ==1){
			head=current->next;
			delete(current);
			return head;
	 }else if(current==NULL){

     delete(tail);
	 } else{

		 tail->next=current->next;
		 delete(current);
		 return node;

	 }





	return 0;
}
