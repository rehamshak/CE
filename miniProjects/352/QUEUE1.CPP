#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<dos.h>


#define size 10


 struct queue
 {
 char data[50];

 }car[size];

 int drawqueue(int x, int y  , struct queue i[size]) ;
void  drawbarstate(int x,int y,char lbl) ;
void mainframe (int x,int y);

  void add(char *data);
  void del();

  int front=-1;
  int back=-1;

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
				  del();

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

	 void add( char *data){

	      if (back+1<size){
				 back++;
	      } else{
	       drawbarstate  (1,30,'f') ;
			       //	 printf(" Error! out of size queue is Fall!\n");
				 goto err1;
	      }

	      (char *) memcpy(car[back].data,data, strlen(data));

		   //	printf("%s",car[back].data);

    err1:


  }


 void del(){

	      if (front!=back){
				 front++;
	      } else{
	      drawbarstate  (1,30,'e') ;
			       //	 printf(" Error!\n the queue is Empty!\n");
	      }






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

	for(k=front+1;k<=back;k++){

	   cprintf(qc[k].data) ;

	    shift=shift +1+strlen(qc[k].data);
	     gotoxy(x+shift,y+1);
	}




 return 0;
}


void mainframe(int x,int y){
   textcolor (15);
   gotoxy(x,y);

   cprintf("size of queue is %d \n" ,size);
    gotoxy(x,y+1);
   cprintf("\npress 'a' to add item  or 'd' to delete item");
    gotoxy(x,y+2);
   cprintf( "\nor 'e' to draw queue " );










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