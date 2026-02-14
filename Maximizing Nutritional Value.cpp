/*
Problem Statement
Alice goes to a grocery store to buy fruits for her smoothie shop. 

There are n varieties of fruits numbered from 1 to n. The price of the ith fruit is the price[i], and the nutritional value of it is a nutrition[i]. Alice also has k discount coupons, and each coupon can only be used on one item. By using a discount coupon, the price of any variety of fruit can be reduced to half of its original value (floor value). 

Alice only has m amount of money, and she wants to buy fruits to maximize their total nutritional value.

Find the maximum nutritional value Alice can get.

Note: Alice can only buy at most one unit of each fruit.

Input Format
The first line contains three space-separated integers, n, m, and k.

The next line contains n space-separated integers denoting the array price[i].

The next line contains n space-separated integers denoting the array nutrition[i].

Output Format
Print a single integer denoting the maximum nutritional value Alice can get, as described in the problem statement.

Constraints
1 ≤  n, m ≤  10^3

1 ≤  k ≤  10

1 ≤  price[i] ≤ 10^3

1 ≤  nutrition[i] ≤ 10^3

Sample Testcase 0
Testcase Input
4 4 1 
8 10 12 14
9 7 6 100
Testcase Output
9
Explanation
Alice has 4 varieties of fruits and 4 units of money. She also has 1 discount coupon. 

Alice can apply a discount on the first fruit, which she can get at (8/2) = 4 dollars. The nutritional value that she will get will be 9. 

This is the maximum nutritional value she can get by using 4 dollars using a discount coupon.

Sample Testcase 1
Testcase Input
4 4 1
2 4 5 7
20 17 15 10
Testcase Output
37
Explanation
Alice has 4 varieties of fruits and 4 units of money. She also has 1 discount coupon.

She could select fruit numbers 1 and 2 and apply a discount on the second fruit. This way, the total cost incurred would be 2 + (4/2): 4, and the nutritional value would be 20 + 17 = 37. 

This is the maximum possible nutritional value that Alice can get after using 4 dollars and using 1 discount coupon.

Companies
Salesforce
Goldman Sachs
Meesho
Topics
Recursion
Array
Dynamic Programming

*/
#include <bits/stdc++.h>
using namespace std;

int maximizeNutritionalValue(int n, int m, int k, vector<int> &price, vector<int> &nutrition) {
    
    // dp[money][coupons] = max nutrition
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        int p = price[i];
        int half = p / 2;
        int nut = nutrition[i];

        // reverse iteration to avoid overwriting
        for (int money = m; money >= 0; money--) {
            for (int c = k; c >= 0; c--) {

                // buy without coupon
                if (money >= p) {
                    dp[money][c] = max(dp[money][c],
                                       dp[money - p][c] + nut);
                }

                // buy with coupon
                if (c > 0 && money >= half) {
                    dp[money][c] = max(dp[money][c],
                                       dp[money - half][c - 1] + nut);
                }
            }
        }
    }

    int ans = 0;
    for (int money = 0; money <= m; money++) {
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[money][c]);
        }
    }
    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> price(n), nutrition(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> nutrition[i];

    cout << maximizeNutritionalValue(n, m, k, price, nutrition);
    return 0;
}


