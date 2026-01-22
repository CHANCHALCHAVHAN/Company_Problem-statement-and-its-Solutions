/*
Problem Statement
In a futuristic water park, there are N water slides arranged in a straight line. Each slide has a popularity rating which represents how attractive the slide is. Due to crowd control policies, each person visiting the park must select exactly one slide to enjoy.

However, there’s a catch:
If two adjacent slides have people assigned to them simultaneously, it causes a congestion conflict and must be avoided.

Your task is to help the park management assign people to a subset of the slides such that:

No two adjacent slides have people assigned.

The sum of popularity ratings of the chosen slides is maximized.

You are to print the maximum total popularity that can be achieved with valid, non-conflicting assignments.

Input Format
First line contains an integer N

Second line contains N space-separated integers P[1] P[2] ... P[N]

Output Format
Print the maximum total popularity with valid assignments.

Constraints
1 ≤ N ≤ 10^5

-10^4 ≤ P[i] ≤ 10^4

Sample Testcase 0
Testcase Input
4  
-1 -2 -3 -4
Testcase Output
0
Explanation
All slides have negative popularity. Best to select none (i.e., max total popularity = 0).


Output: 0

Sample Testcase 1
Testcase Input
5  
3 2 5 10 7
Testcase Output
15
Explanation
We must skip adjacent slides.


Try selecting slides 1, 3, 5 → 3 + 5 + 7 = 15 Valid


Try slides 2 + 4 → 2 + 10 = 12


Try slides 1 + 4 → 3 + 10 = 13


Max possible = 15


Output: 15

Companies
Topics
Dynamic Programming
Array
Greedy
Sliding Window Technique
Optimization
Dynamic Programming
*/
import java.util.Scanner;

public class Main {

    public static int maxTotalPopularity(int[] P, int N) {
        if (N == 0) return 0;

        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = 0; i < N; i++) {
            int take = prev2 + P[i];
            int skip = prev1;

            int curr = Math.max(skip, take);
            curr = Math.max(curr, 0); // don't take negative totals

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = sc.nextInt();
        }

        int result = maxTotalPopularity(P, N);
        System.out.println(result);

        sc.close();
    }
}
