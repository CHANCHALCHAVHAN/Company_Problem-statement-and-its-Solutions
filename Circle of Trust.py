'''
Problem Statement
In a company, every employee either trusts another employee or doesn't. This trust is one-way — for example, if Alice trusts Bob, Bob may or may not trust Alice back.

The company wants to identify the largest group of employees such that every person in the group either directly or indirectly trusts everyone else in the group, and vice versa. This means the group is a circle of mutual trust, where everyone is somehow connected in both directions through the trust chain.

You are given N employees (numbered from 1 to N) and M directed trust relationships (pairs of employees A → B, meaning A trusts B).

Your task is to find the size of the largest such group of mutual trust.

Input Format
First line: Two integers N and M (1 ≤ N ≤ 10⁵, 0 ≤ M ≤ 2×10⁵)

Next M lines: Each contains two integers A B (1 ≤ A, B ≤ N) — meaning A trusts B
Output Format
A single integer — the size of the largest group where mutual trust is reachable among all members (i.e., size of the largest strongly connected component).

Constraints
1 ≤ N ≤ 10⁵
0 ≤ M ≤ 2×10⁵
1 ≤ A, B ≤ N
Sample Testcase 0
Testcase Input
4 2  
1 2  
3 4
Testcase Output
1
Explanation

No cycles exist.

Each node is its own strongly connected component


 Largest mutual group = 1

Sample Testcase 1
Testcase Input
5 5  
1 2  
2 3  
3 1  
4 5  
5 4
Testcase Output
3
Explanation

There are two circles:



{1, 2, 3} form a cycle: each person is connected to others in both directions

{4, 5} form another cycle



 Largest group size is 3

Companies
Topics
DFS
Tarjan's algorithm
Graph
'''
#CODE::=>
import sys
sys.setrecursionlimit(10**6)

def kosaraju(N, adj):
    visited = [False] * (N + 1)
    order = []

    def dfs1(u):
        visited[u] = True
        for v in adj[u]:
            if not visited[v]:
                dfs1(v)
        order.append(u)

    for i in range(1, N + 1):
        if not visited[i]:
            dfs1(i)

    # Reverse the graph
    radj = [[] for _ in range(N + 1)]
    for u in range(1, N + 1):
        for v in adj[u]:
            radj[v].append(u)

    visited = [False] * (N + 1)
    max_scc = 0

    def dfs2(u, comp):
        visited[u] = True
        comp.append(u)
        for v in radj[u]:
            if not visited[v]:
                dfs2(v, comp)

    for u in reversed(order):
        if not visited[u]:
            comp = []
            dfs2(u, comp)
            max_scc = max(max_scc, len(comp))

    return max_scc

# Input Handling
N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B = map(int, input().split())
    adj[A].append(B)

print(kosaraju(N, adj))
