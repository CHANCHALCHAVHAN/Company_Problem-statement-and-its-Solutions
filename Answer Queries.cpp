/*
Problem Statement
You were learning the array data structure, till your friend challenged you with a problem. Given an array of queries of positive integers between 1 and k, you have to process all queries[i]  according to the following rules:

In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P.
Notice that the position of queries[i] in the permutation P is the result for queries[i].
Print an array containing the result for the given queries.

 

Input Format
The first line contains m, the initial permutation P = [1,2,3,….,m]

The following line contains q, the number of queries

The following line contains q numbers denoting the ith query, starting from 0 to q-1.

Output Format
Print the result of all queries, in a space-separated single-line fashion.

Constraints
1<=m<=5*104

1<=q<=m

1<=queries[i]<=m

Sample Testcase 0
Testcase Input
4
3 
3 1 2 


Testcase Output
2 1 2 

Explanation
For q=0: query =3, P=[1,2,3,4,5], position of 3 in P is index 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5].
For q=1: query=1, P=[3,1,2,4,5], position of 1 in P is index 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For q=2: query=2, P=[1,3,2,4,5], position of 2 in P is index 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5].

Sample Testcase 1
Testcase Input
3
3
2 2 1 

Testcase Output
1 0 1

Explanation
For q=0: query =2, P=[1,2,3], position of 2 in P is index 1, then we move 2 to the beginning of P resulting in P=[2,1,3].
For q=1: query=2, P=[2,1,3], position of 2 in P is index 0, then we move 2 to the beginning of P resulting in P=[2,1,3]. 
For q=2: query=1, P=[2,1,3], position of 1 in P is index 1, then we move 1 to the beginning of P resulting in P=[1,2,3].

Companies
Adobe
IBM
Visa
Twitter
Yahoo
Indeed
Pinterest
Topics
Array
Range Queries
Linked List
Binary Tree
Tree


*/

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, int val){
        for(; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx){
        int r = 0;
        for(; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
    // sum on [l..r]
    int range_sum(int l, int r){
        if(l>r) return 0;
        return sum(r) - sum(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    if(!(cin >> m)) return 0;
    int q;
    cin >> q;
    vector<int> queries(q);
    for(int i=0;i<q;i++) cin >> queries[i];

    // We'll map each value 1..m to a position in [1 .. m+q]
    // Initial positions: pos[val] = q + val
    // New front positions will be q, q-1, q-2, ...
    int size = m + q + 5;
    Fenwick fw(size);
    vector<int> pos(m+1);
    for(int val = 1; val <= m; ++val){
        pos[val] = q + val;        // positions are 1-based
        fw.add(pos[val], 1);       // mark presence
    }

    int nextFront = q; // next available front position (decreases)
    bool firstOut = true;
    for(int i=0;i<q;i++){
        int x = queries[i];
        // number of elements before pos[x] is the answer (0-based index)
        int answer = fw.sum(pos[x] - 1);
        if(!firstOut) cout << ' ';
        firstOut = false;
        cout << answer;

        // move x to front
        fw.add(pos[x], -1);    // remove from old pos
        pos[x] = nextFront;    // assign new front pos
        fw.add(pos[x], 1);     // add at new pos
        nextFront--;           // next free front slot
    }
    cout << '\n';
    return 0;
}
