/*
Problem Statement
In a city, there are N towers arranged in a straight line. Each tower has a certain height. You are allowed to process the towers in order, considering each pair of adjacent towers.

There is a threshold value K, and you can perform the following two types of operations:

Link Operation (Forced Merge): You must merge two adjacent towers (i and i+1) if the GCD of their heights is greater than K, unless you choose to skip this merge using a "skip operation" (see below).
When you merge them, they become one tower with a new height equal to the sum of their original heights.

After merging, this pair is treated as a single tower in future operations.

Skip Operation (Limited Usage): You can skip a merge, even if the GCD is greater than K — but only M times in total across the entire process.

Choose a sequence of merge and skip operations such that:

You follow the rules above.

You end up with the maximum possible number of towers remaining after processing all pairs.

Input Format
The first line contains three integers: N, K, and M

The second line contains N integers — H[0], H[1], ..., H[N-1]

Output Format
Print the maximum number of towers that can remain after performing the operations optimally.

Constraints
2 ≤ N ≤ 10^5

1 ≤ K ≤ 10^4

0 ≤ M ≤ N-2

1 ≤ H[i] ≤ 10^5

Sample Testcase 0
Testcase Input
4 10 2
20 30 40 50
Testcase Output
4
Explanation
Tower heights: 20, 30, 40, 50


k = 10, m = 2 (allowed skips)


Process:


20 and 30 → GCD(20,30) = 10 (allowed, no forced merge)


30 and 40 → GCD(30,40) = 10 (allowed, no forced merge)


40 and 50 → GCD(40,50) = 10 (allowed, no forced merge)


Since every GCD is ≤ k, no merges needed, no skips used.

Answer: 4

Sample Testcase 1
Testcase Input
4 2 0
6 9 10 15
Testcase Output
1
Explanation
We are allowed 0 skips, so every adjacent pair with GCD > 2 must be merged.
GCD(6, 9) = 3 → Greater than K → Must merge (no skip available)
New tower height: 6 + 9 = 15


Array becomes: [15, 10, 15]
Now check GCD(15, 10) = 5 → Greater than K → Must merge
New tower height: 15 + 10 = 25


Array becomes: [25, 15]
Now check GCD(25, 15) = 5 → Greater than K → Must merge
New tower height: 25 + 15 = 40


Array becomes: [40]

Companies
Topics
GCD
Greedy
array manipulation
Optimization
Simulation
Mathematics, Algorithms
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, M;
    cin >> N >> K >> M;

    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<long long> st;
    int skipsUsed = 0;

    for (int i = 0; i < N; i++) {
        long long curr = H[i];

        while (!st.empty()) {
            long long g = __gcd(st.back(), curr);

            if (g > K) {
                if (skipsUsed < M) {
                    // Strategic skip to avoid merge
                    skipsUsed++;
                    break;
                } else {
                    // Forced merge
                    curr += st.back();
                    st.pop_back();
                }
            } else {
                break;
            }
        }

        st.push_back(curr);
    }

    cout << st.size() << "\n";
    return 0;
}
