#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<dos.h>


#define size 6



 struct queue
 {
 char data[50];

 }car[size];

 int drawqueue(int x, int y  , struct queue i[size]) ;
void  drawbarstate(int x,int y,char lbl) ;
void mainframe (int x,int y);
 char *dequeue();

  int add(char *data);
  void del();

  int front=0;
  int back=0;
  char msg[20]="  No item! ";
  int main(){

	   char *data;
	   char buffer;




       //	   delay(2500);



 draw:

	   mainframe(2,4);
	   drawbarstate  (1,30,'s') ;
	   drawqueue(10, 15 ,  car);

		    buffer= getch();

		     if (buffer == 'a' || buffer == 'A'){
				printf("	+");
				scanf("%s",data);
			       clrscr();
				add(data);

		      } else if (buffer == 'd' || buffer == 'D') {
				  printf("	-");
				  clrscr();
			      //	  del();
			 printf("%s is Deleted",dequeue());
				//  printf("  Front = %d : back = %d \n:>",front,back);

		      }  else {
				  goto end;

		      }

	 //	del   ();        // delete car 0
       //	 del   ();   // delete car 1


		    goto draw;
 end:

      //	 getch();

		    return 0;
			   }

 int add(char *data)
  {
   /* add an item to the queue */

    back = (back +1) % size;

      if (front == back) {
	 drawbarstate  (1,30,'f')   ;

	 return 0;
      }

	(char *) memcpy(car[back].data,data, strlen(data));

    err1:
      return 1;
  }

char *  dequeue()
  {

     /* remove front element from the queue and put it in item */

	  if (front == back) {
	    drawbarstate  (1,30,'e')   ;
	    return msg ; }
	   /* queue_empty returns an error key */
	 front = (front+1) % size;

     return car[front].data;
     }





int drawqueue(int x, int y , struct queue qc[size]){


int c=14; // draw road
	   //  clrscr();


     for (int i=x;i<=60;i++){

       if (c==14)
	c=7;
       else
	c=14;

     textcolor(c);
      gotoxy(i,y);
	cprintf("-");
	  gotoxy(i,y+2);
	   cprintf("-");
	   }

	textcolor(9);
	int shift=0;


	 gotoxy(x,y-1) ;
	 int d=back-front;
	for(int k=1;k<=d;k++){

	   cprintf("%d",k) ;

	    shift=shift +1+strlen(qc[k+front].data);
	    gotoxy(x+shift,y-1);

	}
	  textcolor(10);
	  shift=0;
	  gotoxy(x,y+1) ;

	for(k=front;k!=back+1;k=(k+1)%(size+1)){

	   cprintf(qc[k].data) ;

	    shift=shift +1+strlen(qc[k].data);
	     gotoxy(x+shift,y+1);
	}




 return 0;
}


void mainframe(int x,int y){

   textcolor (15);
   gotoxy(x,y);

   cprintf("size of circular queue is %d \n" ,size);
    gotoxy(x,y+1);
   cprintf("\npress 'a' to add item  or 'd' to delete item");
    gotoxy(x,y+2);
   cprintf( "\nor 'e' to end " );










}

  void  drawbarstate(int x,int y,char lbl)  {

	textcolor(14);
	gotoxy(x,y);

	cprintf("--------------------------------------------------------------------------------");

       gotoxy(x,y+2);
	cprintf("--------------------------------------------------------------------------------");
	  textcolor(11);
	  gotoxy(x+1,y+1);
	    // switch !
     //	  if (lbl=='s')

	  switch(lbl){
	  case 'f':
	   textcolor(12);
	   cprintf("  Front = %d : back = %d  [ queue is fall ]",front,back) ;
	       break;
	  case 'e':
	  textcolor(12);
	  cprintf("  Front = %d : back = %d  Error! the queue is Empty!\n ",front,back) ;
	       break;
	  default:

	     cprintf("  Front = %d : back = %d  ",front,back) ;
	       }
   }