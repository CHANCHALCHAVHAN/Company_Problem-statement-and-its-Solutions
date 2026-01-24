/*
Problem Statement
You are a trader navigating through an archipelago of N islands, connected by M directed sea routes. Each island offers a unique type of good, represented by an integer from 1 to N. You begin your journey from island 1, and your goal is to reach island N while collecting at least K distinct types of goods along the way.

Traveling from one island to another via a sea route consumes time. Once you collect a good from an island, it starts degrading and becomes worthless after X time units. Only the goods that are still fresh when you reach island N are counted.

You must determine the minimum freshness threshold X such that there exists a path from island 1 to island N collecting at least K distinct goods that are still fresh upon arrival. If no such path exists, print -1.

Input Format
The first line contains N repesenting the number of islands, M representing the number of one-way sea routes and K representing the minimum number of distinct goods required at the end.

The second line contains N integers where Gi represents the type of good available on island i.

Each of the next M lines describes a route from island ui to island vi with a travel time of ti.

 

Output Format
A single integer: the minimum freshness threshold `X` required, or -1 if it is not possible to reach island `N` with at least `K` fresh distinct goods

Constraints
 2 ≤ N ≤ 10⁴

1 ≤ M ≤ 2 × 10⁴

1 ≤ K ≤ N

1 ≤ ti ≤ 10³

1 ≤ Gi ≤ N

Multiple edges between the same pair of nodes are allowed

Graph may contain cycles

You may revisit islands

Sample Testcase 0
Testcase Input
4 4 4
1 2 3 4
1 2 3
2 3 2
3 4 3
1 3 6
Testcase Output
8
Explanation
Route: 1 → 2 → 3 → 4
 Time at each: 0, 3, 5, 8
 Goods collected at islands 1, 2, 3, 4
 Freshness of each: 8 - collection time
 Maximum freshness needed = 8

Sample Testcase 1
Testcase Input
5 6 3
1 2 3 2 5
1 2 4
2 3 5
3 5 6
1 4 3
4 3 2
4 5 5
Testcase Output
8
Explanation

N=5 islands, M=6 edges, K=3 distinct goods needed.

Goods: Island 1: good 1, Island 2: good 2, Island 3: good 3, Island 4: good 2, Island 5: good 5.

Edges: 1→2 (4), 2→3 (5), 3→5 (6), 1→4 (3), 4→3 (2), 4→5 (5).

Goal: Find minimum X X X such that a path from island 1 to 5 collects ≥3 distinct goods, fresh at arrival.Key Path: 1 → 4 → 5



Time: 1→4 (3) + 4→5 (5) = 8.

Goods: Good 1 (t=0), Good 2 (t=3), Good 5 (t=8).

Freshness at t=8: Good 1: 8−0=8 8-0=8 8−0=8, Good 2: 8−3=5 8-3=5 8−3=5, Good 5: 8−8=0 8-8=0 8−8=0.

X: max⁡(8,5,0)=8 \max(8, 5, 0) = 8 max(8,5,0)=8.

Result: 3 distinct goods (1, 2, 5) are fresh with X=8 X=8 X=8.


Alternative Path: 1 → 4 → 3 → 5



Time: 1→4 (3) + 4→3 (2) + 3→5 (6) = 11.

Goods: Good 1 (t=0), Good 2 (t=3), Good 3 (t=5), Good 5 (t=11).

Freshness at t=11: Good 2: 11−3=8 11-3=8 11−3=8, Good 3: 11−5=6 11-5=6 11−5=6, Good 5: 11−11=0 11-11=0 11−11=0.

X for 3 goods (2, 3, 5): max⁡(8,6,0)=8 \max(8, 6, 0) = 8 max(8,6,0)=8.

Other Paths: Paths like 1→2→3→5 require X=11 X=11 X=11 for 3 goods (e.g., goods 2, 3, 5), which is larger.


Output: 8 (smallest X X X for 3 fresh distinct goods via 1→4→5 or 1→4→3→5).

Companies
Juspay
Microsoft
Salesforce
Topics
Binary Search
Breadth-First Search
Path Finding
Data Structures & Algorithms
*/
import java.util.*;

public class Main {
    static class Edge {
        int to, time;
        Edge(int to, int time) {
            this.to = to;
            this.time = time;
        }
    }

    static class State {
        int node, time;
        Map<Integer, Integer> collectTime; // good -> collection time
        State(int node, int time, Map<Integer, Integer> collectTime) {
            this.node = node;
            this.time = time;
            this.collectTime = new HashMap<>(collectTime);
        }
    }

    public static int minimum_freshness_threshold(int n, int m, int k, int[] goods, int[][] edges) {
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(new Edge(e[1], e[2]));
        }

        Queue<State> q = new LinkedList<>();
        Map<Integer,Integer> startCollect = new HashMap<>();
        startCollect.put(goods[0], 0);
        q.add(new State(1, 0, startCollect));

        int answer = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            State cur = q.poll();

            if (cur.node == n) {
                if (cur.collectTime.size() >= k) {
                    int arrival = cur.time;
                    // sort collection times
                    List<Integer> times = new ArrayList<>(cur.collectTime.values());
                    Collections.sort(times);
                    // choose latest K goods
                    int earliestChosen = times.get(times.size() - k);
                    int freshness = arrival - earliestChosen;
                    answer = Math.min(answer, freshness);
                }
                continue;
            }

            for (Edge e : graph.get(cur.node)) {
                int newTime = cur.time + e.time;
                Map<Integer,Integer> newCollect = new HashMap<>(cur.collectTime);
                newCollect.putIfAbsent(goods[e.to - 1], newTime);
                q.add(new State(e.to, newTime, newCollect));
            }
        }

        return answer == Integer.MAX_VALUE ? -1 : answer;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
        int[] goods = new int[n];
        for (int i = 0; i < n; i++) goods[i] = sc.nextInt();
        int[][] edges = new int[m][3];
        for (int i = 0; i < m; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            edges[i][2] = sc.nextInt();
        }
        System.out.println(minimum_freshness_threshold(n, m, k, goods, edges));
    }
}
