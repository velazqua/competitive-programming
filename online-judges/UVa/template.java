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
    while (in.hasNext())
    {
      N = in.nextInt();
      F = in.nextInt();
      BigInteger total = new BigInteger("0");
      for( i=0; i<N; i++ )
      {
        total = total.add(in.nextBigInteger());
      }
    }
  }
}
