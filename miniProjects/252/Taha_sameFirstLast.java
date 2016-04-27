import java.util.Scanner;
public class sameFirstLast{
	public static void main(String[] args)
	{int[]array=new int[10];
	Scanner scan=new Scanner(System.in);
	System.out.printf("enter the elements of the array\n");
	int count=0;
	for(int i=0;i<array.length;i++)
	{array[i]=scan.nextInt();
	if(array[i]%2==0)
		count+=1;
	}
	System.out.printf("the number of evens is %d",count);	
	}
	
}