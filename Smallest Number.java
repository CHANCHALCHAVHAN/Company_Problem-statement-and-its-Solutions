/*
Problem Statement
You are given N balls in a bag, each ball having a number printed on it representing the ball's power Power[i]. The goal is to identify the smallest power value that cannot be expressed as the sum of the powers of the given balls. You task is to find this smallest value.

Input Format
The first line contains an integer N, the number of balls.
The second line contains N space-separated integers representing the powers of the balls.

Output Format
Print the smallest power value that cannot be expressed as the sum of any subset of the given powers.

Constraints
1 <= N <= 10^5

1 <= Power[i] <= 10^9

Sample Testcase 0
Testcase Input
4
1 2 3 4

Testcase Output
11
Explanation
All the power value less than or equal to 10 can be represented as a sum: 1, 2, 3, 4, 1+4 = 5, 2+4 = 6, 3+4 = 7, 1+3+4 = 8, 2+3+4 = 9 and 1+2+3+4 = 10.


So, the answer is 11 as 11 cannot be represented as a sum of any power value of the given balls.

Sample Testcase 1
Testcase Input
2
1 3
Testcase Output
2
Explanation
1 can be represented as a sum of power value of the ball {1} but 2 cannot be represented as a sum of any power value of the balls.


Hence the answer is 2.

Companies
Paypal
Samsung
Topics
Recursion
Sorting
Dynamic Programming
Array
*/
import java.util.*;

public class Main {

    public static int findSmallestUnexpressiblePower(int[] arr) {
        Arrays.sort(arr);

        long reachableSum = 0; // long to avoid overflow

        for (int power : arr) {
            if (power > reachableSum + 1) {
                return (int)(reachableSum + 1);
            }
            reachableSum += power;
        }

        return (int)(reachableSum + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int result = findSmallestUnexpressiblePower(arr);
        System.out.println(result);
    }
}

