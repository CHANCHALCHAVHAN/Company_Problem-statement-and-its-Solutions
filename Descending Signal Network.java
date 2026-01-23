/*
Problem Statement
In the city of Neoterra, a communication network consists of N towers connected by N-1 underground fiber cables, forming a tree structure. Each cable connects two specific towers and has a fixed signal strength W. Additionally, each tower i contains a dataset of value D_i.

You must select exactly one tower to act as the Central Hub. Once a hub is chosen, other towers attempt to transmit their data to it. A tower S can successfully transmit its data to the Central Hub H if and only if the signal strength strictly decreases at every step along the unique path from S to H.

Formally:

Let the unique path from a source tower S to the hub H be: S = v_0 -> v_1 -> v_2 -> ... -> v_k = H
Let w_i be the weight of the edge connecting v_(i-1) and v_i.
The path is valid if and only if: w_1 > w_2 > ... > w_k
(Note: A path consisting of a single node (S=H) is always valid).

Your task is to determine the maximum total data that can be collected. This total is the sum of D_i for all towers i (including the hub itself) that can successfully transmit to the chosen hub. You want to maximize this sum by choosing the optimal hub.

Input Format
The first line contains a single integer N, the number of towers.

The next N-1 lines each contain three integers u, v, and w, representing an undirected edge between tower u and tower v with signal strength w.

The last line contains N space-separated integers d_0, d_1, ..., d_(N-1), where d_i is the data value of tower i.

Output Format
Output a single integer: the maximum total data that can be collected by choosing the best possible Central Hub.

Constraints
1 ≤ N ≤ 2 * 10^5

1 ≤ w ≤ 10^9

1 ≤ d_i ≤ 10^9

Sample Testcase 0
Testcase Input
5
0 1 10
1 2 8
1 3 5
3 4 3
5 4 3 2 1
Testcase Output
15
Explanation
The towers have data values: D=[5, 4, 3, 2, 1] for nodes 0 to 4.
The edges are: (0,1, w=10), (1,2, w=8), (1,3, w=5), (3,4, w=3).


Let's check two possible Hub choices:


1. Choosing Node 1 as Hub:
   - Node 0 -> 1: Edge w=10. Valid.
   - Node 2 -> 1: Edge w=8. Valid.
   - Node 3 -> 1: Edge w=5. Valid.
   - Node 4 -> 3 -> 1: Path edges are (4,3) w=3, then (3,1) w=5.
     Condition requires 3 > 5, which is False. Invalid.
   Total collected: D[1] + D[0] + D[2] + D[3] = 4 + 5 + 3 + 2 = 14.


2. Choosing Node 3 as Hub:
   - Node 4 -> 3: Edge w=3. Valid.
   - Node 1 -> 3: Edge w=5. Valid.
   - Node 0 -> 1 -> 3: Path edges are (0,1) w=10, (1,3) w=5.
     Condition 10 > 5 is True. Valid.
   - Node 2 -> 1 -> 3: Path edges are (2,1) w=8, (1,3) w=5.
     Condition 8 > 5 is True. Valid.
   Total collected: D[3] + D[4] + D[1] + D[0] + D[2] = 2 + 1 + 4 + 5 + 3 = 15.


The maximum possible total is 15 (achieved with Hub 3 or Hub 4).

Sample Testcase 1
Testcase Input
3
0 1 100
1 2 1
10 20 30
Testcase Output
60
Explanation
Choosing Node 2 as Hub:
- Node 1 -> 2: Edge w=1. Valid.
- Node 0 -> 1 -> 2: Path edges are (0,1) w=100, (1,2) w=1.
  Condition 100 > 1 is True. Valid.
Total: D[2] + D[1] + D[0] = 30 + 20 + 10 = 60.

Companies
Topics
Graph
Dynamic Programming
Depth-First Search
Tree
*/
import java.io.*;
import java.util.*;

class Main {

    static class Edge {
        int to;
        long w;
        Edge(int t, long w) {
            this.to = t;
            this.w = w;
        }
    }

    static int N;
    static List<Edge>[] graph;
    static long[] data;
    static boolean[] visited;
    static long answer = 0;

    static long dfs(int u, long prevW) {
        long sum = data[u];
        visited[u] = true;

        for (Edge e : graph[u]) {
            if (!visited[e.to] && e.w > prevW) {
                sum += dfs(e.to, e.w);
            }
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        N = fs.nextInt();
        graph = new ArrayList[N];
        for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < N - 1; i++) {
            int u = fs.nextInt();
            int v = fs.nextInt();
            long w = fs.nextLong();
            graph[u].add(new Edge(v, w));
            graph[v].add(new Edge(u, w));
        }

        data = new long[N];
        for (int i = 0; i < N; i++) data[i] = fs.nextLong();

        for (int hub = 0; hub < N; hub++) {
            visited = new boolean[N];
            long collected = dfs(hub, -1);
            answer = Math.max(answer, collected);
        }

        System.out.println(answer);
    }

    // Fast I/O (because scale matters)
    static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, res = 0;
            while ((c = read()) <= ' ') ;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            while (c > ' ') {
                res = res * 10 + (c - '0');
                c = read();
            }
            return res * sign;
        }

        long nextLong() throws IOException {
            int c, sign = 1;
            long res = 0;
            while ((c = read()) <= ' ') ;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            while (c > ' ') {
                res = res * 10 + (c - '0');
                c = read();
            }
            return res * sign;
        }
    }
}
