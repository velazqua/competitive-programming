import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      int N;
      while (true)
      {
         N = in.nextInt();
         if (N == 0) {
            break;
         }
         BigInteger total = new BigInteger("1");
         for(int i = 1; i <= N; i++)
         {
           BigInteger temp = new BigInteger("" + i);
           total = total.multiply(temp);
         }
         int[] numArray = new int[10];
         for(int i = 0; i < 9; i++)
            numArray[i] = 0;
         String S = new String(total.toString());
         for(int i = 0; i < S.length(); i++) {
            numArray[S.charAt(i)-'0']++;
         }
         System.out.println(N + "! --");
         System.out.format("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%4d\n", numArray[0], numArray[1], numArray[2], numArray[3], numArray[4]);
         System.out.format("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%4d\n", numArray[5], numArray[6], numArray[7], numArray[8], numArray[9]);
      }
   }
}
