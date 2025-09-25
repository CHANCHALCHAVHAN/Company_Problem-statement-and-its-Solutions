/*
Problem Statement
You are a toy collector with a budget B dollars. There is a store selling N different types of toys. Each toy type i has:

a price per unit P[i]

a limited stock S[i] (maximum number of units you can buy)

a fun value per unit F[i] (how much fun you get from each unit of that toy)

You want to maximize the total fun value you get by buying some quantity of toys without exceeding your budget B. You can buy any number of units of each toy type from 0 up to its stock limit.

Input Format
First line contains two integers N and B

Next N lines each contain three integers P[i], S[i], and F[i] — price per unit, stock available, and fun value per unit for the ith toy.

Output Format
Print the maximum total fun value you can achieve by buying toys within the budget.

Constraints
1 ≤ N ≤ 100

1 ≤ B ≤ 10,000

1 ≤ P[i],S[i],F[i] ≤ 100

Sample Testcase 0
Testcase Input
3 50
10 3 60
20 2 100
5 5 30
Testcase Output
300
Explanation
Buy 3 units of toy 1: cost = 30, fun = 180


Buy 4 units of toy 3: cost = 20, fun = 120
Total cost = 50 (within budget), total fun = 300 (maximum).

Sample Testcase 1
Testcase Input
4 20
4 5 10
3 3 7
8 1 20
2 4 5
Testcase Output
50
Explanation
One way to get maximum fun:


Buy 1 unit of toy 3: cost 8, fun 20


Buy 3 units of toy 1: cost 12, fun 30
Total cost = 20, total fun = 50


No other combination yields more fun within budget.

Output: 50

Companies
Topics
Dynamic Programming
Knapsack Problem
Optimization
Greedy
Combinatorics
Data Structure
Dynamic Programming

*/

code
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    vector<int> dp(B + 1, 0); // dp[i] = max fun achievable with budget i

    for (int i = 0; i < N; ++i) {
        int price, stock, fun;
        cin >> price >> stock >> fun;

        // Apply bounded knapsack using binary decomposition
        vector<pair<int, int>> items;
        int k = 1;
        while (stock > 0) {
            int take = min(k, stock);
            items.push_back({price * take, fun * take});
            stock -= take;
            k *= 2;
        }

        // Update dp array for each decomposed item
        for (auto [cost, value] : items) {
            for (int j = B; j >= cost; --j) {
                dp[j] = max(dp[j], dp[j - cost] + value);
            }
        }
    }

    cout << dp[B] << endl;
    return 0;
}
