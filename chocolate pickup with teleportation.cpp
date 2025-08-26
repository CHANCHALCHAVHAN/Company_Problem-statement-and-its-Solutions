/*
Problem Statement
You are given an N × M matrix grid, where grid[i][j] represents the number of chocolates available at position (i, j). You have two robots collecting chocolates, starting from:

Robot #1 at top-left corner (0, 0).

Robot #2 at top-right corner (0, M - 1).

Both robots move down simultaneously while following the rules:

From (i, j), a robot can move to (i+1, j-1), (i+1, j), or (i+1, j+1).

If both robots land on the same cell, only one collects chocolates.

Teleportation Portals: Some cells contain portals, marked as -1. If a robot lands on a portal, it is instantly teleported to a random cell in the next row. (Teleportation happens before collecting chocolates.)

The robots must reach the bottom row.

Maximize the total chocolates collected.

Input Format
The first line contains two integers N and M, the number of rows and columns in the grid.

The next n lines each contain m space-separated integers, representing the grid, where:

grid[i][j] is the number of chocolates at position (i, j).

A cell with -1 represents a teleportation portal.

Output Format
Print a single integer, the maximum number of chocolates that can be collected by both robots combined.

Constraints
2 ≤ N, M ≤ 70

0 ≤ grid[i][j] ≤ 100 (except portals marked as -1)

Sample Testcase 0
Testcase Input
3 3
1 2 3
4 5 6
7 8 9
Testcase Output
32
Explanation
Robot 1: (0,0)=1 → (1,1)=5 → (2,2)=9 → sum = 15


Robot 2: (0,2)=3 → (1,2)=6 → (2,1)=8 → sum = 17


 


They never share a cell, so total = 15 + 17 = 32.

Sample Testcase 1
Testcase Input
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Testcase Output
73
Explanation
Robot 1: (0,0)=1 → (1,1)=6 → (2,2)=11 → (3,3)=16 → sum = 34


Robot 2: (0,3)=4 → (1,3)=8 → (2,3)=12 → (3,2)=15 → sum = 39


They never share a cell, so total = 34 + 39 = 73.

Companies
Topics
Data Structures
Dynamic Programming

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> grid;
int dp[70][70][70];

int getMaxChocolates(int row, int col1, int col2) {
    if (col1 < 0 || col1 >= M || col2 < 0 || col2 >= M)
        return 0;

    if (row == N)
        return 0;

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    int chocolates = 0;

    // Handle teleportation
    if (grid[row][col1] == -1) {
        int maxTeleport1 = 0;
        for (int newCol1 = 0; newCol1 < M; ++newCol1) {
            maxTeleport1 = max(maxTeleport1, getMaxChocolates(row + 1, newCol1, col2));
        }
        return dp[row][col1][col2] = maxTeleport1;
    }

    if (grid[row][col2] == -1) {
        int maxTeleport2 = 0;
        for (int newCol2 = 0; newCol2 < M; ++newCol2) {
            maxTeleport2 = max(maxTeleport2, getMaxChocolates(row + 1, col1, newCol2));
        }
        return dp[row][col1][col2] = maxTeleport2;
    }

    if (col1 == col2)
        chocolates += grid[row][col1];
    else
        chocolates += grid[row][col1] + grid[row][col2];

    int maxNext = 0;
    for (int d1 = -1; d1 <= 1; ++d1) {
        for (int d2 = -1; d2 <= 1; ++d2) {
            maxNext = max(maxNext, getMaxChocolates(row + 1, col1 + d1, col2 + d2));
        }
    }

    return dp[row][col1][col2] = chocolates + maxNext;
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    // Initialize DP table
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < M; ++k)
                dp[i][j][k] = -1;

    // Start from top-left and top-right corners
    int result = getMaxChocolates(0, 0, M - 1);
    cout << result << endl;
    return 0;
}
