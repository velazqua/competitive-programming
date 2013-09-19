import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
  public static void main(String[] args)
  {
    ArrayList<ArrayList<BigInteger>> As = new ArrayList<ArrayList<BigInteger>>();
    for(int A = 0; A <= 15; A++) {
      BigInteger Abig = new BigInteger("" + A);
      BigInteger total = new BigInteger("0");
      ArrayList<BigInteger> temp = new ArrayList<BigInteger>();
      temp.add(BigInteger.ZERO);
      for(int i = 1; i <= 150; i++) {
        BigInteger I = new BigInteger("" + i);
        total = total.add(Abig.pow(i).multiply(I));
        temp.add(total);
      }
      As.add(temp);
    }
    Scanner in = new Scanner(System.in);
    int N;
    int a;
    while (in.hasNext())
    {
      N = in.nextInt();
      a = in.nextInt();
      System.out.println(As.get(a).get(N));
    }
  }
}
