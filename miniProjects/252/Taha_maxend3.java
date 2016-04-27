/*?? ???? ???? ??? ?????? 021102953*/
import java.util.Scanner;
public class maxend3{
  public static void main(String[]args){
    Scanner scan=new Scanner(System.in);
    int[]array=new int[3];
    System.out.printf("Enter the element of the array\n");
    for(int i=0;i<3;i++)
    {array[i]=scan.nextInt();
      }
      int[]a=new int[3];
      a=max(array);
      System.out.printf("the new array is\n");
      for(int i=0;i<array.length;i++){
      System.out.printf("%d",a[i]);
      
      }
    
  }
  public static int[] max(int[]a){
     int max1=a[0];
     for(int i=0;i<3;i++)
     {if(a[i]>max1)
      max1=a[i];
      
     }
     for(int i=0;i<3;i++){
       a[i]=max1;
     }
     return a;
     }
}