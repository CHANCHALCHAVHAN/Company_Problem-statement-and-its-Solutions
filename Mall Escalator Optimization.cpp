/*
Problem Statement
A newly opened mall has N floors (numbered from 0 to N-1) and each floor is connected to one or more other floors using escalators. Each escalator only goes one-way (either up or down), and takes exactly 1 minute to use.

The mall administration wants to minimize crowd congestion by ensuring that customers can reach every other floor from the ground floor (floor 0) in minimum time using escalators only.

You are given the list of escalators, each as a pair (u, v) denoting a one-way escalator from floor u to floor v.

Write a program to calculate the minimum number of minutes required to reach each floor from floor 0 using only escalators. If a floor is not reachable, return -1 for that floor.

Input Format
First line contains two integer N and M

Next M lines: Two integers u v — a directed escalator from floor u to floor v.

Output Format
Print a single line with N space-separated integers.

The i-th integer is the minimum minutes required to reach floor i from floor 0.

Constraints
1 ≤ N ≤ 10^3

0 ≤ M ≤ 2 * 10^4

0 ≤ u, v < N

Sample Testcase 0
Testcase Input
5 2
0 1
3 4
Testcase Output
0 1 -1 -1 -1
Explanation
0 → 1: reachable in 1 minute.


Floors 2, 3, 4 have no path from floor 0, so result is -1 for those.


Output: 0 1 -1 -1 -1

Sample Testcase 1
Testcase Input
6 7
0 1
0 2
1 3
2 3
3 4
4 5
2 5
Testcase Output
0 1 1 2 3 2
Explanation
From floor 0, both 1 and 2 can be reached in 1 minute.


3 can be reached via 1 → 3 or 2 → 3 in 2 minutes.


4 via 3 → 4 = 3 minutes.


5 can be reached directly via 2 → 5 in 2 minutes (better than 0 → 1 → 3 → 4 → 5 which takes 4 mins).


Output: 0 1 1 2 3 2

Companies
Topics
Graph
BFS
Shortest Path
Simulation
Data Structure
Graph Theory


*/

#include <iostream>
#include <vector>
#include <queue>

void calculate_minimum_minutes(int N, int M, std::vector<std::pair<int, int>> &escalators, std::vector<int> &result) {
    // Build adjacency list
    std::vector<std::vector<int>> adj(N);
    for (auto &e : escalators) {
        adj[e.first].push_back(e.second);
    }

    // Initialize result with -1
    result.assign(N, -1);
    result[0] = 0; // ground floor

    // BFS
    std::queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (result[v] == -1) { // not visited
                result[v] = result[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> escalators(M);
    for (int i = 0; i < M; i++) {
        std::cin >> escalators[i].first >> escalators[i].second;
    }
    std::vector<int> result(N);
    calculate_minimum_minutes(N, M, escalators, result);
    for (int i = 0; i < N; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
