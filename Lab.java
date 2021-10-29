package com.company;

import java.util.Scanner;

public class Lab {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int size = n;
        int[][] arr = new int[n][n];
        int num = 1;
        int count = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (count++ % 2 == 0) {
                for (int j = 0; j <= i; j++) {
                    arr[i][j] = num++;
                }
                for (int j = i - 1; j >= 0; j--) {
                    arr[j][i] = num++;
                }
            } else {
                for (int j = 0; j <= i; j++) {
                    arr[j][i] = num++;
                }
                for (int j = i - 1; j >=0 ; j--) {
                    arr[i][j] = num++;
                }
            }

        }


        // output array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    }

    /*
    16 15 8  7
    13 14 9  6
    12 11 10 5
    1  2  3  4

       11    10
            9
            8
            7
            6
    1 2 3 4 5
     */


}
