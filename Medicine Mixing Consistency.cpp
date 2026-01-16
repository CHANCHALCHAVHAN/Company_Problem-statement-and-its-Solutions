/*
Problem Statement
In a high-tech medicine factory, there are N large mixing containers arranged in a line. Each container has a temperature value indicating how hot the medicine is while mixing. To maintain chemical stability, the difference in temperature between any two adjacent containers should not exceed K degrees after adjustments.

The factory has a machine that can reduce the temperature of any container by any amount (but not increase it) to maintain consistency. Each degree reduced in temperature costs 1 energy unit.

You are given an array T[0..N-1], where T[i] is the temperature of the i-th container. Your task is to adjust the temperatures such that the absolute difference between adjacent containers is at most K and the total energy cost is minimized.

Input Format
First line contains two integers N and K.

Second line: N integers T[0], T[1], ..., T[N-1].

Output Format
Print the minimum total energy cost to adjust the temperatures so that the difference between any two adjacent containers is at most K.

Constraints
2 ≤ N ≤ 10^5

0 ≤ T[i] ≤ 10^5 for all 0 ≤ i < N

 

Sample Testcase 0
Testcase Input
4 5
12 14 11 9
Testcase Output
0
Explanation
4 5
12 14 11 9


All temperature differences are:


|12 - 14| = 2


|14 - 11| = 3


|11 - 9| = 2
All ≤ 5, and no temperature exceeds limit — no adjustment needed.


Total cost = 0

Sample Testcase 1
Testcase Input
5 3
10 15 20 13 25
Testcase Output
15
Explanation
5 3
10 15 20 13 25

we can adjust:


T[1] from 15 → 13 (cost 2)


T[2] from 20 → 16 (cost 4)


T[4] from 25 → 16 (cost 9)
All others remain the same.


Adjusted temps: [10, 13, 16, 13, 16]
All adjacent differences ≤ 3
Total cost = 2 + 4 + 9 = 15

Companies
Topics
Greedy
Array
Dynamic Programming
Minimization Problem
Two Pointers
Sliding Window
Greedy Algorithms
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    long long cost = 0;

    // feasible interval for first container
    int low = 0, high = T[0];
    int prev = high;  // choose max feasible (minimize reduction)

    for (int i = 1; i < N; i++) {
        // feasible range for current container
        int new_low = max(0, prev - K);
        int new_high = min(T[i], prev + K);

        // pick the maximum feasible value
        int adjusted = new_high;

        cost += (T[i] - adjusted);
        prev = adjusted;
    }

    cout << cost << "\n";
    return 0;
}
