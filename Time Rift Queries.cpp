/*
Problem Statement
In a faraway dimension, a wizard maintains a timeline of arrays, where each version of the array results from updating an earlier version. Every update either inserts or changes the value at a specific position in the array. Due to his magical powers, the wizard can query across different points in the timeline.

You are given an initial array A of size N. The array evolves over time via M versioned updates. Each update produces a new version of the array by changing one index to a new value.

Later, the wizard wants to perform Q queries. Each query is of the form:

Given a version V, a range [L, R], and a number K, 
find the K-th smallest number in that subarray of version V.

Your task is to efficiently process all updates and answer the K-th order statistics queries on historical versions of the array.

Input Format
The first line contains two integers N and M.

The second line conaains N integers A[1..N] (initial array)

Next M lines: Each line has three integers:
    pos val baseVersion
    => update A[pos] = val, creating a new version from baseVersion

Next line: Integer Q
Next Q lines: Each line has four integers:
    V L R K => Query the K-th smallest element in A[L..R] of version V

Output Format
For each query, print the answer on a new line.

Constraints
1 ≤ N ≤ 10^3

1 ≤ M ≤ 10^3

1 ≤ Q ≤ 10⁵

1 ≤ A[i], val ≤ 10⁹

1 ≤ pos ≤ N

0 ≤ baseVersion < (M+1)

1 ≤ V ≤ (M+1)

1 ≤ L ≤ R ≤ N

1 ≤ K ≤ (R − L + 1)

Version 0 refers to the original array. Every update creates a new version.

Sample Testcase 0
Testcase Input
6 2
4 1 6 3 9 2
2 5 0
6 0 1
3
0 1 6 3
1 1 4 2
2 3 6 4
Testcase Output
3
4
9
Explanation
Version 0: Original array [4,1,6,3,9,2]
Query: 3rd smallest between index 1 and 6 → sorted [1,2,3,4,6,9] → answer is 3.


Version 1: Update index 2 to 5 → [4,5,6,3,9,2]
Query: 2nd smallest between index 1 and 4 → sorted [3,4,5,6] → answer is 4.


Version 2: Update index 6 to 0 → [4,5,6,3,9,0]
Query: 4th smallest between index 3 and 6 → sorted [0,3,6,9] → answer is 6.

Sample Testcase 1
Testcase Input
5 3
1 5 2 4 3
3 6 0
2 7 1
4 1 2
2
3 1 5 3
1 2 4 2
Testcase Output
3
5
Explanation
Version 0: [1, 5, 2, 4, 3]
Version 1: Modify index 3 to 6 → [1, 5, 6, 4, 3]
Version 2: Modify index 2 to 7 → [1, 7, 6, 4, 3]
Version 3: Modify index 4 to 1 → [1, 7, 6, 1, 3]


Now,
Query 1 (V = 3, L = 1, R = 5, K = 3):
Array = [1, 7, 6, 1, 3] → Sorted = [1, 1, 3, 6, 7] → 3rd smallest = 3


Query 2 (V = 1, L = 2, R = 4, K = 2):
Array = [5, 6, 4] → Sorted = [4, 5, 6] → 2nd smallest = 5

Companies
Juspay
Goldman Sachs
Salesforce
Topics
Persistent Segment Tree
K-th Order Statistics
Version Control in Data Structures
Range Query
Tree
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    struct Update { int pos, val, base; };
    vector<Update> upd(M);
    for (int i = 0; i < M; ++i) {
        cin >> upd[i].pos >> upd[i].val >> upd[i].base;
        upd[i].pos--; // convert to 0-based
    }

    // Build all versions
    vector<vector<int>> versions(M + 1, vector<int>(N));
    versions[0] = A;
    for (int i = 1; i <= M; ++i) {
        // Create version i from its baseVersion
        versions[i] = versions[upd[i - 1].base];
        versions[i][upd[i - 1].pos] = upd[i - 1].val;
    }

    int Q; 
    cin >> Q;
    while (Q--) {
        int V, L, R, K;
        cin >> V >> L >> R >> K;
        --L; --R; // convert to 0-based

        // Extract subarray [L..R] from version V
        vector<int> sub;
        sub.reserve(R - L + 1);
        for (int i = L; i <= R; ++i) sub.push_back(versions[V][i]);

        // Find K-th smallest (1-based K)
        nth_element(sub.begin(), sub.begin() + (K - 1), sub.end());
        cout << sub[K - 1] << '\n';
    }
    return 0;
}
