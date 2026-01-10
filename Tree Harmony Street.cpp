/*
Problem Statement
In a newly developed smart city, an eco-friendly initiative mandates planting trees along a long street. The street is divided into N plot segments, each represented as an integer in an array P[].

Each plot can accommodate at most one tree. However, certain conditions must be followed to maximize ecological harmony:

A tree can only be planted in a

In a newly developed smart city, an eco-friendly initiative mandates planting trees along a long street. The street is divided into N plot segments, each represented as an integer in an array P[].

Each plot can accommodate at most one tree. However, certain conditions must be followed to maximize ecological harmony:

A tree can only be planted in a plot segment if:
1. The segment is empty (represented by 0 in array P[]).
2. None of its immediate neighbors (left or right) are occupied. A neighbor is considered occupied if it already has a tree (represented by 1) or is a mandatory tree zone (represented by 2).

You are given the initial configuration of the street in an array P[] of size N, where:
0 → empty plot
1 → already has a tree
2 → mandatory tree zone

You need to return the maximum number of additional trees that can be planted on the street following the above rules without disturbing existing or mandatory trees.

plot segment if:

The segment is empty (represented by 0 in array P[]).

None of its immediate neighbors (left or right) already have a tree (represented by 1).

There are also special zones (represented by 2) where trees must be planted no matter the neighboring conditions.

You are given the initial configuration of the street in an array P[] of size N, where:

0 → empty plot

1 → already has a tree

2 → mandatory tree zone

You need to return the maximum number of trees that can be planted on the street following the above rules without disturbing existing or mandatory trees.

Input Format
First line contains a single integer N.

Second line contains N space-separated integers representing the array P[].

Output Format
Print the maximum number of additional trees that can be planted while satisfying all constraints.

Constraints
1 ≤ N ≤ 10^5

0 ≤ P[i] ≤ 2

Sample Testcase 0
Testcase Input
7  
0 1 0 2 0 1 0
Testcase Output
0
Explanation
Array: [0, 1, 0, 2, 0, 1, 0]


We iterate through the array to find valid spots:
i = 0: Right is 1 → Can't plant.
i = 2: Left is 1 → Can't plant.
i = 4: Left is 2, Right is 1 → Can't plant.
i = 6: Left is 1 → Can't plant.

Sample Testcase 1
Testcase Input
10  
0 0 1 0 0 2 0 1 0 0
Testcase Output
2
Explanation
Initial Array: [0, 0, 1, 0, 0, 2, 0, 1, 0, 0]


i = 0: Value is 0. Left is boundary (ok), Right is 0 (ok).
       → PLANT TREE. Count = 1.
       Array effectively becomes: [1, 0, 1, 0, 0, 2, 0, 1, 0, 0]


i = 1: Value is 0. Left is now 1 (newly planted).
       → Can't plant.


i = 2: Value is 1 (existing tree). Skip.


i = 3: Value is 0. Left is 1 (existing tree).
       → Can't plant.


i = 4: Value is 0. Left is 0. Right is 2 (Mandatory Zone).
       → Can't plant. (Neighbors cannot be 1 or 2).


i = 5: Value is 2 (Mandatory Zone). Skip.


i = 6: Value is 0. Left is 2 (Mandatory Zone).
       → Can't plant.


i = 7: Value is 1 (existing tree). Skip.


i = 8: Value is 0. Left is 1 (existing tree).
       → Can't plant.


i = 9: Value is 0. Left is 0, Right is boundary (ok).
       → PLANT TREE. Count = 2.
       Array effectively becomes: [..., 1, 0, 1]


Total trees planted: 2

Companies
Topics
Greedy
Simulation
Array
Algorithms, Implementation
Data Structure
Greedy Algorithms
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        if (P[i] != 0) continue;

        bool left_ok = (i == 0) || (P[i - 1] == 0);
        bool right_ok = (i == N - 1) || (P[i + 1] == 0);

        if (left_ok && right_ok) {
            // Plant the tree
            P[i] = 1;
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}
