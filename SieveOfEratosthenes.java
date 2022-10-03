/*-----------------------------------------------------------------
Sieve of eretosthenes is one of the most efficient ways to 
find all primes smaller than n when n is smaller than 10 million.
-------------------------------------------------------------------*/
import java.util.*;

class SieveOfEratosthenes
{
	public static void main(String[] args) {
	    
	    int n = 100;
		List<Integer> primeNumbersList = sieve(n);
		
		for(int i=0; i<primeNumbersList.size(); i++)
		    System.out.print(primeNumbersList.get(i) + " ");
		    
	}
	
	static List<Integer> sieve(int n){
        
        List<Integer> list = new ArrayList<>();
        
        boolean prime[] = new boolean[n + 1];
        
        for (int i = 0; i <= n; i++)
            	prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true){
                // all multiples of p cannot be prime
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        // adding all prime numbers
        for (int i = 2; i <= n; i++){
            if (prime[i] == true)
                list.add(i);
        }
        return list;
    }
}