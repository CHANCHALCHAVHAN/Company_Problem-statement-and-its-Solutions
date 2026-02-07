/*
Problem Statement
You are a trader in a volatile market. You are given an array 'prices' where prices[i] is the stock price on the i-th day.

You can perform the following operations:

Buy a stock (you can only hold one stock at a time).
Sell the stock you are holding.
Wait (do nothing).
There are specific rules for COOLDOWNS and BONUSES based on your performance:

Variable Cooldown:
If you sell a stock at a PROFIT (Sell Price > Buy Price), you must wait for 'k' days before you can buy again.
The cooldown 'k' is calculated as: floor(Profit / threshold).
If you sell at a LOSS or BREAK-EVEN, there is NO cooldown (you can buy again the very next day).
Note: You always receive the profit from a sale, even if the resulting cooldown period extends beyond the last day of the price array.
Momentum Bonus:
The market rewards consistency. If you make 3 CONSECUTIVE profitable transactions (Profit > 0), you receive an immediate cash bonus.
The bonus is equal to 10% of the profit of that 3rd transaction (rounded down).
After receiving a bonus, your "consecutive win streak" resets to 0.
Any loss or break-even transaction immediately resets your streak to 0.
Your goal is to maximize your total profit (transaction gains + bonuses) by the end of the given period.

Input Format
First line consist on an integer n, representing the number of days.

Second line consist of n space separated integers representing the prices array.

Third line consist of an integer representing the threshold used for cooldown calculation.

Output Format
Print a single integer representing the maximum possible total profit.

Constraints
1 <= n <= 10^3

1 <= prices[i] <= 10^5

1 <= threshold <= 10^3

The answer is guaranteed to fit within a 32-bit signed integer.

Sample Testcase 0
Testcase Input
6
10 30 10 30 10 30
100
Testcase Output
62
Explanation
Since the threshold is high (100), the cooldown floor(Profit/100) is 0 for all trades of $20 profit.


Buy Day 0 ($10), Sell Day 1 ($30). Profit: +20. Streak: 1
- Cooldown: 0.


Buy Day 2 ($10), Sell Day 3 ($30). Profit: +20. Streak: 2.
- Cooldown: 0.


Buy Day 4 ($10), Sell Day 5 ($30). Profit: +20. 
- Bonus Triggered (3rd win): floor(20 * 0.10) = 2.
- Total for this trade: 22. Streak resets to 0.


Total Profit: 20 + 20 + 22 = 62.

Sample Testcase 1
Testcase Input
6
1 5 2 10 1 5
2
Testcase Output
9
Explanation
Option 1 (Two small trades):


Buy Day 0 ($1), Sell Day 1 ($5). Profit: 4.
- Cooldown: floor(4/2) = 2 days. 
- Must wait Day 2 and Day 3.


Buy Day 4 ($1), Sell Day 5 ($5). Profit: 4.
- Total Profit: 8.


Option 2 (One large trade):


Buy Day 0 ($1), Sell Day 3 ($10). Profit: 9.
- Cooldown: floor(9/2) = 4 days.
- Even though the cooldown lasts until Day 8, you still keep the $9 profit.


 


Since 9 > 8, the maximum profit is 9.

Companies
Topics
Array
Simulation
Dynamic Programming
*/
import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] prices;
    static int threshold;
    static Integer[][] memo;   // memo[i][streak]
    static boolean[][] seen;   // seen[i][streak]

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        n = Integer.parseInt(line.trim());

        prices = new int[n];
        line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        for (int i = 0; i < n; i++) {
            if (!st.hasMoreTokens()) {
                line = br.readLine();
                while (line != null && line.trim().isEmpty()) line = br.readLine();
                st = new StringTokenizer(line);
            }
            prices[i] = Integer.parseInt(st.nextToken());
        }

        line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        threshold = Integer.parseInt(line.trim());

        memo = new Integer[n + 1][3];
        seen = new boolean[n + 1][3];

        int ans = dfs(0, 0);
        System.out.println(ans);
    }

    // dfs(dayIndex, streak) -> maximum profit achievable starting at dayIndex,
    // when NOT holding any stock and current consecutive-win streak = streak (0..2)
    static int dfs(int day, int streak) {
        if (day >= n) return 0;
        if (seen[day][streak]) return memo[day][streak];

        // Option 1: skip this day (do nothing)
        int best = dfs(day + 1, streak);

        // Option 2: buy at 'day' and choose some sell day j >= day
        // (allow selling same day as buy -> profit 0)
        for (int j = day; j < n; j++) {
            int profit = prices[j] - prices[day];
            int newStreak = (profit > 0) ? streak + 1 : 0;
            int bonus = 0;
            if (newStreak == 3) {
                // 10% of the 3rd transaction profit, rounded down
                bonus = profit / 10; // profit > 0 here
                newStreak = 0; // streak resets after bonus
            }

            int cooldown = (profit > 0) ? (profit / threshold) : 0;
            int nextDay = j + cooldown + 1;
            if (nextDay > n) nextDay = n;

            int total = profit + bonus + dfs(nextDay, newStreak);
            best = Math.max(best, total);
        }

        seen[day][streak] = true;
        memo[day][streak] = best;
        return best;
    }
}
