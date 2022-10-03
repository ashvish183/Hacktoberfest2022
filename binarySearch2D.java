// Binary Search approach to search for an element in an ascendingly sorted in row wise and column wise 2D matrix

import java.util.Arrays;

public class binaryIn2dArray {
    public static void main(String[] args) {
        // Matrix sorted in row and col wise
        int[][] arr={
                {10,20,30},
                {15,25,35},
                {17,27,37}
        };
        int target= 27;
        System.out.println(Arrays.toString(search(arr,target)));
    }
    public static int[] search(int[][] matrix, int target){
        int row=0;
        int col=matrix.length-1;
        while( row < matrix.length && col >= 0){
            if ( matrix[row][col] ==  target){
                return new int[] {row,col};
            }else if( matrix[row][col] > target){
                col = col - 1;
            }else {
                row = row + 1;
            }
        }
        return new int[] {-1,-1};
    }
}
