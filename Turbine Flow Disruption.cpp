/***
Problem Statement
In a futuristic hydroelectric facility, N turbines are aligned in a straight pipeline, each capable of controlling water flow by a certain value. Each turbine has an initial flow intensity.

Periodically, maintenance systems issue flow update signals to a range of turbines, increasing or decreasing their flow intensities. However, due to signal synchronization delays, updates do not apply immediately—they are deferred and applied in bulk at once when explicitly triggered.

Additionally, engineers must query the total flow across a specific turbine range after any number of deferred updates.

You are tasked with building a system to efficiently:

Handle deferred updates over a range.

Apply updates in constant time using lazy propagation.

Process range sum queries efficiently.

Input Format
First line contains two integers N and Q — number of turbines and number of operations respectively.


Second line contains N space-separated integers, where the i-th integer is the initial flow intensity of turbine i.


Next Q lines describe operations. Each operation can be of two types:


1 L R V — Defer an update by adding value V to turbines in range [L, R] (1-based index).


2 L R — Apply all deferred updates and return the sum of flow intensities from index L to R.

Output Format
For every type 2 operation, print the total flow of the range on a new line.

Constraints
1 ≤ N, Q ≤ 2 * 10^5


-10^6 ≤ flow intensity values ≤ 10^6


1 ≤ L ≤ R ≤ N


-10^5 ≤ V ≤ 10^5

Sample Testcase 0
Testcase Input
5 5
3 1 4 1 5
1 1 3 2
2 1 3
1 2 5 -1
2 2 4
2 1 5
Testcase Output
14
7
16
Explanation
Initial Array: [3, 1, 4, 1, 5] (5 turbines).


Operation 1: 1 1 3 2


If: Defer adding +2 to turbines 1 to 3.


Then: Mark update, array unchanged: [3, 1, 4, 1, 5].


Operation 2: 2 1 3


If: Query sum of turbines 1 to 3.

Then: Apply +2 to turbines 1 to 3. Array: [5, 3, 6, 1, 5]. Sum = 5 + 3 + 6 = 14.


Output: 14.


Operation 3: 1 2 5 -1


If: Defer adding -1 to turbines 2 to 5.


Then: Mark update, array unchanged: [5, 3, 6, 1, 5].


Operation 4: 2 2 4


If: Query sum of turbines 2 to 4.


Then: Apply -1 to turbines 2 to 5. Array: [5, 2, 5, 0, 4]. Sum = 2 + 5 + 0 = 7.


Output: 7.


Operation 5: 2 1 5


If: Query sum of turbines 1 to 5.


Then: No new updates. Array: [5, 2, 5, 0, 4]. Sum = 5 + 2 + 5 + 0 + 4 = 16.


Output: 16.

Sample Testcase 1
Testcase Input
6 6
10 20 30 40 50 60
1 2 5 5
2 1 6
1 3 6 -10
2 2 4
2 5 6
2 1 3
Testcase Output
230
85
95
60
Explanation
Initial Array: [10, 20, 30, 40, 50, 60] (6 turbines).


Operation 1: 1 2 5 5


If: Defer adding +5 to turbines 2 to 5.


Then: Mark update but don’t change array yet. Array stays [10, 20, 30, 40, 50, 60].


Operation 2: 2 1 6


If: Query sum of turbines 1 to 6.


Then: Apply deferred update (add +5 to turbines 2 to 5).


Array becomes [10, 25, 35, 45, 55, 60].


Sum = 10 + 25 + 35 + 45 + 55 + 60 = 230.


Output: 230.


Operation 3: 1 3 6 -10


If: Defer adding -10 to turbines 3 to 6.


Then: Mark update but don’t change array yet. Array stays [10, 25, 35, 45, 55, 60].


Operation 4: 2 2 4


If: Query sum of turbines 2 to 4.


Then: Apply deferred update (add -10 to turbines 3 to 6).


Array becomes [10, 25, 25, 35, 45, 50].


Sum = 25 + 25 + 35 = 85.


Output: 85.


Operation 5: 2 5 6


If: Query sum of turbines 5 to 6.


Then: No new updates. Use current array [10, 25, 25, 35, 45, 50].


Sum = 45 + 50 = 95.


Output: 95.


Operation 6: 2 1 3


If: Query sum of turbines 1 to 3.


Then: No new updates. Use current array [10, 25, 25, 35, 45, 50].


Sum = 10 + 25 + 25 = 60.


Output: 60.


 

Companies
Juspay
Amazon
Meesho
Topics
lazy-propagation
Segment Trees with Lazy Propagation
*/


#code
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long tree[4 * MAXN], lazy[4 * MAXN];

void build(vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) return;

    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long queryRange(int node, int start, int end, int l, int r) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) return 0;

    if (start >= l && end <= r) return tree[node];

    int mid = (start + end) / 2;
    long long p1 = queryRange(2 * node, start, mid, l, r);
    long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    build(arr, 1, 0, N - 1);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R, V;
            cin >> L >> R >> V;
            updateRange(1, 0, N - 1, L - 1, R - 1, V);
        } else {
            int L, R;
            cin >> L >> R;
            cout << queryRange(1, 0, N - 1, L - 1, R - 1) << '\n';
        }
    }

    return 0;
}
