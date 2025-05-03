'''
Problem Statement
You are given a tree with N nodes, numbered from 1 to N. Each edge in the tree has a weight associated with it. Additionally, each node has an initial value.

You need to process Q queries of the following types:

Update Node: Change the value of a node to a new given value.
Update Edge: Change the weight of a specific edge.
Weighted Path Sum: Given two nodes u and v, compute the sum of all node values along the path from u to v, where each node’s value is multiplied by the minimum edge weight encountered along the path.
Input Format
The first line contains two integers N (number of nodes) and Q (number of queries).

The next line contains N space-separated integers, where the i-th integer represents the initial value of node i.

The next N-1 lines contain three integers u, v, w, representing an edge between nodes u and v with weight w.

The next Q lines contain queries in one of the following formats:

1 x val → Update node x’s value to val.
2 u v w → Update the weight of the edge between u and v to w.
3 u v → Compute the weighted path sum between nodes u and v.
Output Format
For each query of type 3 u v, print the weighted path sum between u and v.

Constraints
2 <= N <= 10^4

1 <= Q <= 10^3

1 <= nodeValue[i] <= 10^7

1 <= u, v <= N

1 <= w <= 10^6

The input graph is always a tree (i.e., connected and has no cycles).

The root of the tree is node 1.

Sample Testcase 0
Testcase Input
3 4
6 8 3
1 2 5
2 3 4
1 2 3
3 1 3
2 3 2 6
3 1 3
Testcase Output
48
60
Explanation

Initial node values:

Node 1 → 6, Node 2 → 8, Node 3 → 3



Edges:

1 - 2 with weight 5

2 - 3 with weight 4




Queries Execution:



Update Node 2’s value to 3 → New values: [6, 3, 3]

Compute Weighted Path Sum (1 → 3)

Path: 1 → 2 → 3, Min edge weight = 4

Calculation: (6×4) + (3×4) + (3×4) = 48

Output: 48



Update Edge (2 - 3) weight to 6 → New edge weights: [5, 6]

Compute Weighted Path Sum (1 → 3)

Path: 1 → 2 → 3, Min edge weight = 5

Calculation: (6×5) + (3×5) + (3×5) = 60

Output: 60




 
Sample Testcase 1
Testcase Input
5 5
10 20 30 40 50
1 2 5
2 4 1
2 5 3
1 3 2
3 1 5
1 3 25
3 3 4
2 2 4 3
3 3 5
Testcase Output
240
95
210
Explanation

Initial node values:

Node 1 → 10, Node 2 → 20, Node 3 → 30, Node 4 → 40, Node 5 → 50



Edges:

1 - 2 with weight 5

2 - 4 with weight 1

2 - 5 with weight 3

1 - 3 with weight 2




        1 (10)
        /  \
    5 /    \ 2
     /       \
    2 (20)  3 (30)
   /   \


 1/    \3
  /      \
 4 (40)  5 (50)



Queries Execution:



Update Node 3’s value to 25 → New values: [10, 20, 25, 40, 50]

Compute Weighted Path Sum (3 → 4)

Path: 3 → 1 → 2 → 4, Min edge weight = 1

Calculation: (25×1) + (10×1) + (20×1) + (40×1) = 95

Output: 95



Update Edge (2 - 4) weight to 3 → New edge weights: [5, 3, 3, 2]

Compute Weighted Path Sum (3 → 5)

Path: 3 → 1 → 2 → 5, Min edge weight = 2

Calculation: (25×2) + (10×2) + (20×2) + (50×2) = 210

Output: 210

'''
import sys
sys.setrecursionlimit(10**6)

class SegmentTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (4 * size)
        self.lazy = [0] * (4 * size)

    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = (start + end) // 2
            self.build(arr, 2 * node + 1, start, mid)
            self.build(arr, 2 * node + 2, mid + 1, end)
            self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]

    def update(self, node, start, end, idx, value):
        if start == end:
            self.tree[node] = value
        else:
            mid = (start + end) // 2
            if idx <= mid:
                self.update(2 * node + 1, start, mid, idx, value)
            else:
                self.update(2 * node + 2, mid + 1, end, idx, value)
            self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]

    def query(self, node, start, end, l, r):
        if start > r or end < l:
            return 0
        if l <= start and end <= r:
            return self.tree[node]
        mid = (start + end) // 2
        left_sum = self.query(2 * node + 1, start, mid, l, r)
        right_sum = self.query(2 * node + 2, mid + 1, end, l, r)
        return left_sum + right_sum

class Tree:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n + 1)]
        self.value = [0] * (n + 1)
        self.parent = [-1] * (n + 1)
        self.depth = [0] * (n + 1)
        self.subtree_size = [0] * (n + 1)
        self.heavy = [-1] * (n + 1)
        self.head = [0] * (n + 1)
        self.pos = [0] * (n + 1)
        self.edge_weight = {}
        self.seg_tree = None
        self.cur_pos = 0

    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))
        self.edge_weight[(u, v)] = w
        self.edge_weight[(v, u)] = w

    def dfs(self, v, p, d):
        self.parent[v] = p
        self.depth[v] = d
        self.subtree_size[v] = 1
        max_size, heavy_child = 0, -1
        for u, w in self.adj[v]:
            if u == p: continue
            self.dfs(u, v, d + 1)
            self.subtree_size[v] += self.subtree_size[u]
            if self.subtree_size[u] > max_size:
                max_size = self.subtree_size[u]
                heavy_child = u
        self.heavy[v] = heavy_child

    def decompose(self, v, h):
        self.head[v] = h
        self.pos[v] = self.cur_pos
        self.cur_pos += 1
        if self.heavy[v] != -1:
            self.decompose(self.heavy[v], h)
        for u, w in self.adj[v]:
            if u == self.parent[v] or u == self.heavy[v]: continue
            self.decompose(u, u)

    def update_value(self, x, val):
        self.value[x] = val
        self.seg_tree.update(0, 0, self.n - 1, self.pos[x], val)

    def query_path(self, u, v):
        res, min_edge = 0, float('inf')
        while self.head[u] != self.head[v]:
            if self.depth[self.head[u]] < self.depth[self.head[v]]:
                u, v = v, u
            min_edge = min(min_edge, self.edge_weight[(self.parent[self.head[u]], self.head[u])])
            res += self.seg_tree.query(0, 0, self.n - 1, self.pos[self.head[u]], self.pos[u])
            u = self.parent[self.head[u]]
        if self.pos[u] > self.pos[v]:
            u, v = v, u
        res += self.seg_tree.query(0, 0, self.n - 1, self.pos[u], self.pos[v])
        return res * min_edge

    def preprocess(self):
        self.dfs(1, -1, 0)
        self.decompose(1, 1)
        arr = [self.value[i] for i in range(1, self.n + 1)]
        self.seg_tree = SegmentTree(self.n)
        self.seg_tree.build(arr, 0, 0, self.n - 1)

n, q = map(int, input().split())
tree = Tree(n)
values = list(map(int, input().split()))
for i in range(1, n + 1):
    tree.value[i] = values[i - 1]

for _ in range(n - 1):
    u, v, w = map(int, input().split())
    tree.add_edge(u, v, w)

tree.preprocess()

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        tree.update_value(query[1], query[2])
    elif query[0] == 2:
        tree.edge_weight[(query[1], query[2])] = query[3]
        tree.edge_weight[(query[2], query[1])] = query[3]
    elif query[0] == 3:
        print(tree.query_path(query[1], query[2]))
