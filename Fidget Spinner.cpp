/*

Problem Statement
You are given a fidget spinner with numbered leaves from 1 to 6, and you need to find the number of possible ways to construct a sum N using the numbers on the leaves. You can spin the spinner in either direction and repeatedly add the number pointed at by the spinner any number of times.

Input Format
The first line of input contains an integer N representing the sum you need to construct.

Output Format
Display the number of ways to construct the sum N, return it in modulo 10^9+7.

Constraints
1<=N<=10^6

Sample Testcase 0
Testcase Input
3
Testcase Output
4
Explanation
You want to find the different ways to construct a sum of 3.
 Use 1 three times: 1+1+1=3
 Use 1 once, and then use 2: 1+2=3
 Use 2 once, and then use 1: 2+1=3
 Use 3 once: 3=3.
So there are 4 ways to construct 3.

Sample Testcase 1
Testcase Input
2
Testcase Output
2
Explanation
You want to find the different ways to construct a sum of 2.
 Use 1 twice: 1+1=2
 Use 2 once:  2=2
So there are 2  ways to form 2.

Companies
Visa
Topics
Math
Dynamic Programming
Recursion
Recursion

*/
#include <iostream>
#define MOD 1000000007
using namespace std;

int ways(int sum) {
    long long dp[sum + 1];
    
    dp[0] = 1;

    for (int i = 1; i <= sum; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[sum];
}

int main() {
    int n;
    cin >> n;
    cout << ways(n) << endl;
    return 0;
}
