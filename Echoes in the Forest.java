/*
Problem Statement
You are an explorer in a magical forest represented by a 2D grid of size N x M. Each cell is either:

Tree (T), which blocks movement,

Empty ground (.), where you can walk freely,

Echo Stone (E), a special stone that amplifies your steps as echoes.

You start at a given empty cell (Sx, Sy). Your goal is to reach a target empty cell (Tx, Ty).

Every time you step on an Echo Stone (E), your footsteps echo through the forest. This echo causes all adjacent empty cells (up, down, left, right) to become temporarily blocked for the next K moves due to magical vibrations — you cannot move into these adjacent cells during those K moves.

You can step onto the Echo Stone cell itself.

The temporary block starts immediately after stepping on the Echo Stone.

Multiple echoes’ block timers are independent and can overlap.

Trees (T) are permanently blocked, regardless of echoes.

You can move only up, down, left, or right into unblocked empty or Echo Stone cells.

Find the minimum number of moves needed to reach (Tx, Ty) from (Sx, Sy), considering the echo blocking effect.

If it is impossible to reach the target, output -1.

Input Format
The first line contains three integers: N, M, and K

The next N lines each contain a string of length M representing the forest grid.

The next line contains two integers Sx and Sy.

The next line contains two integers Tx and Ty.

Output Format
Print the minimum number of moves to reach the target, or -1 if unreachable.

Constraints
2 <= N, M <= 50

1 <= K <= 10

Sx, Sy, Tx, Ty

Sample Testcase 0
Testcase Input
3 3 1
...
...
...
1 1
3 3
Testcase Output
4
Explanation
Grid:
. . .
. . .
. . .



Start: (1,1)
Target: (3,3)


You can go in a straight path:


(1,1) → (1,2) → (1,3) → (2,3) → (3,3)


You reach the target in 4 steps.





Sample Testcase 1
Testcase Input
4 4 2
....
.E..
....
....
1 1
4 4
Testcase Output
6
Explanation
Grid:
. . . .
. E . .
. . . .
. . . .


Start: (1,1)
Target: (4,4)


Echo stone is at (2,2), but we can avoid it.


Path: (1,1) → (1,2) → (1,3) → (1,4) → (2,4) → (3,4) → (4,4)


Echo stone is not triggered, so no temporary blocks happen.
You reach the target in 6 steps.





Companies
Topics
Graph
BFS
Grid
Shortest Path
Simulation
Path Finding
Data Structure
Graph Theory
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Main {

    static class State {
        int x, y, steps;
        int[][] block;

        State(int x, int y, int steps, int[][] block) {
            this.x = x;
            this.y = y;
            this.steps = steps;
            this.block = block;
        }
    }

    static int N, M, K;
    static char[][] grid;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static int[][] copy(int[][] src) {
        int[][] dest = new int[N][M];
        for (int i = 0; i < N; i++) {
            dest[i] = src[i].clone();
        }
        return dest;
    }

    static int bfs(int sx, int sy, int tx, int ty) {
        Queue<State> q = new LinkedList<>();
        boolean[][][] visited = new boolean[N][M][K + 1];

        q.add(new State(sx, sy, 0, new int[N][M]));

        while (!q.isEmpty()) {
            State cur = q.poll();

            if (cur.x == tx && cur.y == ty) {
                return cur.steps;
            }

            int timeSlot = cur.steps % (K + 1);
            if (visited[cur.x][cur.y][timeSlot]) continue;
            visited[cur.x][cur.y][timeSlot] = true;

            // Decrease all block timers
            int[][] nextBlock = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    nextBlock[i][j] = Math.max(0, cur.block[i][j] - 1);
                }
            }

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (grid[nx][ny] == 'T') continue;
                if (nextBlock[nx][ny] > 0) continue;

                int[][] updatedBlock = copy(nextBlock);

                // Echo stone triggers temporary blocks
                if (grid[nx][ny] == 'E') {
                    for (int k = 0; k < 4; k++) {
                        int ax = nx + dx[k];
                        int ay = ny + dy[k];
                        if (ax >= 0 && ay >= 0 && ax < N && ay < M &&
                            grid[ax][ay] == '.') {
                            updatedBlock[ax][ay] = Math.max(updatedBlock[ax][ay], K);
                        }
                    }
                }

                q.add(new State(nx, ny, cur.steps + 1, updatedBlock));
            }
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        grid = new char[N][M];
        for (int i = 0; i < N; i++) {
            grid[i] = sc.next().toCharArray();
        }

        int sx = sc.nextInt() - 1;
        int sy = sc.nextInt() - 1;
        int tx = sc.nextInt() - 1;
        int ty = sc.nextInt() - 1;

        int result = bfs(sx, sy, tx, ty);
        System.out.println(result);
    }
}
