
#include<stdio.h>
#include<stdlib.h>
#define null 0
struct node{int data;
struct node *next;};
struct node * insert(struct node *,int );
void printlist(struct node *);
struct node * sort(struct node*);
struct node *merge(struct node *,struct node *);
int countnodes(struct node *);
int countnodes(struct node *p)
{int count=0;
while(p!=null)
{p=p->next;
count+=1;}
return count;}
void main(){
struct node *list1=null;
struct node *list2=null;
int x;
int n;
struct node *merged=null;;
while(1)
{printf("press '1' to insert node to the first linked list,'2' to the second linked list and '3' to display the merged linked list\n");
scanf("%d",&n);
switch (n)
{case 1:{printf("enter the number you want to put in the node\n");
scanf("%d",&x);
list1=insert(list1,x);
break;}
case 2:{printf("enter the number you want to put in the node\n");
scanf("%d",&x);
list2=insert(list2,x);
break;}
case 3:{list1=sort(list1);
list2=sort(list2);
merged=merge(list1,list2);
printlist(merged);

break;}
}}}
struct node* insert(struct node *p,int x)
{struct node *temp;
if(p==null)
{p=(struct node *)malloc(sizeof(struct node));
p->data=x;
p->next=null;}
else
{temp=p;
while(temp->next!=null)
temp=temp->next;
temp->next=(struct node *)malloc(sizeof(struct node));
temp=temp->next;
temp->data=x;
temp->next=null;
}
return p;}
void printlist(struct node *p)
{while(p!=null)
{printf("%d ",p->data);
p=p->next;}}
struct node *sort(struct node *p)
{struct node *temp1,*temp2;
int i,j,n,temp;
 n=countnodes(p);
for(i=1;i<n;i++)
{temp1=p;
temp2=p->next;
for(j=1;j<(n-i);j++)
{if(temp1->data>temp2->data)
{temp=temp2->data;
temp2->data=temp1->data;
temp1->data=temp;}
temp1=temp1->next;
temp2=temp2->next;
}}return p;}
struct node *merge(struct node *p1,struct node *p2)
{struct node *r=null,*temp;
if(p1==null)
{r=p2;
return r;}
else if(p2==null)
{r=p1;
return r;}
else
{
if(p1->data<p2->data)
{r=p1;
temp=p1;
p1=p1->next;
temp->next=null;}
else
{r=p2;
temp=p2;
p2=p2->next;
temp->next=null;}
while((p1!=null)&&(p2!=null))
{if(p1->data<p2->data)
{temp->next=p1;
p1=p1->next;
temp=temp->next;
temp->next=null;}
else
{temp->next=p2;
p2=p2->next;
temp=temp->next;
temp->next=null;}}
if(p1==null)
temp=p2;
if(p2==null)
temp=p1;}
return r;}










