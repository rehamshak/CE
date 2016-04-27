import java.util.Scanner;
public class middleWay {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		
	int[]a=new int[3];
	int[]b=new int[3];
	int[]c=new int[2];
	for(int i=0;i<a.length;i++){
		System.out.printf("enter the an Element for array a");
		a[i]=scan.nextInt();
		System.out.printf("enter the an Element for array b");
		b[i]=scan.nextInt();
	}
	System.arraycopy(a,1, c, 0, 1);
	System.arraycopy(b, 1, c, 1, 1);
	System.out.printf("The new array is");
	for(int cc:c)
		System.out.printf("%d",cc);

		
	
		
	}

	}

