/*
Problem Statement
A monkey lives on an island filled with magical stones arranged in a straight line. Each stone has a magical weight, which can be positive or negative. The monkey starts on stone 0 and wants to reach the last stone (stone N-1).

The monkey can jump from its current stone to any forward stone within a maximum distance of K.

However, there is a magical rule: The total sum of the weights of all stones visited along the path (including the starting stone and the final stone) must be exactly 0.

Write a program to determine if there exists a valid path from the first stone to the last stone such that:

The monkey only moves forward.
Each jump is at most K stones apart.
The sum of weights of all visited stones is exactly 0.
Return "YES" if such a path exists, otherwise return "NO".

Input Format
The first line contains two space-separated integers N and K.

The second line contains N space-separated integers: W[0], W[1], ..., W[N-1] — representing the magical weight of each stone.

Output Format
Print "YES" if the monkey can reach the last stone with a total path weight of exactly 0. Otherwise, print "NO".

Constraints
2 ≤ N ≤ 300

1 ≤ K ≤ 50

-100 ≤ W[i] ≤ 100

Sample Testcase 0
Testcase Input
5 2
2 -3 1 2 -2
Testcase Output
YES
Explanation
Start at stone 0 (weight = 2).


Jump 1 stone to stone 1 (weight = -3). Current Sum: 2 + (-3) = -1.


Jump 1 stone to stone 2 (weight = 1). Current Sum: -1 + 1 = 0.


Jump 1 stone to stone 3 (weight = 2). Current Sum: 0 + 2 = 2.


Jump 1 stone to stone 4 (weight = -2). Final Sum: 2 + (-2) = 0.


Path: 0 -> 1 -> 2 -> 3 -> 4. All jumps are <= K (2). Total sum is 0.


Output: YES

Sample Testcase 1
Testcase Input
4 1
1 2 3 4
Testcase Output
NO
Explanation
K = 1, so the monkey must visit every stone in order: 0 -> 1 -> 2 -> 3.


Weights: 1 + 2 + 3 + 4 = 10.


The total sum is 10, which is not 0.


No other path is possible.


Output: NO

Companies
Topics
Graph
BFS
Dynamic Programming
Memoization
Path Finding
Backtracking
Array
Graph Algorithm,Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> W(N);
    for(int &x : W) cin >> x;

    // reachable[i] = all possible sums when reaching stone i
    vector<unordered_set<int>> reachable(N);
    reachable[0].insert(W[0]);

    for(int i = 0; i < N; i++) {
        for(int sum : reachable[i]) {
            for(int j = i + 1; j <= min(N - 1, i + K); j++) {
                reachable[j].insert(sum + W[j]);
            }
        }
    }

    if(reachable[N-1].count(0))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
