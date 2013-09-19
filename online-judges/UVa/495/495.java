import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
   public static void main(String[] args)
   {
     // calculate all fibonaccis up to 5000
     ArrayList<BigInteger> fibs = new ArrayList<BigInteger>();// = new BigInteger[5010];
     fibs.add(BigInteger.ZERO);
     fibs.add(BigInteger.ONE);
     for(int i = 2; i <= 5001; i++) {
       fibs.add(fibs.get(i-1).add(fibs.get(i-2)));
     }
      Scanner in = new Scanner(System.in);
      int N;
      while (in.hasNext())
      {
         N = in.nextInt();
         System.out.println("The Fibonacci number for " + N + " is " + fibs.get(N));
      }
   }
}
