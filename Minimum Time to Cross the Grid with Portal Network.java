/*
Problem Statement
You are given a map represented by a 2D integer matrix `grid` of size m x n. Each cell grid[r][c] represents the time cost required to step onto that cell from an adjacent cell (up, down, left, right).

There is also a special "Portal Network". You are provided with a list of specific integers called `portals`. If two cells (r1, c1) and (r2, c2) have the exact same value, and that value exists in the `portals` list, you can travel instantly between them (cost 0).

However, utilizing the Portal Network is physically taxing. You have a limit of `k` portal jumps you can perform in total along your path.

Your task is to calculate the minimum time required to travel from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1).

Rules:

Start at (0, 0). The cost of the starting cell itself is NOT included.
Moving to adjacent cell (r, c) adds `grid[r][c]` to your total time.
Portal movement: Moving from (r1, c1) to (r2, c2) costs 0 time if:
grid[r1][c1] == grid[r2][c2]
grid[r1][c1] is in the `portals` list
You have used fewer than `k` jumps so far.
Note: Portal values are unique and between 1 and 100.

Input Format
The first line contains two integers `m` and `n` separated by a space, representing the number of rows and columns of the grid.

The next `m` lines each contain `n` integers separated by spaces, representing the rows of the `grid`.

The next line contains a single integer `P`, representing the number of values in the portal network.

The next line contains `P` integers separated by spaces, representing the values in `portals`. (If P is 0, this line may be empty or skipped).

The last line contains a single integer `k`, representing the maximum number of portal jumps allowed.

Output Format
Print a single integer representing the minimum time cost. If the destination is unreachable, print -1.

Constraints
1 <= m, n <= 10^2

1 <= grid[i][j] <= 10^2

0 <= P <= 10^2

1 <= k <= 50

Sample Testcase 0
Testcase Input
3 3
1 3 1
3 3 3
1 3 1
1
3
1
Testcase Output
4
Explanation
Grid is 3x3. Portals are values [3]. Max jumps k=1.


Optimal path:
- Start at (0,0).
- Move Right to (0,1) [Value 3]. Cost increases by 3. (Current Total: 3).
- The value at (0,1) is 3, which is a portal. Warp to (2,1) [Value 3]. Warp Cost: 0. Jumps used: 1.
- Move Right to (2,2) [Value 1]. Cost increases by 1. (Current Total: 4).
   
Total Cost: 3 + 0 + 1 = 4.

Sample Testcase 1
Testcase Input
2 2
1 100
100 1
0

0
Testcase Output
101
Explanation
Grid 2x2. P=0 (no portals). K=0.


Path:
- Start at (0,0).
- Move Right to (0,1) [Value 100]. Cost increases by 100.
- Move Down to (1,1) [Value 1]. Cost increases by 1.


Total Cost: 100 + 1 = 101.

Companies
Topics
Graph
Dijkstra's Algorithm
Shortest Path
Heaps
greedy
*/
import java.io.*;
import java.util.*;

class Solution {

    static class State implements Comparable<State> {
        int cost, r, c, used;
        State(int cost, int r, int c, int used) {
            this.cost = cost;
            this.r = r;
            this.c = c;
            this.used = used;
        }
        public int compareTo(State other) {
            return Integer.compare(this.cost, other.cost);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] dims = br.readLine().trim().split("\\s+");
        int m = Integer.parseInt(dims[0]);
        int n = Integer.parseInt(dims[1]);

        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            String[] row = br.readLine().trim().split("\\s+");
            for (int j = 0; j < n; j++) {
                grid[i][j] = Integer.parseInt(row[j]);
            }
        }

        int P = Integer.parseInt(br.readLine().trim());
        Set<Integer> portalSet = new HashSet<>();
        if (P > 0) {
            String[] portalVals = br.readLine().trim().split("\\s+");
            for (int i = 0; i < P; i++) {
                portalSet.add(Integer.parseInt(portalVals[i]));
            }
        } else {
            // consume empty line if present
            br.readLine();
        }

        int k = Integer.parseInt(br.readLine().trim());

        // Map portal value -> list of coordinates
        Map<Integer, List<int[]>> portalPositions = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (portalSet.contains(grid[i][j])) {
                    portalPositions.computeIfAbsent(grid[i][j], x -> new ArrayList<>()).add(new int[]{i, j});
                }
            }
        }

        int INF = Integer.MAX_VALUE / 2;
        int[][][] dist = new int[m][n][k+1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                Arrays.fill(dist[i][j], INF);

        dist[0][0][0] = 0;
        PriorityQueue<State> pq = new PriorityQueue<>();
        pq.add(new State(0, 0, 0, 0));

        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            int cost = cur.cost, r = cur.r, c = cur.c, used = cur.used;

            if (r == m-1 && c == n-1) {
                System.out.println(cost);
                return;
            }
            if (cost > dist[r][c][used]) continue;

            // Normal moves
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newCost = cost + grid[nr][nc];
                    if (newCost < dist[nr][nc][used]) {
                        dist[nr][nc][used] = newCost;
                        pq.add(new State(newCost, nr, nc, used));
                    }
                }
            }

            // Portal moves
            if (used < k && portalSet.contains(grid[r][c])) {
                for (int[] pos : portalPositions.get(grid[r][c])) {
                    int pr = pos[0], pc = pos[1];
                    if (pr == r && pc == c) continue;
                    if (cost < dist[pr][pc][used+1]) {
                        dist[pr][pc][used+1] = cost;
                        pq.add(new State(cost, pr, pc, used+1));
                    }
                }
            }
        }

        System.out.println(-1);
    }
}
