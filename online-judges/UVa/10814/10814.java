import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    for(int i = 0; i < N; i++)
    {
      BigInteger a = in.nextBigInteger();
      String d = in.next();
      BigInteger b = in.nextBigInteger();
      BigInteger GCD = a.gcd(b);
      System.out.println(a.divide(GCD) + " / " + b.divide(GCD));
    }
  }
}
