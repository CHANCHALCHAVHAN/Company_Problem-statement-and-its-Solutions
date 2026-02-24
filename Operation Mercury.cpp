/*
Problem Statement
Agent Smith is in a chamber that's like a grid (H X W), and each cell in this grid has a certain height. The chamber is currently filled with a toxic substance, mercury. The mercury is leaking from a specific cell and spreads horizontally and vertically until it encounters cells with heights greater than or equal to its own potency .  If the height of the cell is greater than or equal to the potency then mercury will not leak.

The task is to find out, for each combination of potency and origin cell provided, how many cells in the chamber are affected by the mercury leak.

For instance, given a specific potency and origin cell, the task is to determine how far the mercury spreads horizontally and vertically until it encounters cells with heights greater than or equal to its own potency.

Here, H and W are denoting height and width of the grid, where in each row the height of the cell is given.

Input Format
The first line of each test case contains three integers: H, W, and Q. These represent the height, width, and number of queries (combinations of potency and origin cell) respectively.

The next line contains H lines, each containing W space-separated integers denoting the heights of cells in the grid.

Following that, each of the Q lines contains three integers: r[i], c[i], and p[i], representing the  origin cell(row, column) and potency of the mercury leak for each query.

Output Format
Display Q space separated integers representing the number of hazardous cells reached by the mercury leak for the corresponding combination.

Constraints
1 ≤ H, W ≤ 1000
1 ≤ Q ≤ 2*10^5
1 ≤ r[i] ≤ H
1 ≤ c[i] ≤ W
0 ≤ A[i][j] ≤ 10^9 (height of cells)
0 ≤ p[i] ≤ 10^9 (potency of mercury leak)
Sample Testcase 0
Testcase Input
5 5 3 
4 3 9 7 2
8 6 5 2 8
1 7 3 4 3
2 2 4 5 6
9 9 9 9 9 
3 4 6 
3 2 5 
1 4 9
Testcase Output
10 0 19
Explanation
There are 3 queries provided.


Query 1: Starting from cell (3, 4) with a potency of 6.


The cell (3,4) has a height of 4, which is smaller than the potency (6). Therefore, the mercury spread horizontly and vertically until it reaches cells with heights less than the potency before dissipating.





 


It reaches 10 cells (origin cell included) before dissipating.


Query 2: Starting from cell (3,2) with a potency of 5.
The cell (3, 2) has a height of 7, which is greater than the potency (5). Therefore, the mercury dissipates immediately, and no other cells are affected. Thus, the output for this query is 0.

Similarly, we can calculate for Qyery 3.

Sample Testcase 1
Testcase Input
3 3 2
2 4 3
1 5 6
3 1 7
1 2 3
2 3 4
Testcase Output
0 0
Explanation
We have a grid with dimensions 3x3, where each cell has a corresponding height:


There are 2 queries in this test case:


Mercury leak originates from cell (1, 2) with a potency of 3.


Mercury leak originates from cell (2, 3) with a potency of 4.


Starting with the first query:


The cell (1, 2) has a height of 4, which is greater than the potency (3). Therefore, the mercury dissipates immediately, and no other cells are affected. Thus, the output for this query is 0.


Moving on to the second query:


The cell (2, 3) has a height of 6, which is greater than the potency (4). Again, the mercury dissipates immediately, and no other cells are affected. Thus, the output for this query is also 0.

Companies
Juspay
Meesho
HCL
Topics
BFS
Graph
Graph

*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void user_logic(int H, int W, vector<vector<int>>& grid, vector<tuple<int, int, int>>& queries, vector<int>& result) {
    // Directions for 4-neighbor movement (up, down, left, right)
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int qi = 0; qi < (int)queries.size(); qi++) {
        int r, c, p;
        tie(r, c, p) = queries[qi];
        r--; c--; // convert to 0-based indexing

        // If origin cell is blocked immediately
        if (grid[r][c] >= p) {
            result[qi] = 0;
            continue;
        }

        // BFS flood-fill
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<pair<int,int>> q;
        q.push({r, c});
        visited[r][c] = true;
        int count = 0;

        while (!q.empty()) {
            auto [cr, cc] = q.front(); q.pop();
            count++;

            for (int d = 0; d < 4; d++) {
                int nr = cr + dr[d];
                int nc = cc + dc[d];
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if (visited[nr][nc]) continue;
                if (grid[nr][nc] >= p) continue; // blocked by height

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        result[qi] = count;
    }
}
