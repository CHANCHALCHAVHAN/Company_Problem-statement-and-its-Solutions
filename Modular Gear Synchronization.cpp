/*
Problem Statement
In a giant underground mechanical vault, N gears rotate in isolation. Each gear completes one full rotation after a certain number of seconds. However, these gears are defective — each gear only rotates after every multiple of its delay time and skips its next tick if it coincides with any of its forbidden ticks.

For each gear i:

It rotates every a_i seconds.

However, it must skip any time t such that t % f_i == 0.

Your task is to determine the earliest time T > 0 when all gears rotate simultaneously.

If there is no such possible time where all gears can rotate together (i.e., all constraints cannot be satisfied), print -1.

Input Format
First line: Integer N — the number of gears (1 ≤ N ≤ 10^5)

Next N lines: Two integers per line — `a_i` and `f_i` for each gear.

Output Format
A single integer.

Constraints
1 ≤ N ≤ 10^5

1 ≤ a_i, f_i ≤ 10^9

Sample Testcase 0
Testcase Input
3
4 6
6 9
8 10
Testcase Output
-1
Explanation

LCM of (4, 6, 8) = 24


Check if 24 is divisible by any forbidden ticks (6, 9, 10):



24 % 6 == 0 → forbidden, so no valid T = 24



Since 24 is divisible by forbidden tick 6, and all multiples of 24 will also be divisible by 6, answer is -1.

Sample Testcase 1
Testcase Input
2
3 2
5 4
Testcase Output
15
Explanation

LCM of (3, 5) = 15


Check if 15 divisible by forbidden ticks (2, 4):



15 % 2 != 0


15 % 4 != 0



So T = 15 is valid, as it meets all gear requirements and is not forbidden.

Companies
Topics
Basic Arithmetic
Number Theory
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a , long long b){
    return (a / __gcd(a,b))*b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<long long , long long>> gears(n);
    long long ans =1;
    for (int i = 0; i < n; ++i) {
        cin >> gears[i].first >> gears[i].second;
        ans= lcm(gears[i].first , ans);
    }
    for(int i =0 ; i<n ; i++){
        if(ans % gears[i].second == 0){
            cout<< -1;
            return 0;
        }
    }


    cout << ans;
    return 0 ;
}
