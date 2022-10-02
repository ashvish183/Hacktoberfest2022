import java.util.*;

public class Main{

	public static void main(String[] args) throws Exception{
		/**
	    * Counting Sort
	    */
	    System.out.println(Arrays.toString(countingSort(new int[] { 4, 1, 5, 8, 3 }, 9)));	
	}

	static int[] countingSort(int[] array, int max) {
        int[] list = new int[max + 1];

        for (int i = 0; i < array.length; i++)
            list[array[i]]++;

        int count = 0;
        for (int i = 0; i < list.length; i++) {
            for (int j = 0; j < list[i]; j++)
                array[count++] = i;
        }

        return array;
	   }
}
