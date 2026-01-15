/*
Problem Statement
You are designing an automatic sewing machine that stitches a rectangular cloth using a thread line that moves over the cloth surface. The cloth is represented as a 2D grid of size M x N, where each cell needs exactly one stitch. The stitching needle starts at the top-left cell (0, 0) and can move:

Right (R)

Down (D)

Left (L)

Up (U)

However, there's a constraint:

Turning the needle (changing direction) consumes extra thread (T units).

Stitching each cell normally consumes 1 unit of thread.

The machine must cover all cells exactly once (no cell can be stitched twice), ending at any cell.

Your task is to compute the minimum total thread required to stitch the entire cloth exactly once, considering the cost of turning.

Input Format
First line: Three integers M, N, and T

Output Format
Print the minimum total thread required to stitch the entire cloth exactly once, considering both stitching and turning costs.

Constraints
1 ≤ M ≤ 5

1 ≤ N ≤ 6

0 ≤ T ≤ 1000

Sample Testcase 0
Testcase Input
2 3 3
Testcase Output
12
Explanation
Grid: 2 rows × 3 columns


Stitch each of the 6 cells.


Start at (0,0)


One optimal path: (0,0) → (0,1) → (0,2) → (1,2) → (1,1) → (1,0)


Directions: Right → Right → Down → Left → Left
Turns: 2 (Right→Down, Down→Left)
Thread Cost:


Stitching: 6


Turns: 2 × 3 = 6


Total: 6 + 6 = 12

Sample Testcase 1
Testcase Input
1 4 2
Testcase Output
4
Explanation
Grid: 1 row × 4 columns


Only one valid path: move right across all cells.


Path: (0,0) → (0,1) → (0,2) → (0,3)


Directions: Right → Right → Right
Turns: 0
Thread Cost:


Stitching: 4


Turns: 0 × 2 = 0


Total: 4

Companies
Topics
Dynamic Programming
Bitmask
Backtracking
Grid Traversal
Recursion
Optimization
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, dir;
    int mask;
};

int M, N, T;
int totalCells;
map<tuple<int,int,int,int>, int> memo;

int dx[4] = {0, 1, 0, -1}; // R, D, L, U
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y, int dir, int mask) {
    if (mask == (1 << totalCells) - 1) return 1; // stitched last cell

    auto key = make_tuple(x,y,dir,mask);
    if (memo.count(key)) return memo[key];

    int ans = 1e9;
    for (int ndir = 0; ndir < 4; ndir++) {
        int nx = x + dx[ndir];
        int ny = y + dy[ndir];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

        int pos = nx * N + ny;
        if (mask & (1 << pos)) continue; // already stitched

        int cost = 1; // stitching
        if (dir != -1 && dir != ndir) cost += T; // turn cost

        ans = min(ans, cost + dfs(nx, ny, ndir, mask | (1 << pos)));
    }
    return memo[key] = ans;
}

int main() {
    cin >> M >> N >> T;
    totalCells = M * N;
    memo.clear();
    cout << dfs(0, 0, -1, 1 << 0) << endl;
    return 0;
}














