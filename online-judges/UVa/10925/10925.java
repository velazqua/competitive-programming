import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      int N;
      int F;
      int c = 1;
      while (true)
      {
         N = in.nextInt();
         F = in.nextInt();
         if( N == 0 && F == 0 )
            break;
         int i;
         BigInteger total = new BigInteger("0");
         for( i=0; i<N; i++ )
         {
            total = total.add(in.nextBigInteger());
         }
         System.out.println("Bill #"+c + " costs "+ total + ": each friend should pay " + total.divide(BigInteger.valueOf(F))+"\n");

         c += 1;
      }
   }
}
