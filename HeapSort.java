import java.util.Scanner;

public class HeapSort {
    public void sort(int a[]) {
        int n = a.length;

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);

        for (int i = n - 1; i > 0; i--) {

            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;

            heapify(a, i, 0);
        }
    }

    void heapify(int arr[], int n, int i) {
        int max = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[max])
            max = l;

        if (r < n && arr[r] > arr[max])
            max = r;

        if (max != i) {
            int swap = arr[i];
            arr[i] = arr[max];
            arr[max] = swap;

            heapify(arr, n, max);
        }
    }

    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n;
        // System.out.print("Enter no. of elements you want in array:");
        n = s.nextInt();
        int arr[] = new int[n];
        // System.out.println("Enter all the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        // s.close();

        HeapSort ob = new HeapSort();
        ob.sort(arr);

        System.out.println("Sorted Array : : ");
        printArray(arr);
    }
}
