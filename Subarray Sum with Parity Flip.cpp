/*
Problem Statement
In a game of numbers, an array A of N integers is considered "parity-flippable" if a continuous subarray exists such that:

When even numbers in the subarray are increased by 1 and odd numbers are decreased by 1, the sum of the modified subarray becomes exactly K.

You're given an integer array A and an integer K. Your task is to count the number of contiguous subarrays where this transformation leads to a sum of exactly K.

Input Format
First line contains two integers N and K denoting the number of integers and the sum of the modified subarray becomes exactly K.


Second line contains N space-separated integers representing the array A.

Output Format
Print a single integer — the number of contiguous subarrays where the parity-flipped sum equals K.

Constraints
1≤N≤2×10^5

−10^9≤A[i]≤10^9

−10^15≤K≤10^15

Sample Testcase 0
Testcase Input
5 10
2 3 4 1 6
Testcase Output
2
Explanation
 Let's evaluate all subarrays and apply the transformation:



[2] → 2 + 1 = 3 ≠ 10


[2,3] → 2+1 + 3-1 = 3 + 2 = 5


[2,3,4] → 3 + 2 + 5 = 10 (Valid)


[3,4,1] → 2 + 5 + 0 = 7


[4,1,6] → 5 + 0 + 7 = 12


[4,1] → 5 + 0 = 5


[4,1,6] → 5 + 0 + 7 = 12


[2,3,4,1] → 3 + 2 + 5 + 0 = 10 (Valid)



Valid subarrays = 2.

Sample Testcase 1
Testcase Input
4 0
1 -1 2 -2
Testcase Output
3
Explanation

[1] → 1+1→2 


[1, -1] → 2+(-2) → 0 (Valid)


[-1, 2] → (-2)+3→ 1


[2,-2] → 3+(-3) → 0 (Valid)


[-1, 2, -2] → (-2)+ 3+(-3) → -2  


[1, -1, 2, -2] → 2+(-2)+3+(-3)→ 0 (Valid)


Correct answer is 3.

Companies
Topics
Prefix Sum
Subarray
Hash Map
Difference Array
Array
*/
import java.util.*;

public class Main {
    public static int count_parity_flipped_subarrays(int n, long k, int[] arr) {
        // Step 1: Transform array
        long[] transformed = new long[n];
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                transformed[i] = (long) arr[i] + 1; // even → +1
            } else {
                transformed[i] = (long) arr[i] - 1; // odd → -1
            }
        }

        // Step 2: Prefix sum + hashmap
        Map<Long, Integer> prefixCount = new HashMap<>();
        prefixCount.put(0L, 1); // base case: empty prefix
        long prefixSum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += transformed[i];

            // Check if prefixSum - k exists
            long target = prefixSum - k;
            if (prefixCount.containsKey(target)) {
                count += prefixCount.get(target);
            }

            // Update map
            prefixCount.put(prefixSum, prefixCount.getOrDefault(prefixSum, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = scanner.nextInt();
        }
        int result = count_parity_flipped_subarrays(n, k, arr);
        System.out.println(result);
        scanner.close();
    }
}
