import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    BigInteger sevenTeen = new BigInteger("17");
    while (true)
    {
      BigInteger N = in.nextBigInteger();
      if (N.equals(BigInteger.ZERO))
        break;
      BigInteger num = new BigInteger(N + "");
      if (num.mod(sevenTeen).equals(BigInteger.ZERO)) {
        System.out.println("1");
      }
      else {
        System.out.println("0");
      }
    }
  }
}
