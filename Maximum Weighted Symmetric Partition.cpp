/*
Problem Statement
You are given a string S of length N consisting of lowercase English letters. Each character C in the string has an associated positive integer weight W(C) (provided as a mapping for all 26 lowercase characters).

You are allowed to partition the string S into one or more non-empty, contiguous substrings such that each substring is a palindrome. Your task is to maximize the total weighted score of the partition, where the score of a palindromic substring is defined as:

score = (length of the palindrome) × (sum of weights of all characters in the substring)

Return the maximum possible score obtainable by any valid palindromic partitioning of S.

Input Format
The first line contains a single integer N representing the length of the string.

The second line contains the string S of length N, consisting of lowercase letters.

The third line contains 26 space-separated integers representing the weight of characters 'A' to 'Z'.

Output Format
Print a single integer representing the maximum weighted score achievable.

Constraints
1 ≤ N ≤ 10^3

1 ≤ weight of each character ≤ 10^4

Sample Testcase 0
Testcase Input
5
aabaa
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
Testcase Output
30
Explanation
Weights for characters:
"aabaa" → 1+1+2+1+1 = 6


Score:
"aabaa": 5 × 6 = 30

Maximum total weight = 30

Sample Testcase 1
Testcase Input
6
abcbda
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
Testcase Output
27
Explanation
You can split the string "abcbda" into palindromic substrings: ["a", "bcb", "d", "a"].


Weights for characters:
- "a" → 1
- "bcb" → 2+3+2 = 7
- "d" → 4
- "a" → 1


Score:
- "a": 1 × 1 = 1
- "bcb": 3 × 7 = 21
- "d": 1 × 4 = 4
- "a": 1 × 1 = 1


Maximum total weight = 1 + 21 + 4 + 1 = 27

Companies
MAQ Software
ZS
Juspay
Topics
palindrome
Memoization
Partitioning
String
Palindromic Structure
Dynamic Programming
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<long long> weight(26);
    for (int i = 0; i < 26; i++) {
        cin >> weight[i];
    }

    // Step 1: Prefix sum of weights
    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + weight[S[i] - 'a'];
    }

    // Step 2: Palindrome DP table
    vector<vector<bool>> isPal(N, vector<bool>(N, false));

    // Single characters
    for (int i = 0; i < N; i++) {
        isPal[i][i] = true;
    }

    // Length >= 2
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            if (S[i] == S[j]) {
                if (len == 2 || isPal[i + 1][j - 1]) {
                    isPal[i][j] = true;
                }
            }
        }
    }

    // Step 3: DP for max score
    vector<long long> dp(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (isPal[j][i]) {
                long long len = i - j + 1;
                long long sumWeights = prefix[i + 1] - prefix[j];
                long long score = len * sumWeights;
                dp[i] = max(dp[i], (j > 0 ? dp[j - 1] : 0) + score);
            }
        }
    }

    cout << dp[N - 1] << "\n";
    return 0;
}
