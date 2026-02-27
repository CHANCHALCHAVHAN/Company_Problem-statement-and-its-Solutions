/*
Problem Statement
You are given an integer array books representing the thicknesses of a row of books on a shelf. You are also given two integers, maxBooks and k. You must pack the books into boxes in the exact same order they appear in the array.

Each box you use has a capacity limit, meaning it can hold at most maxBooks books.

The cost to ship a single box is equal to the maximum thickness of any book inside that box. The total shipping cost is the sum of the costs of all the boxes used.

Before you start packing, you are allowed to permanently remove at most k books from the shelf to save on shipping costs. The remaining books must be packed in their original relative order.

Return the minimum possible total shipping cost to pack the remaining books.

Input Format
The first line contains three space-separated integers n, maxBooks, and k here, n represents the total number of books, maxBooks represents the maximum number of books a single box can hold, k represents the maximum number of books you can remove.

The second line contains n space-separated integers representing the thickness of each book in the books array.

Output Format
A single integer representing the minimum possible total shipping cost.

Constraints
1 <= n <= 10^3

1 <= books[i] <= 10^4

1 <= maxBooks <= 100

0 <= k <= 100

Sample Testcase 0
Testcase Input
6 3 1
4 1 3 2 8 5
Testcase Output
9
Explanation
You are given 6 books. A box can hold up to 3 books, and you can remove 1 book.


We can remove the book with thickness 8.


The remaining books are [4, 1, 3, 2, 5].


We can pack the books into 2 boxes:
- Box 1: contains [4, 1, 3]. The thickest book is 4, so the cost is 4.
- Box 2: contains [2, 5]. The thickest book is 5, so the cost is 5.


Total shipping cost = 4 + 5 = 9.

Sample Testcase 1
Testcase Input
3 1 2
10 20 30
Testcase Output
10
Explanation
You are given 3 books. A box can hold only 1 book, and you can remove up to 2 books.


We can remove the two thickest books: 20 and 30.


The remaining books are [10].


We pack it into 1 box:
- Box 1: contains [10]. The thickest book is 10, so the cost is 10.


Total shipping cost = 10.

Companies
Topics
Dynamic Programming
Memoization
Partitioning
Array
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, maxBooks, k;
    cin >> n >> maxBooks >> k;
    vector<int> books(n);
    for (int i = 0; i < n; i++) cin >> books[i];

    // dp[i][r] = minimum cost starting from index i with r removals left
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    
    // Base case: no books left → cost = 0
    for (int r = 0; r <= k; r++) dp[n][r] = 0;

    // Fill DP backwards
    for (int i = n - 1; i >= 0; i--) {
        for (int r = 0; r <= k; r++) {
            // Option 1: remove this book
            if (r > 0) {
                dp[i][r] = min(dp[i][r], dp[i + 1][r - 1]);
            }

            // Option 2: pack books into a box
            int maxThickness = 0;
            for (int j = i; j < n && j < i + maxBooks; j++) {
                maxThickness = max(maxThickness, books[j]);
                dp[i][r] = min(dp[i][r], maxThickness + dp[j + 1][r]);
            }
        }
    }

    cout << dp[0][k] << endl;
    return 0;
}
