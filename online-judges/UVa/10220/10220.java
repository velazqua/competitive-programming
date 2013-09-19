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
         int summ = 0;
         String S = new String(total.toString());
         for(int i = 0; i < S.length(); i++) {
            summ += S.charAt(i)-'0';
         }
         System.out.println(summ);
      }
   }
}
