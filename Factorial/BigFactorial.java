import java.util.Scanner;
import java.math.BigInteger;
class fact {
  public static void main(String[] args) {
    
    int n;
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    BigInteger ans=factr(n);
    System.out.println(ans);
  }
  public static BigInteger factr(int n)
  {
    BigInteger factorial=BigInteger.valueOf(1);
    for(int i=1;i<=n;i++)
    {
      factorial=factorial.multiply(BigInteger.valueOf(i));
    }
    return factorial;
  }
}
