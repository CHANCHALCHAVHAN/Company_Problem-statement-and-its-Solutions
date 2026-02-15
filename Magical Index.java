/*
Problem Statement
Alice and Bob attend an event where there are N people, each either poor (requiring money) or rich (donating money). Alice can only move left, while Bob can only move right from a starting index i, called the "Magical Index." They both start with 0 money, collecting from the rich and giving to the poor as they move. The goal is to find a starting index i such that, after their respective movements, Alice and Bob end with the same amount of money.

The input is an array of size N, where negative values represent poor people, and non-negative values represent rich people. If any value is zero, it represents a rich person donating 0 money. The task is to determine if such a starting index exists where both Alice and Bob end with equal amounts of money.

Input Format
The first line contains an integer N, the size of array.
The second line contains N space-seprated elements - the array

Output Format
The output should return the smallest magical index if it exists; otherwise, return -1.

Constraints
1 <= N <= 10^5. 

0<=|A[i]| <=10^5 

Sample Testcase 0
Testcase Input
7 
5 -7 1 0 6 -11 4
Testcase Output
4
Explanation
The given array is 5 -7 1 0 6 -11 4. Here Magical index is 4 because A[0]+A[1]+A[2]= A[5]+A[6] +A[7].


Alice will end up with an amount -1, and Bob will also end up with an amount -1.of Hence, the result will be 4.

Sample Testcase 1
Testcase Input
5
1 2 3 4 5
Testcase Output
-1
Explanation
No index is a magical index.
Companies
Cisco
Dell
IBM
Topics
Prefix Sum
Array

*/
import java.util.*;

public class Main {
    public static int magicalIndex(int[] arr) {
        int n = arr.length;

        long totalSum = 0;
        for (int val : arr) {
            totalSum += val;
        }

        long leftSum = 0;

        for (int i = 0; i < n; i++) {
            long rightSum = totalSum - leftSum - arr[i];

            if (leftSum == rightSum) {
                return i + 1; // 1-based index
            }

            leftSum += arr[i];
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        int result = magicalIndex(arr);
        System.out.println(result);
    }
}
