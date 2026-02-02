/*
Problem Statement
In a distant galaxy, there are N planets connected by N-1 wormholes, forming a tree structure. Each planet produces a specific amount of energy, represented by an integer value. This value can be positive (resource-rich), zero, or negative (resource-consuming).

The Galactic Federation wants to form a Strategic Alliance by selecting exactly K planets to build defense stations. However, the wormhole network has a limitation: to prevent signal interference, no two selected planets can be directly connected by a wormhole.

Your task is to select exactly K planets such that:

No two selected planets are adjacent.
The sum of energy values of the selected planets is maximized.
If it is impossible to select exactly K planets satisfying the interference constraint, return -1.

Note: The graph is guaranteed to be a tree.

Input Format
The first line contains two space-separated integers N and K, representing the number of planets and the required number of defense stations.

The second line contains N space-separated integers E[0], E[1], ..., E[N-1], where E[i] is the energy value of the i-th planet.

The next N-1 lines each contain two space-separated integers u and v, representing a wormhole connecting planet u and planet v. The planets are numbered from 1 to N.

Output Format
Print a single integer: the maximum total energy of the selected K planets. If it is impossible to select K planets, print -1.

Constraints
1 <= N <= 2 * 10^3

1 <= K <= N

-10^5 <= E[i] <= 10^5

Sample Testcase 0
Testcase Input
3 2
5 10 5
1 2
1 3
Testcase Output
15
Explanation
The structure is a "V" shape where Node 1 is connected to both Node 2 and Node 3 (2-1-3).
We need to pick exactly 2 planets such that no two are adjacent.
Let's check the possible pairs:
- {1, 2}: Invalid. They are directly connected.
- {1, 3}: Invalid. They are directly connected.
- {2, 3}: Valid. There is no direct connection between 2 and 3.


Therefore, we select planets 2 and 3.
Total Energy = Energy(2) + Energy(3) = 10 + 5 = 15.

Sample Testcase 1
Testcase Input
5 3
10 10 10 10 10
1 2
2 3
3 4
4 5
Testcase Output
30
Explanation
The structure is a line: 1-2-3-4-5.
We need to pick 3 planets such that no two are adjacent.
The only valid set of size 3 is {1, 3, 5}.
Total Energy = 10 + 10 + 10 = 30.

Companies
Topics
Graph
Data Structures
Tree
*/
import java.io.*;
import java.util.*;

class Solution {

    static final long NEG_INF = (long)-1e18;
    static int N, K;
    static long[] energy;
    static List<Integer>[] tree;

    static long[][] dp0, dp1;
    static int[] size;

    static void dfs(int u, int parent) {
        dp0[u][0] = 0;
        dp1[u][1] = energy[u];
        size[u] = 1;

        for (int v : tree[u]) {
            if (v == parent) continue;

            dfs(v, u);

            long[] newDp0 = new long[K + 1];
            long[] newDp1 = new long[K + 1];
            Arrays.fill(newDp0, NEG_INF);
            Arrays.fill(newDp1, NEG_INF);

            for (int i = 0; i <= Math.min(size[u], K); i++) {
                if (dp0[u][i] == NEG_INF && dp1[u][i] == NEG_INF) continue;

                for (int j = 0; j <= Math.min(size[v], K - i); j++) {

                    // u not selected → child may or may not be
                    long bestChild = Math.max(dp0[v][j], dp1[v][j]);
                    if (dp0[u][i] != NEG_INF && bestChild != NEG_INF) {
                        newDp0[i + j] = Math.max(newDp0[i + j], dp0[u][i] + bestChild);
                    }

                    // u selected → child must NOT be selected
                    if (dp1[u][i] != NEG_INF && dp0[v][j] != NEG_INF) {
                        newDp1[i + j] = Math.max(newDp1[i + j], dp1[u][i] + dp0[v][j]);
                    }
                }
            }

            dp0[u] = newDp0;
            dp1[u] = newDp1;
            size[u] += size[v];
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] first = br.readLine().trim().split("\\s+");
        N = Integer.parseInt(first[0]);
        K = Integer.parseInt(first[1]);

        energy = new long[N];
        String[] vals = br.readLine().trim().split("\\s+");
        for (int i = 0; i < N; i++) energy[i] = Long.parseLong(vals[i]);

        tree = new ArrayList[N];
        for (int i = 0; i < N; i++) tree[i] = new ArrayList<>();

        for (int i = 0; i < N - 1; i++) {
            String[] edge = br.readLine().trim().split("\\s+");
            int u = Integer.parseInt(edge[0]) - 1;
            int v = Integer.parseInt(edge[1]) - 1;
            tree[u].add(v);
            tree[v].add(u);
        }

        dp0 = new long[N][K + 1];
        dp1 = new long[N][K + 1];
        size = new int[N];

        for (int i = 0; i < N; i++) {
            Arrays.fill(dp0[i], NEG_INF);
            Arrays.fill(dp1[i], NEG_INF);
        }

        dfs(0, -1);

        long ans = Math.max(dp0[0][K], dp1[0][K]);
        System.out.println(ans < 0 ? -1 : ans);
    }
}
