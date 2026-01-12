/*
Problem Statement
You are trapped in a cursed maze represented as an N x M grid. Each cell (i, j) has:

0: An empty path.

-1: A cursed wall (cannot pass).

X > 0: A magical rune that grants X points but curses you for X steps (you cannot pick up another rune until X steps have passed).

You start at (0, 0) and must reach (N-1, M-1) while maximizing your total rune points. Movement is allowed in 4 directions (up, down, left, right).

Challenge: Find the maximum points you can collect without violating the curse constraints.

Input Format
The first line contain two integers N & M (dimensions of the maze).

Next N lines each containing M space-separated integers representing the maze grid.

Output Format
1 ≤ N, M ≤ 100

0 ≤ X ≤ 10 (rune values)

It is guaranteed that (0, 0) and (N-1, M-1) are not cursed walls.

Constraints
Print a single integer: Maximum points collected, or -1 if the exit is unreachable.

Sample Testcase 0
Testcase Input
3 3
0  2 -1
0 -1  3
0  0  0
Testcase Output
5
Explanation
Take rune 2 at (0,1). Curse lasts 2 steps.
Move to (0,0) → (1,0) → (2,0) (2 steps passed).
Now take rune 3 at (2,1). Total points = 2 + 3 = 5.
Reach (2,2).

Sample Testcase 1
Testcase Input
4 4
0 1 0 0
0 -1 0 0
2 0 -1 0
0 0 0 3
Testcase Output
6
Explanation
Start at (0,0), cooldown=0, points=0.
Move right to (0,1), pick rune 1 → points=1, cooldown=1.
Need to wait 1 step before next rune.
Move down to (1,1) blocked, so instead move down to (1,0), cooldown=0, points=1.
Move down to (2,0), cooldown=0, pick rune 2 → points=3, cooldown=2.


Need to wait 2 steps:
Move right to (2,1), cooldown=1.
Move down to (3,1), cooldown=0.
Move right to (3,2), cooldown=0.
Move right to (3,3), cooldown=0, pick rune 3 → points=6, cooldown=3.


End reached with total points 6.

Companies
Topics
BFS
Dynamic Programming
Grid
Graph
*/
#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, cd;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // dp[x][y][cd] = maximum points achievable at (x,y) with cooldown cd
    vector<vector<vector<int>>> dp(
        N, vector<vector<int>>(M, vector<int>(11, -1))
    );

    queue<State> q;
    dp[0][0][0] = 0;
    q.push({0, 0, 0});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y, cd] = q.front();
        q.pop();

        int currPoints = dp[x][y][cd];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (grid[nx][ny] == -1) continue;

            int nextCd = max(0, cd - 1);
            int nextPoints = currPoints;

            // If we can pick a rune
            if (grid[nx][ny] > 0 && nextCd == 0) {
                nextPoints += grid[nx][ny];
                nextCd = grid[nx][ny];
            }

            if (dp[nx][ny][nextCd] < nextPoints) {
                dp[nx][ny][nextCd] = nextPoints;
                q.push({nx, ny, nextCd});
            }
        }
    }

    int ans = -1;
    for (int cd = 0; cd <= 10; cd++) {
        ans = max(ans, dp[N - 1][M - 1][cd]);
    }

    cout << ans << "\n";
    return 0;
}
