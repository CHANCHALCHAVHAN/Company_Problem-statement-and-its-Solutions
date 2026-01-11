/*
Problem Statement
You are the Chief Logistics Officer for the Galactic Trade Federation, responsible for loading a sequence of cargo containers onto a fleet of starships at a spaceport.

You are given an integer array weights, where weights[i] represents the weight of the i-th cargo container in the order it arrived.

You must load these containers according to the following rules:

Containers must be loaded in the exact order they arrived. You may only form contiguous groups of containers.
You have exactly k starships available.
All k starships must be used, and each starship must carry at least one container.
The fuel cost of a starship is determined by the heaviest container it carries. That is, the cost of a group of containers is the maximum weight in that group.
Your task is to partition the array weights into exactly k non-empty contiguous subarrays such that the total fuel cost (the sum of the maximum weight in each subarray) is minimized.

Return the minimum possible total fuel cost. If it is not possible to partition the containers into exactly k non-empty contiguous subarrays, return -1.

Input Format
The first line contains an integer n, representing the number of cargo containers.

The second line contains n space-separated integers, where the i-th integer represents the weight of the i-th container.

The third line contains an integer k, representing the number of available starships.

Output Format
Print a single integer representing the minimum total fuel consumption.

Constraints
1 <= weights.length <= 3 * 10^2

0 <= weights[i] <= 10 * 3

1 <= k <= 10

Sample Testcase 0
Testcase Input
5
7 2 5 10 8
2
Testcase Output
17
Explanation
We need to split the containers into 2 ships.
The optimal split is at index 2 (between 5 and 10):
- Ship 1 takes [7, 2, 5]. Max weight = 7.
- Ship 2 takes [10, 8]. Max weight = 10.
- Total Fuel = 7 + 10 = 17.

Sample Testcase 1
Testcase Input
6
6 5 4 3 2 1
2
Testcase Output
7
Explanation
We need to split the containers into 2 ships.
Option A: Ship 1 takes [6], Ship 2 takes [5, 4, 3, 2, 1].
- Cost Ship 1: max(6) = 6
- Cost Ship 2: max(5, 4, 3, 2, 1) = 5
- Total: 6 + 5 = 11.


Option B: Ship 1 takes [6, 5, 4, 3, 2], Ship 2 takes [1].
- Cost Ship 1: max(6, 5, 4, 3, 2) = 6
- Cost Ship 2: max(1) = 1
- Total: 6 + 1 = 7.


Since 7 is the lowest possible total, the answer is 7.

Companies
Topics
Dynamic Programming
Array
Arrays
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int k;
    cin >> k;

    // Impossible case
    if (k > n) {
        cout << -1 << endl;
        return 0;
    }

    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int currentMax = 0;

            // Try all possible splits
            for (int t = i - 1; t >= 0; t--) {
                currentMax = max(currentMax, weights[t]);
                dp[i][j] = min(dp[i][j], dp[t][j - 1] + currentMax);
            }
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}
