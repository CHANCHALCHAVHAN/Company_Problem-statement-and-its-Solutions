/*
Problem Statement
There are N cities where Alice’s city is 1 and Bob’s city is N. There are M bi-directional roads between any two cities having a certain length. As Alice and Bob are childhood friends they want to meet  again in a city such that the 

The absolute difference between the distance traveled by Alice and the distance traveled by Bob is as minimal as possible.

Write a program to determine the minimum absolute difference between the distance traveled by Alice and the distance traveled by Bob. If they can’t meet then report -1.

Input Format
The first line of input will be two integers “N” and “M” denoting the number of cities and the number of paths.

The next M lines of input will be 3 integers a,b, c denoting a bi-directional road between a and b of length c.

Output Format
print a single integer denoting the minimum absolute difference between the distance traveled by Alice and the distance traveled by Bob. If they can’t meet then print -1.

Constraints
2<= N , M <= 10^3

1<= a,b<= N;

1<= c <= 10^5

Sample Testcase 0
Testcase Input
7 8
1 2 2
2 5 3
1 4 7
1 3 4
3 6 5
5 7 4
7 6 2
4 7 3
Testcase Output
1
Explanation
If they meet at node 5 then the distance traveled by Alice is 5 and distance traveled by Bob is 4 and the absolute difference is 1. It is the minimum absolute difference.




Sample Testcase 1
Testcase Input
4 4
1 2 5
4 2 7
3 1 11
4 3 9
Testcase Output
2
Explanation
They can meet either at city 2 or city 3 . For both the case the absolute difference of distances will be 2.

Companies
Meesho
Amazon
PwC
Topics
Minimum Spanning Tree
Graph
Data Structure
Graph

*/



#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int start, int N, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> distAlice = dijkstra(1, N, adj);
    vector<int> distBob = dijkstra(N, N, adj);

    int minDiff = INF;
    for (int i = 1; i <= N; ++i) {
        if (distAlice[i] != INF && distBob[i] != INF) {
            minDiff = min(minDiff, abs(distAlice[i] - distBob[i]));
        }
    }

    cout << (minDiff == INF ? -1 : minDiff) << endl;
    return 0;
}
