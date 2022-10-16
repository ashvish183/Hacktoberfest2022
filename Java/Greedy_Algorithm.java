/*

Problem: You have to make a change of an amount using the smallest possible number of coins.
Amount: $18

Available coins are
  $5 coin
  $2 coin
  $1 coin
There is no limit to the number of each coin you can use.

*/

// package Java;
import java.util.Vector;
public class Greedy_Algorithm{

    static int deno[] = {1, 2, 5};
        static int n = deno.length;
     
        static void findMin(int V)
        {
            Vector<Integer> ans = new Vector<>();
            for (int i = n - 1; i >= 0; i--)
            {
                while (V >= deno[i])
                {
                    V -= deno[i];
                    ans.add(deno[i]);
                }
            }
            for (int i = 0; i < ans.size(); i++)
            {
                System.out.print(
                    " " + ans.elementAt(i));
            }
        }

        public static void main(String[] args)
        {
            int n = 18;
            System.out.print(
                "Following is minimal number "
                +"of change for " + n + ": ");
            findMin(n);
        }
}