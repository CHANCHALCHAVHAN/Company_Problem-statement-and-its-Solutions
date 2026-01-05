/*
Problem Statement
In a Quantum Factory, a series of N machines are connected in a directed network. Each machine performs a quantum operation and has an associated internal value. These operations can scale down the energy before passing it on to the next connected machine. The goal is to compute the maximum energy that can be transferred from the starting machine (machine 1) to the ending machine (machine N), while applying the scaling effects defined by each machine.

The factory consists of N machines (nodes), numbered from 1 to N.

Each machine i has:

A value V[i] (quantum operation intensity)

A scaling factor multiplier K[i]

The factory starts with an initial energy of E at machine 1.

Each machine applies a scaling factor to the incoming energy before passing it to the next machine(s). The scaling factor for machine i is calculated as:

scale[i] = 1 - ((K[i] * V[i]) % 100) / 100
This ensures that some energy is lost (or retained) based on the machine's quantum behavior.

If there's a directed edge from machine u to machine v, the energy transferred to v is:

energy[v] = energy[u] * scale[u]
There is no transmission cost for edges—only scaling at the nodes affects energy.

Your task is to compute the maximum energy that can reach machine N starting from machine 1, by following any valid path and applying the scaling rule at each machine.

Input Format
First line contains two integers N and M — the number of machines (nodes) and connections (edges), respectively.

Second line contains N space-separated integers — the values V[1], V[2], ..., V[N] for each machine.

Third line contains N space-separated integers — the K[1], K[2], ..., K[N] values used for energy scaling.

Fourth line contains a single integer E — the initial energy at machine 1.

Next M lines: Each line contains two integers u and v — representing a directed connection from machine u to machine v.

Output Format
Print a single floating-point number representing the maximum energy that can reach the final machine (N) from the starting machine (1), up to 6 decimal places.

Constraints
1 ≤ N ≤ 500

1 ≤ M ≤ 1000

1 ≤ E ≤ 10^8

1 ≤ u, v ≤ N

1 ≤ V[i] ≤ 10^4

1 ≤ K[i] ≤ 100

Sample Testcase 0
Testcase Input
3 2
50 60 70
1 2 3
500
1 2
2 3
Testcase Output
200.000000
Explanation
N = 3 machines, M = 2 edges
Node values = [50, 60, 70]
K values = [1, 2, 3]
Initial energy at machine 1 = 500


Let's calculate the scaling factors:
For machine 1: scale[1] = 1 - (1 * 50 % 100) / 100 = 0.5
For machine 2: scale[2] = 1 - (2 * 60 % 100) / 100 = 0.8
For machine 3: scale[3] = 1 - (3 * 70 % 100) / 100 = -0.9


After calculating the energy flow at each machines considering the scaling factor, the maximum amount of energy reaching to machine 3 is 200.000000 via path 1 -> 2 -> 3.

Sample Testcase 1
Testcase Input
4 5
10 20 30 40
2 3 4 5
1000
1 2
1 3
2 3
2 4
3 4
Testcase Output
640.000000
Explanation
N = 3 machines, M = 2 edges
Node values = [50, 60, 70]
K values = [1, 2, 3]
Initial energy at machine 1 = 500


Let's calculate the scaling factors:
For machine 1: scale[1] = 1 - (2 * 10 % 100) / 100 = 0.8
For machine 2: scale[2] = 1 - (3 * 20 % 100) / 100 = 0.4
For machine 3: scale[3] = 1 - (4 * 30 % 100) / 100 = 0.8
For machine 4: scale[4] = 1 - (5 * 40 % 100) / 100 = 1.0


After calculating the energy flow at each machines considering the scaling factor, the maximum amount of energy reaching to machine 4 is 6400.000000 via path 1 -> 3 -> 4.

Companies
Meesho
Adobe
Goldman Sachs
Juspay
Topics
Graph
DFS
BFS
Algorithms, Implementation
Data Structure
Graph Theory
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> V(N + 1), K(N + 1);
    for (int i = 1; i <= N; i++) cin >> V[i];
    for (int i = 1; i <= N; i++) cin >> K[i];

    double E;
    cin >> E;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Compute scaling factors
    vector<double> scale(N + 1);
    for (int i = 1; i <= N; i++) {
        scale[i] = 1.0 - ((K[i] * V[i]) % 100) / 100.0;
    }

    // Max energy reachable at each node
    vector<double> bestEnergy(N + 1, -1.0);
    bestEnergy[1] = E;

    // Max-heap: {energy, node}
    priority_queue<pair<double, int>> pq;
    pq.push({E, 1});

    while (!pq.empty()) {
        auto [currEnergy, u] = pq.top();
        pq.pop();

        if (currEnergy < bestEnergy[u]) continue;

        for (int v : adj[u]) {
            double nextEnergy = currEnergy * scale[u];
            if (nextEnergy > bestEnergy[v]) {
                bestEnergy[v] = nextEnergy;
                pq.push({nextEnergy, v});
            }
        }
    }

    cout << fixed << setprecision(6) << max(0.0, bestEnergy[N]) << "\n";
    return 0;
}
