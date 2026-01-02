/*
Problem Statement
You are part of an expedition team exploring an ancient underground network of caves. The caves are structured as a graph, where each node represents a cave, and each edge between two caves represents a tunnel.

Your task is to find the maximum possible number of valuable artifacts you can collect by traversing the cave network.

Rules of the Expedition:

Start & End: You start at the entrance cave (labeled 0) and must reach the exit cave (labeled N-1).
Movement: You move through tunnels connecting the caves.
Step Limit: You can take at most K steps (traverse at most K tunnels).
Artifacts & Traps:
Some caves contain artifacts, represented by a positive integer (value adds to your total).
Some caves contain traps, represented by a negative integer (value subtracts from your total).
The value of the starting cave (Cave 0) is included in your total.
Revisiting: You are allowed to revisit caves or re-traverse tunnels, provided you do not exceed the K step limit.
Goal: Determine the maximum total value of artifacts you can collect on a valid route from Cave 0 to Cave N-1 taking no more than K steps. If it is impossible to reach Cave N-1 within K steps, return -1.

Input Format
The first line contains three integers N, M, and K:
  - N: Number of caves.
  - M: Number of tunnels.
  - K: Maximum allowed steps.

The second line contains N integers, where the i-th integer represents the value of cave i.

The next M lines each contain two integers u and v, representing a bidirectional tunnel between cave u and cave v.

Output Format
Print a single integer: the maximum total value collectible upon reaching the exit (Cave N-1) within K steps. If the exit is unreachable within K steps, print -1.

Constraints
1 ≤ N ≤ 10^3

0 ≤ M ≤ 10^4

-10^3 ≤ cave[i] ≤ 10^3 (positive integers represent artifacts and negative integers represent traps)

0 ≤ K ≤ N-1

The number of edges can be large, and the graph may have cycles.

Sample Testcase 0
Testcase Input
4 4 2
10 -5 8 -3
0 1
1 2
2 3
0 3
Testcase Output
7
Explanation
N = 4, M = 4, K = 2


Artifact values = [10, -5, 8, -3]


Graph:
0  -  1  -  2  - 3
 \_________/



Start: 0, Target: 3, Max steps: 2


Valid Paths:


0 → 3 = 10 - 3 = 7 (best and only within 2 steps)


0 → 1 → 2 → 3 = 4 steps →  invalid





Sample Testcase 1
Testcase Input
5 6 3
5 -1 2 3 -2
0 1
0 2
1 3
2 3
2 4
3 4
Testcase Output
8
Explanation
N = 5 caves, M = 6 tunnels, K = 3 max steps


Artifact values = [5, -1, 2, 3, -2]


Graph:
0 - 1
|   |
2 - 3
 \ /
  4



We start from cave 0 and want to reach cave 4 in at most 3 steps.


Valid Paths from 0 to 4:


0 → 1 → 3 → 4 = 5 - 1 + 3 - 2 = 5


0 → 2 → 4 = 5 + 2 - 2 = 5


0 → 2 → 3 → 4 = 5 + 2 + 3 - 2 = 8 (best)

Companies
Topics
Path Finding
Backtracking
Dynamic Programming
Graph
Depth-First Search
Breadth-First Search
*/
#include <bits/stdc++.h>
using namespace std;

const int NEG_INF = -1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> value(N);
    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dp[steps][node] = max value
    vector<vector<int>> dp(K + 1, vector<int>(N, NEG_INF));

    // Start at cave 0
    dp[0][0] = value[0];

    for (int step = 1; step <= K; step++) {
        for (int u = 0; u < N; u++) {
            if (dp[step - 1][u] == NEG_INF) continue;

            for (int v : adj[u]) {
                dp[step][v] = max(dp[step][v],
                                  dp[step - 1][u] + value[v]);
            }
        }
    }

    int answer = NEG_INF;
    for (int step = 0; step <= K; step++) {
        answer = max(answer, dp[step][N - 1]);
    }

    cout << (answer == NEG_INF ? -1 : answer) << "\n";
    return 0;
}
