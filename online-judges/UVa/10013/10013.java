import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      int N;
      N = in.nextInt();
      for(int i = 0; i < N; i++)
      {
         int M = in.nextInt();
         String num1 = new String(""), num2 = new String("");
         int dig1, dig2;
         for(int k = 0; k < M; k++) {
            dig1 = in.nextInt();
            dig2 = in.nextInt();
            num1 += dig1;
            num2 += dig2;
         }
         BigInteger NUM1 = new BigInteger(num1);
         BigInteger NUM2 = new BigInteger(num2);
         System.out.println(NUM1.add(NUM2));
         if (i != N-1) {
           System.out.println("");
         }
      }
   }
}
