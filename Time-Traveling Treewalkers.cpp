/*
Problem Statement
You are given a rooted tree with N nodes (1 to N) and N-1 undirected edges. The root of the tree is node 1. 

Each node i has a specific time portal value T[i].
There is a global teleport constraint K.
A Treewalker starts at the root node (node 1). The walker can perform the following moves:

Walk: Move from the current node to any direct child. This takes 1 unit of time.
Teleport: At any node u, the walker can activate a time portal to return to its direct parent v. This teleportation takes 0 units of time, but is only allowed if |T[u] - T[v]| ≤ K. If this condition is not met, the walker must physically walk back to the parent, taking 1 unit of time.
Your task is to compute the minimum total time required to visit every node in the tree at least once and return to the root node.

Input Format
The first line contains two integers N and K, representing the number of nodes and the teleport constraint.

The second line contains N space-separated integers, where the i-th integer represents T[i] (the time portal value of node i).

The next N-1 lines each contain two integers u and v, representing an undirected edge between node u and node v.

Output Format
Print a single integer representing the minimum total time to visit all nodes and return to the root.

Constraints
1 ≤ N ≤ 10^3

0 ≤ T[i] ≤ 10^3

0 ≤ K ≤ 10^3

Sample Testcase 0
Testcase Input
4 1
1 2 3 4
1 2
2 3
3 4
Testcase Output
3
Explanation
Timestamps
Node:           1  2  3  4  
Timestamp:  1  2  3  4

Tree

1(1)
 |
2(2)
 |
3(3)
 |
4(4)



Steps and Explanation


1 → 2 → 3 → 4: +3 steps


Try to teleport:


4 → 3: |4-3| = 1 


3 → 2: |3-2| = 1 


2 → 1: |2-1| = 1 


Total Cost: 1 + 1 + 1 = 3

Sample Testcase 1
Testcase Input
6 3
10 12 13 9 15 16
1 2
1 3
2 4
2 5
3 6
Testcase Output
5
Explanation
Timestamps
Node:          1   2   3   4   5   6  
Timestamp: 10 12 13  9 15 16

Tree

        1(10)
       /     \
     2(12)   3(13)
    /    \      \
 4(9)   5(15)   6(16)



Steps and Explanation


1 → 2 → 4: +1 +1


Teleport 4 → 2: |9-12| = 3 


2 → 5: +1


Teleport 5 → 2: |15-12| = 3 


Teleport 2 → 1: |12-10| = 2 


1 → 3 → 6: +1 +1


Teleport 6 → 3: |16-13| = 3 


Teleport 3 → 1: |13-10| = 3 


Total Cost: 1+1+1+1+1 = 5






Companies
Topics
Dynamic Programming
Greedy
Graph Traversal- DFS
Backtracking
Simulation
Tree
Breadth-First Search
Depth-First Search
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> T(N + 1);
    for(int i = 1; i <= N; i++) cin >> T[i];

    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(N + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    int teleportEdges = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);

                if(abs(T[u] - T[v]) <= K)
                    teleportEdges++;
            }
        }
    }

    int result = 2 * (N - 1) - teleportEdges;
    cout << result;
    return 0;
}
