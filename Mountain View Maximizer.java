/*
Problem Statement
A group of tourists are visiting a mountain valley with a row of scenic mountain peaks N aligned from west to east. Each peak has a height H[i]. Tourists can be positioned on some of these peaks to get the best possible sunset view. But there's a catch:

A tourist placed on a peak i can enjoy a clear sunset view only if no taller or equally tall peak exists to the west of it (i.e., in positions 0 to i - 1).

Additionally, for environmental reasons, you are allowed to place tourists on at most K peaks.

Your job is to choose up to K positions for placing tourists such that the number of clear sunset views is maximized.

Input Format
First line: Two integers N and K

Second line: N space-separated integers H[0], H[1], ..., H[N-1]

Output Format
Print the maximum number of tourists that can be placed such that each one has a clear sunset view.

Constraints
1 ≤ N ≤ 10^5

1 ≤ K ≤ N

1 ≤ H[i] ≤ 10^9

Sample Testcase 0
Testcase Input
6 10
2 4 7 6 8 9
Testcase Output
5
Explanation
Peaks: 2 4 7 6 8 9


Valid peaks:


2 (index 0) → valid


4 (index 1) → taller than 2 → valid


7 (index 2) → taller than 4 → valid


8 (index 4) → taller than 7 → valid


9 (index 5) → taller than 8 → valid


Total valid = 5


K = 10, so we can choose all of them → Answer = 5

Sample Testcase 1
Testcase Input
5 5
5 4 3 2 1
Testcase Output
1
Explanation
Peaks: 5 4 3 2 1


Only the first peak (5) is the tallest so far → only one tourist can have a clear sunset view.


Total valid = 1, K = 5 → Answer = 1

Companies
Topics
Greedy
Array
Prefix Handling
Observation
One-Pass
Simulation
Greedy Algorithms
*/


import java.util.Scanner;

public class Main {
    // Placeholder for user logic
    public static int maxSunsetViews(int[] heights, int K) {
    int maxSoFar = 0;
    int count = 0;

    for (int h : heights) {
        if (h > maxSoFar) {
            count++;
            maxSoFar = h;
        }
    }

    // You can place tourists on at most K peaks
    return Math.min(count, K);
}


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read N and K
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        int[] heights = new int[N];
        
        // Read N space-separated integers
        for (int i = 0; i < N; i++) {
            heights[i] = scanner.nextInt();
        }
        
        // Call the user logic function and print the result
        int result = maxSunsetViews(heights, K);
        System.out.println(result);
    }
}
