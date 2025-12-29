/*
Problem Statement
You are an adventurous climber planning to ascend a mountain that consists of N distinct checkpoints arranged in a line from the base (checkpoint 1) to the summit (checkpoint N).

Each checkpoint i has an altitude h[i] meters above sea level.

You want to climb from checkpoint 1 to checkpoint N, but you want to minimize the total effort spent.

The effort to move from checkpoint i to checkpoint j (j > i) is defined as:

The effort equals the absolute altitude difference between checkpoints i and j, multiplied by the number of checkpoints you skip in between plus one. Formally:
effort = |h[j] - h[i]| * (j - i)

You can move forward by skipping any number of checkpoints (i.e., jump directly from checkpoint i to checkpoint j with j > i), but you want to find a path from 1 to N with minimal total effort, where the total effort is the sum of effort for all jumps in your chosen path.

Input Format
First line contains an integer N

Second line contains N space-separated integers h[i]

Output Format
Print the minimal total effort required to reach checkpoint N starting from checkpoint 1.

Constraints
2 ≤ N ≤ 10^4

1 ≤ h[i] ≤ 10^9

Sample Testcase 0
Testcase Input
4
100 200 150 250
Testcase Output
200
Explanation
Checkpoints: [100, 200, 150, 250]
- Checkpoint 1: 100
- Checkpoint 2: 200
- Checkpoint 3: 150
- Checkpoint 4: 250


Optimal path: Checkpoint 1 -> Checkpoint 2 -> Checkpoint 4


1. Jump from Checkpoint 1 to 2:
   Effort = |height[2] - height[1]| * (step_distance)
   Effort = |200 - 100| * (2 - 1)
   Effort = 100 * 1 = 100


2. Jump from Checkpoint 2 to 4:
   Effort = |height[4] - height[2]| * (step_distance)
   Effort = |250 - 200| * (4 - 2)
   Effort = 50 * 2 = 100


Total effort = 100 + 100 = 200

Sample Testcase 1
Testcase Input
3
50 80 90
Testcase Output
40
Explanation
Checkpoints: [50, 80, 90]


We compare two possible strategies:


Strategy A: Jump directly from 1 to 3
   Effort = |90 - 50| * (3 - 1)
   Effort = 40 * 2 = 80


Strategy B: Step-by-step (1 -> 2 -> 3)
   Step 1 (1 -> 2):
     Effort = |80 - 50| * (2 - 1) = 30 * 1 = 30
   Step 2 (2 -> 3):
     Effort = |90 - 80| * (3 - 2) = 10 * 1 = 10
   Total Strategy B Effort = 30 + 10 = 40


Since 40 < 80, the minimal effort is 40.

Companies
Topics
Dynamic Programming
Greedy
Array
minimum cost flow
Math
Data Structure
Dynamic Programming
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> h(N + 1);
    for (int i = 1; i <= N; i++) cin >> h[i];

    const long long INF = LLONG_MAX / 2;
    vector<long long> dp(N + 1, INF);
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            long long cost = abs(h[i] - h[j]) * (i - j);
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }

    cout << dp[N];
    return 0;
}
