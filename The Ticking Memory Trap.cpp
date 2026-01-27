/*
Problem Statement
You are managing a highly sensitive and time-critical memory vault in a top-secret research facility. Each memory slot holds a value, and the entire array of memory slots can be modified or queried.

The vault has a special property — it supports versioned states of the memory. Every time a modification (update) is made, a new version is created (without destroying the previous one).

You are given:

An initial array of n memory slots.

A series of q operations — each either:

Updates a slot in a specific version (creating a new version).

Queries the sum in a range in a specific version.

All memory versions are immutable once created — you can only update on top of an existing version to make a new one.

Your task is to support these operations efficiently, handling up to 10^5 operations.

Input Format
First line contains two integers n and q, the size of the array and the number of queries respectively.

Second line contains n integers, where the i-th integer represents the initial value at index i in the array.

Each of the next q lines contains a query in one of the following two formats:

1 v i x — Create a new version by updating index i (1-based) to value x in version v.

2 v l r — In version v, query the sum of elements from index l to r (both inclusive, 1-based).

Output Format
For each type-2 query, print a single integer

Constraints
1 ≤ n ≤ 10^5

1 ≤ q ≤ 10^5

-10^6 ≤ a[i], x ≤ 10^6

1 ≤ v ≤ current version count (initial version is 1)

1 ≤ i, l, r ≤ n

Sample Testcase 0
Testcase Input
4 7
3 6 9 12
2 1 2 4
1 1 2 10
1 2 3 5
2 3 1 3
2 2 2 4
2 1 1 2
2 1 1 4
Testcase Output
27
18
31
9
30
Explanation

Initial Array (Version 1): [3, 6, 9, 12]




Query: 2 1 2 4 → Version 1, sum from index 2 to 4
   6 + 9 + 12 = 27


Update: 1 1 2 10 → Modify Version 1 at index 2 to 10 → New Version 2
   Version 2: [3, 10, 9, 12]


Update: 1 2 3 5 → Modify Version 2 at index 3 to 5 → New Version 3
   Version 3: [3, 10, 5, 12]


Query: 2 3 1 3 → Version 3, sum from index 1 to 3
   3 + 10 + 5 = 18


Query: 2 2 2 4 → Version 2, sum from index 2 to 4
  10 + 9 + 12 = 31


Query: 2 1 1 2 → Version 1, sum from index 1 to 2
   3 + 6 = 9


Query: 2 1 1 4 → Version 1, sum from index 1 to 4
   3 + 6 + 9 + 12 = 30



 Final Output: 27, 18, 31, 9, 30

Sample Testcase 1
Testcase Input
5 6
1 2 3 4 5
2 1 1 5
1 1 3 10
2 2 1 5
1 2 2 20
2 3 1 3
2 1 2 4
Testcase Output
15
22
31
9
Explanation

Initial version 1: [1, 2, 3, 4, 5]


Query sum(1, 5) → 15


Update index 3 to 10 in version 1 → creates version 2: [1, 2, 10, 4, 5]


Query sum(1, 5) in version 2 → 22


Update index 2 to 20 in version 2 → creates version 3: [1, 20, 10, 4, 5]


Query sum(1, 3) in version 3 → 1+20+10 = 31


Query sum(2, 4) in version 1 → 2+3+4 = 9

Companies
Juspay
jp morgan
Adobe
Topics
segment-tree
Data Structures & Algorithms
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    Node* left;
    Node* right;

    Node(long long s = 0, Node* l = nullptr, Node* r = nullptr)
        : sum(s), left(l), right(r) {}
};

Node* build(int l, int r, const vector<int>& arr) {
    if (l == r) {
        return new Node(arr[l]);
    }
    int mid = (l + r) / 2;
    Node* left = build(l, mid, arr);
    Node* right = build(mid + 1, r, arr);
    return new Node(left->sum + right->sum, left, right);
}

Node* update(Node* prev, int l, int r, int idx, int val) {
    if (l == r) {
        return new Node(val);
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        Node* left = update(prev->left, l, mid, idx, val);
        return new Node(left->sum + prev->right->sum, left, prev->right);
    } else {
        Node* right = update(prev->right, mid + 1, r, idx, val);
        return new Node(prev->left->sum + right->sum, prev->left, right);
    }
}

long long query(Node* node, int l, int r, int ql, int qr) {
    if (!node || qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return node->sum;
    int mid = (l + r) / 2;
    return query(node->left, l, mid, ql, qr) +
           query(node->right, mid + 1, r, ql, qr);
}

void process_queries(
    int n,
    int q,
    vector<int>& initial_array,
    vector<tuple<int, int, int, int>>& queries,
    vector<int>& results
) {
    vector<Node*> versions;
    versions.reserve(q + 1);

    // Version 1
    versions.push_back(build(0, n - 1, initial_array));

    for (auto& qu : queries) {
        int type, v, x, y;
        tie(type, v, x, y) = qu;
        v--;  // convert to 0-based version index

        if (type == 1) {
            int idx = x - 1;
            int val = y;
            Node* newVersion = update(versions[v], 0, n - 1, idx, val);
            versions.push_back(newVersion);
        } else {
            int l = x - 1;
            int r = y - 1;
            long long ans = query(versions[v], 0, n - 1, l, r);
            results.push_back(ans);
        }
    }
}
