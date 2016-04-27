

///////////////////// A program that makes 2 doubly linked lists    ////////////////////////////

///////////////////////////////////////// Read me first ////////////////////////////////////////
/*----------------------------------------Read me first------------------------------------------*/
/*----------------------------------------Read me first------------------------------------------*/
/*----------------------------------------Read me first------------------------------------------*/
////////    to insert to first list     							  head=insert(your  input , head)
////////    to insert to second list     							  head2=insert(your  input , head2)
////////    to print the first list 								  print(head);
////////    to print the second list 								  print(head2);
////////    to reverse the first list                                 head=reverse(head);
////////    to reverse the second list                                head2=reverse(head2);
////////    to delete a node from the first list                      head=deleteNode(enter place of node , head);
////////    to delete a node from the second list                     head2=deleteNode(enter place of node , head2);

#include<iostream.h>

struct node{

		int data;
		node *next,*before;
};
// 2 list head and 2 end of list
node *head,*head2,*temp,*last,*last2;


// a new node at the beggening of the list you choose
node* insert(int y,node*temp2){

								temp=new node;
								temp->data=y;

								if(temp2==NULL){
														temp->next=temp2;
								}
								else{
										temp2->before=temp;
										temp->next=temp2;
                              temp->before=NULL;
								}
								if(temp2==head && last==NULL)  last=temp2;
                        if(temp2==head2 && last2==NULL)  last2=temp2;
								temp2=temp;
								return temp2;


}
// delete the node you don't want in the list you choose
node* deleteNode(int place,node* temp2){
					node *del=temp2->next;
					node *d=temp2;
					if (place==1){
									temp2=temp2->next;
									temp->before=NULL;
									return temp2;
					}
					else if(place==2){
											temp2->next=del->next;
                                 del->next->before=temp2;
											return temp2;
					}
					else {
								for(int i=2;i<place;i++){
										  d=del;
										  del=del->next;

								}
								if(del->next==NULL){
										d->next=del->next;}
								else{
										d->next=del->next;
										del->next->before=d;
								}
					}
              return temp2;

}
// shows the data of the list you choose
void print(node*temp2){

					cout<<"list :\n";
					for(node* ptr=temp2;ptr!=NULL;ptr=ptr->next){
					cout<<ptr->data<<endl;

					}

}

// reverse the list you choose
node* reverse(node *temp2){

					 node *t;
					 if(temp2==head){
											for(node* ptr=last;ptr!=NULL;ptr=ptr->next){
														t=ptr->before;
														ptr->before=ptr->next;
														ptr->next=t;
											}
											t=temp2;
											temp2=last;
											last=t;
					 }
					 else if(temp2==head2){
											for(node* ptr=last2;ptr!=NULL;ptr=ptr->next){
														t=ptr->before;
														ptr->before=ptr->next;
														ptr->next=t;
											}
											t=temp2;
											temp2=last2;
											last2=t;
					 }
											return temp2;



}
// the main program
void main(){
		//initialize the heads and ends (( don't change ))
		head=NULL; head2=NULL; last=NULL; last2=NULL;
		

}// end of program
