import java.util.*;
public class TapwaterEfficientSol {
    public static void main(String args[]){
        int n;
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter the number of elements you want to store: ");

        n=sc.nextInt();

        int[] arr = new int[10];
        System.out.println("Enter the elements of the array: ");
        for(int i=0; i<n; i++)
        {

            arr[i]=sc.nextInt();
        }
        System.out.println("Rainwater Trapped is: " + getWater(arr, n));
    }
    static int getWater(int arr[], int n)
    {
        int res=0;
        int lMax[] = new int[n];
        int rMax[] = new int[n];

        lMax[0]=arr[0];
        for(int i = 1; i<n;i++)
            lMax[i] = Math.max(arr[i],lMax[i-1]);
        rMax[n-1]=arr[n-1];
        for(int i=n-2; i>=0;i--)
            rMax[i] = Math.max(arr[i],rMax[i+1]);

        for(int i = 1;i<n-1;i++)
            res = res+(Math.min(lMax[i],rMax[i])-arr[i]);

        return res;
    }
}
