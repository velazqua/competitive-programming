import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      int N;
      while (in.hasNext())
      {
         N = in.nextInt();
         BigInteger total = new BigInteger("1");
         for(int i = 1; i <= N; i++)
         {
           BigInteger temp = new BigInteger("" + i);
           total = total.multiply(temp);
         }
         System.out.println(N + "!");
         System.out.println(total);
      }
   }
}
