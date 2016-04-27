 //  ?? ????? ???? ??? ??????? 021102953
                             import java.util.Scanner;
public class project2{
  public static void main(String[] args)
  {  Scanner scan=new Scanner(System.in);
    for(int i=1;i<=10;i++)
    {int x,y,z;
      gradeStudent();
      System.out.printf("Enter the first test grade(0-100)\n");
      x=scan.nextInt();
      if((x<0)||(x>100))
      
          {System.out.printf("Error repeat entering grades betwwen 0-100");
        continue;}
        if(x==-1)
        break;
      
      System.out.printf("Enter the second test grade(0-100)\n");
      y=scan.nextInt();
      if((y<0)||(y>100))
        {System.out.printf("Error repeat entering grades betwwen 0-100");
        continue;}
        if(y==-1)
        break;
        System.out.printf("Enter the homework grade(0-100)\n");
        z=scan.nextInt();
        if((z<0)||(z>100))
      
          {System.out.printf("Error repeat entering grades betwwen 0-100");
          continue;}
          if(z==-1)
          break;
          
          
          
          double av=calculateAverage(x,y,z);
          System.out.printf("First test:%d\n",x);
        System.out.printf("Second test:%d\n",y);
        System.out.printf("Homework:%d\n",z);
        System.out.printf("Average:%f\n",av);
          if(av<60)
        System.out.printf("letter grades:F\n");
        if((av>=60)&&(av<70))
          System.out.printf("letter grades:D\n");
        if((av>=70)&&(av<80))
        System.out.printf("letter grades:C\n");
        if((av>=80)&&(av<90))
          System.out.printf("letter grades:B\n");
        if(av>=90)
          System.out.printf("letter grades:A\n");
          
        GoldStars(x,y,z);}
      
          
        
      
       System.out.printf("thank you for using this program good bye!");}



  
      public static void gradeStudent()
      {
        System.out.printf("\nA student's letter grade will be calculated\n from the data is entered at the prompts.\nA gold star will be issued for each grade 90 and above.\nPlease use whole numbers only.Thanks!\n");
        
      }
      public static double calculateAverage(int a,int b,int c)
      {double average=(double)(a+b+c)/3;
        return average;
      }
      public static void GoldStars(int a,int b,int c)
      {if(a>=90)
    System.out.printf("*");
    if(b>=90)
        System.out.printf("*");
    if(c>=90)
    System.out.printf("*");
    
  }
    
  }
    
    
