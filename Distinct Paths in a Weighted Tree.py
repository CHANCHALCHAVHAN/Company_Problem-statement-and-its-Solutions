'''
Problem Statement
You are given an undirected weighted tree with N nodes and (N-1) edges, where each edge has a positive weight.

Additionally, you are given q queries, where each query consists of a single integer X. For each query, count the number of distinct paths in the tree where the maximum edge weight in the path is less than or equal to X.

A path is defined as a sequence of connected edges between any two nodes in the tree.

A path from node A to node B is considered the same as a path from node B to node A.

A tree is an acyclic connected graph with n nodes and (N−1) edges.

Input Format
The first line contains an integer n (2 ≤ n ≤ 10^4) — the number of nodes in the tree.

The next (n-1) lines each contain three integers U, V, W (1 ≤ U,V ≤,0 ≤ W ≤ 10^5), representing an undirected edge between nodes uuu and vvv with weight www.

The next line contains an integer Q (1 ≤ Q ≤ 10^4) — the number of queries.

The next line contains q integers, x1, x2, ..., xq (0 ≤ Xi ≤ 10^5) , where each xix_ixi​ is the threshold weight for the query.

Output Format
Print q integers, where the ith integer represents the number of distinct paths in the tree such that the maximum edge weight in the path is ≤ Xi

Constraints
2 ≤ N ≤ 104

1 ≤ Q ≤ 104

1 ≤ U,V ≤ n

U ≠ V

0 ≤ W  ≤ 10^5

0 ≤ Xi ≤ 10^5

Sample Testcase 0
Testcase Input
3
1 2 1
2 3 4
1
3
Testcase Output
1
Explanation


Query 1 (max weight = 3): The only valid path is (1 to 2) (weight = 1).




The path (2 to 3) is not included since its edge weight (4) exceeds 3.



Sample Testcase 1
Testcase Input
7
1 2 3
2 3 1
2 4 9
3 6 7
3 5 8
5 7 4
3
1 3 5
Testcase Output
1 3 4
Explanation


Query 1 (max weight = 1):




Valid path: (2 to 3)






Query 2 (max weight = 3):




Valid paths: (1 to 2), (1 to 3), (2 to 3)






Query 3 (max weight = 5):




Valid paths: (1 to 2), (1 to 3), (2 to 3), (5 to 7)





Companies
Meesho
VMware
ZS
Topics
Data Structure
unionn
Tree
'''

import sys

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.total_paths = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        
        if root_u != root_v:
            if self.size[root_u] < self.size[root_v]:
                root_u, root_v = root_v, root_u
                
            self.parent[root_v] = root_u
            self.total_paths[root_u] += self.total_paths[root_v] + self.size[root_u] * self.size[root_v]
            self.size[root_u] += self.size[root_v]

def count_paths(n, edges, queries):
    edges.sort(key=lambda x: x[2])  
    sorted_queries = sorted(enumerate(queries), key=lambda x: x[1])  

    dsu = DSU(n)
    results = [0] * len(queries)
    edge_index = 0
    total_count = 0

    for query_index, threshold in sorted_queries:
        while edge_index < len(edges) and edges[edge_index][2] <= threshold:
            u, v, w = edges[edge_index]
            dsu.union(u - 1, v - 1)
            total_count = dsu.total_paths[dsu.find(u - 1)]
            edge_index += 1
        
        results[query_index] = total_count

    return results

# Read input efficiently
input = sys.stdin.read
data = input().split("\n")

n = int(data[0])
edges = [tuple(map(int, data[i].split())) for i in range(1, n)]
q = int(data[n])
queries = list(map(int, data[n + 1].split()))

# Get results and print
result = count_paths(n, edges, queries)
sys.stdout.write(" ".join(map(str, result)) + "\n")
