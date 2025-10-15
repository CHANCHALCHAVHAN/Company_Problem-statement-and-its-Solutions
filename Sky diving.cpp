Problem Statement
John Wick, our favorite character, wants to practice skydiving using a special set of K identical parachutes in his apartment building. The building has N floors, and he wants to determine the highest floor f (where 0≤ f≤ N ) from which he can safely jump without the parachute failing.

Each attempt, John can choose a floor x  (where 1≤ x ≤ N ) to jump from. If the parachute fails at a floor higher than f, it is no longer usable. If the parachute does not fail, it can be reused in future attempts.

Your task is to determine the minimum number of attempts John needs to make to find the threshold floor f with certainty.

Input Format
The first line  contains 2 integers N and K denoting the number of floors and number of parachutes respectively.

Output Format
The output contains a single integer denoting the minimum number of attempts needed to successfully perform the task.

Constraints
0<=N<=10^3

0<=K<=50

Sample Testcase 0
Testcase Input
2 2 
Testcase Output
2
Explanation
The first parachute can be dropped from floor 1 while the second parachute may be dropped from floor 2. We know that f = 0 if the first parachute fails. We know that f = 1 if the second parachute fails but the first parachute does not. Otherwise, we know that f = 2 if both parachutes survive.

Sample Testcase 1
Testcase Input
100 2
Testcase Output
14
Explanation
One of the possible way to figure out is : 


One good method is to drop the first parachute on the ninth floor. We know f is between 0 and 8 if it breaks. Drop the second parachute beginning on level 1 and working your way up one by one until you reach floor 8, where you'll discover f. The total number of droplets is 1 + 8 = 9. - If the first parachute does not fail, drop it on floor 22 again. We know f is between 9 and 21 if it breaks. Drop the second parachute beginning on level 10 and work your way up one by one to locate f within 12 drops. The total number of drops is 2 + 12 = 14. - If the first parachute does not break, repeat steps 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100, dropping the first parachute from floors 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100. It takes at most 14 drops to determine f, regardless of the result.

Companies
Microsoft
Amazon
Topics
Math
Dynamic Programming
Recursion

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minAttempts(int N, int K) {
    // dp[k][n] = minimum attempts needed with k parachutes and n floors
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

    // Base cases
    if (N==1 && K==0){
        return 0;
    }
    for (int k = 1; k <= K; ++k) {
        dp[k][0] = 0; // 0 floors needs 0 attempts
        dp[k][1] = 1; // 1 floor needs 1 attempt
    }
    for (int n = 1; n <= N; ++n) {
        dp[1][n] = n; // With 1 parachute, need to try all floors
    }

    // Fill DP table
    for (int k = 2; k <= K; ++k) {
        for (int n = 2; n <= N; ++n) {
            int low = 1, high = n, res = INT_MAX;
            while (low <= high) {
                int mid = (low + high) / 2;
                int broken = dp[k - 1][mid - 1];   // parachute breaks
                int survived = dp[k][n - mid];     // parachute survives
                int worst = 1 + max(broken, survived);
                res = min(res, worst);

                if (broken > survived)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            dp[k][n] = res;
        }
    }

    return dp[K][N];
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << minAttempts(N, K) << endl;
    return 0;
}

