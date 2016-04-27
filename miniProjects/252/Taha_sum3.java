import java.util.Scanner;
public class sum3{
  public static void main(String[] args){
    int i, sum=0;
    int [] a=new int[3];
    Scanner scan=new Scanner(System.in);
    System.out.printf("enter the elements of the array\n");
    for(i=0;i<a.length;i++)
    {a[i]=scan.nextInt();
      sum+=a[i];
    }
    System.out.printf("the sum is %d",sum);
     }
  }

