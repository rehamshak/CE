import java.util.Scanner;
public class reverse{
  public static void main(String[] args)
  {Scanner scan=new Scanner(System.in);
    int [] array=new int[3];
    System.out.printf("Enter the elements of the array\n");
    for(int i=0;i<array.length;i++){
      array[i]=scan.nextInt();
    }
    System.out.printf("the array in the reverse order\n")  ;
    
    for(int i=array.length-1;i>=0;i--){
      System.out.printf("%d",array[i]);
    }
    
  }
}