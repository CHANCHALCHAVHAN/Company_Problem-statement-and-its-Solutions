/*************************************************************************************************************************************************************************************************************************************************************************************
Problem Statement
An electronic shop is running a limited-time combo offer: if a customer buys exactly K types of devices in one bill such that the total value of the bill lies between L and R (inclusive), they get a 10% discount.

You are given a list of N devices, each with a type (as a string) and a price (an integer). Each type is unique per device. A customer can buy at most one device per type.

Your task is to find the maximum number of different valid combos the shop can create using exactly K different types of devices such that their total price lies within the given range [L, R].

Input Format
First line contains four integers: N K L R

Next N lines contains a string deviceType and an integer price

Output Format
Print the number of valid combo

Constraints
1 ≤ N ≤ 20

1 ≤ K ≤ N

1 ≤ L ≤ R ≤ 10^6

1 ≤ price ≤ 10^5

Sample Testcase 0
Testcase Input
4 2 1000 1200
tv 900
soundbar 950
bluetooth 850
earbuds 870
Testcase Output
0
Explanation
All possible 2-device combos:


tv + soundbar = 1850 Invalid


tv + bluetooth = 1750 Invalid


tv + earbuds = 1770 Invalid


soundbar + bluetooth = 1800 Invalid


soundbar + earbuds = 1820 Invalid


bluetooth + earbuds = 1720 Invalid


None are in [1000, 1200] →  0 valid combos

Sample Testcase 1
Testcase Input
5 3 1000 1500
laptop 700
monitor 500
keyboard 300
mouse 200
printer 400
Testcase Output
8
Explanation
All valid 3-device combinations whose total cost is between 1000 and 1500:


laptop + monitor + keyboard = 1500 Valid


laptop + monitor + mouse = 1400 Valid


laptop + keyboard + mouse = 1200 Valid


laptop + keyboard + printer = 1400 Valid


laptop + mouse + printer = 1300 Valid


monitor + keyboard + mouse = 1000 Valid


monitor + keyboard + printer = 1200 Valid


monitor + mouse + printer = 1100 Valid


Total: 8 valid combos

Companies
Topics
Combinatorics
Backtracking
Subsets
Brute-force
Array
Data Structure
Backtracking

*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countValidCombos(int idx, int selected, int totalPrice, int K, int L, int R, const vector<int>& prices) {
    if (selected == K) {
        return (totalPrice >= L && totalPrice <= R) ? 1 : 0;
    }
    if (idx >= prices.size()) return 0;

    // Include current device
    int include = countValidCombos(idx + 1, selected + 1, totalPrice + prices[idx], K, L, R, prices);
    // Exclude current device
    int exclude = countValidCombos(idx + 1, selected, totalPrice, K, L, R, prices);

    return include + exclude;
}

int main() {
    int N, K, L, R;
    cin >> N >> K >> L >> R;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        string type;
        int price;
        cin >> type >> price;
        prices[i] = price;
    }

    int result = countValidCombos(0, 0, 0, K, L, R, prices);
    cout << result << endl;

    return 0;
}
