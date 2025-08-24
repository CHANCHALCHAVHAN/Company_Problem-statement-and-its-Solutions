/*
PROBLEM STATEMENT
Problem Statement
A smart home contains N rooms, each with a device that requires internet connectivity. The home has a single router, which can only be connected to one room at a time.

The router features a smart-switching system that allows it to change its connection from one room to another. However, only a limited number of such switches can be made in a single day.

You are given:

An array devices[] of size N, where devices[i] represents the internet demand of the device in room i (1 ≤ devices[i] ≤ 10⁴).

A matrix switchCost[][] of size N × N, where switchCost[i][j] is the cost of switching from room i to room j.

An integer K, representing the maximum number of switches allowed in a day (not counting the initial connection).

The router always starts in room 0. You can make at most K switches after that (i.e., visit at most K+1 rooms in total).

Your task is to determine the maximum total internet demand that can be collected from the sequence of visited rooms.

Note: The switchCost values are provided for reference but do not reduce or affect the total demand — they are purely informational. The only limitation is the number of switches (K).

Input Format
First line: Two integers N and K

Second line: N numbers — internet demand of each room.

Next N lines: Each line has N numbers — cost to switch from one room to another.

Output Format
Print the maximum total internet demand you can get with at most K switches.

Constraints
1 ≤ N ≤ 15

0 ≤ k < N-1

1 ≤ devices[i] ≤ 10^4

0 ≤ switchCost[i][j] ≤ 10^4

Sample Testcase 0
Testcase Input
4 2
30 50 70 10
0 5 15 10
5 0 20 25
15 20 0 30
10 25 30 0
Testcase Output
150
Explanation
Start at room 0 (demand 30).


Switch to room 2 (demand 70), cost 15.


Switch to room 1 (demand 50), cost 20.


Switch count = 2 (max allowed).


Total demand = 30 + 70 + 50 = 150.


This is the highest possible sum with 2 switches.

Sample Testcase 1
Testcase Input
3 1
10 20 30
0 10 100
10 0 10
100 10 0
Testcase Output
40
Explanation
Start at room 0 (demand 10).


Only 1 switch allowed.


Switch to room 2 (demand 30), cost 100.


Despite high cost, cost doesn't reduce demand; it only limits switching.


Total demand = 10 + 30 = 40.


Switching to room 1 instead gives total demand 30, less optimal.


Staying at room 0 alone gives 10, so switching to room 2 maximizes demand.

Companies
Topics
Dynamic Programming
Graph
DFS
Memoization
Optimization
Backtracking
Bitmask
Graph

*/
//CODE

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, K;
vector<int> devices;
vector<vector<int>> switchCost;
unordered_map<string, int> memo;

int dfs(int room, int switchesLeft, int visitedMask) {
    string key = to_string(room) + "_" + to_string(switchesLeft) + "_" + to_string(visitedMask);
    if (memo.count(key)) return memo[key];

    int maxDemand = 0;

    for (int next = 0; next < N; ++next) {
        if ((visitedMask & (1 << next)) == 0 && switchesLeft > 0) {
            int newMask = visitedMask | (1 << next);
            int demand = devices[next] + dfs(next, switchesLeft - 1, newMask);
            maxDemand = max(maxDemand, demand);
        }
    }

    return memo[key] = maxDemand;
}

int main() {
    cin >> N >> K;
    devices.resize(N);
    switchCost.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        cin >> devices[i];
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> switchCost[i][j]; // Not used in calculation

    int startMask = 1 << 0; // Room 0 visited
    int result = devices[0] + dfs(0, K, startMask);
    cout << result << endl;

    return 0;
}
