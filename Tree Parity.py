'''
Problem Statement
Ram enjoys solving puzzles with trees. He has a tree with N nodes, numbered from 1 to N, and the tree is rooted at node 1. Each node in the tree has a value a[i], and Ram is curious to know whether all nodes within a subtree of a given node i share the same parity (either all values are even or all are odd).

Ram is also considering modifying at most one node's value to change its parity temporarily, just to check if the condition holds.

You are asked to help Ram by answering q queries of the following types:

i x - Assign the value x to the i-th node.
i - Determine whether the subtree of node i can have all nodes with the same parity, allowing you to temporarily change the parity of at most one node for this check.
For each query of the second type, you must determine if the subtree can be made to have the same parity by changing at most one node's value.

Input Format
The first line contains two integers, N and q, representing the number of vertices in the tree and the number of queries.

The next N-1 lines each contain two integers u and v, representing an edge between vertices u and v.

The following line contains N space-separated integers representing the value assigned to each vertex.

The next q lines describe the queries, where each query is in one of the following forms: 1 i x updates the value of vertex i to x, and 2 i processes or retrieves information related to vertex i.

Output Format
For each query of the second type, output "YES" (without quotes) if all the vertices in the subtree of ith vertex can have the same parity and "NO" (without quotes) otherwise.

Constraints
1 <= N  <= 2*10^5

1 <= a[i] <= 10^9

1 <= q <= 2*10^5

1 <= i <= N

1 <= x <= 10^9

Sample Testcase 0
Testcase Input
5 5
1 2
1 3
3 4
3 5
2 9 3 4 6
2 1
2 2
2 3
1 3 10
2 3 
Testcase Output

NO
YES
YES
YES
Explanation
Vertex 1 has 3 even and 2 odd nodes in its subtree and its impossible to make all the nodes of same parity so the answer is NO. 
Vertex 2 has only 1 odd node, so the answer is YES.
We can change Vertex 3 to some even number and thus all vertices in its subtree will be even, so the answer is YES.
After update, vertex 1 has 4 even and 1 odd node. On changing the parity of node 2 to even the whole subtree of vertex 1 becomes even, so the answer is YES.
Sample Testcase 1
Testcase Input
4 3
1 2
2 3
3 4
33 7 4 2
2 1
1 2 10
2 1 
Testcase Output
NO
YES

Explanation
Initially vertex 1 has 2 even and 2 odd nodes, changing at most 1 node still doesn’t make all of the vertices of its subtree of same parity, so the answer is NO. 
After updating the value of node 2 from 7 to 10 in type 1 query, node 1 has now 3 even and 1 odd node. Thus by considering the additional operation we can change the parity of node 1 to be even and now all the nodes are of same parity. So the answer is YES.
Companies
Amazon
Airbnb
Meesho
Topics
Binary Tree
DFS
BFS
Recursion
Tree

'''
import sys
sys.setrecursionlimit(1 << 25)

def input():
    return sys.stdin.readline()

# DFS to flatten the tree and record entry/exit times
def dfs(u, parent):
    nonlocal time
    in_time[u] = time
    flat[time] = u
    time += 1
    for v in tree[u]:
        if v != parent:
            dfs(v, u)
    out_time[u] = time - 1

# Segment Tree for parity counts
class SegmentTree:
    def __init__(self, data):
        self.N = len(data)
        self.tree = [0] * (4 * self.N)
        self.build(data, 0, self.N - 1, 1)

    def build(self, data, l, r, node):
        if l == r:
            self.tree[node] = data[l] % 2  # 0 for even, 1 for odd
        else:
            mid = (l + r) // 2
            self.build(data, l, mid, 2 * node)
            self.build(data, mid + 1, r, 2 * node + 1)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def update(self, idx, val, l, r, node):
        if l == r:
            self.tree[node] = val % 2
        else:
            mid = (l + r) // 2
            if idx <= mid:
                self.update(idx, val, l, mid, 2 * node)
            else:
                self.update(idx, val, mid + 1, r, 2 * node + 1)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def query(self, ql, qr, l, r, node):
        if qr < l or ql > r:
            return 0
        if ql <= l and r <= qr:
            return self.tree[node]
        mid = (l + r) // 2
        return self.query(ql, qr, l, mid, 2 * node) + self.query(ql, qr, mid + 1, r, 2 * node + 1)

# Main logic
N, q = map(int, input().split())
tree = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)

a = list(map(int, input().split()))
in_time = [0] * (N + 1)
out_time = [0] * (N + 1)
flat = [0] * N
time = 0

dfs(1, -1)

# Build segment tree with parity values
parity_data = [a[flat[i] - 1] for i in range(N)]
seg_tree = SegmentTree(parity_data)

for _ in range(q):
    parts = input().split()
    if parts[0] == '1':
        i = int(parts[1])
        x = int(parts[2])
        a[i - 1] = x
        seg_tree.update(in_time[i], x, 0, N - 1, 1)
    else:
        i = int(parts[1])
        total_nodes = out_time[i] - in_time[i] + 1
        odd_count = seg_tree.query(in_time[i], out_time[i], 0, N - 1, 1)
        even_count = total_nodes - odd_count
        print("YES" if odd_count <= 1 or even_count <= 1 else "NO")

