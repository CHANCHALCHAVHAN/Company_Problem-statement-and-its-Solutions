/*
Problem Statement
You are given a string s consisting of uppercase and lowercase English letters. The string s may have repeated characters, and your task is to identify the longest substring of s that meets the following criteria:

The substring must contain distinct characters (no repeated characters within the substring).

The absolute difference between the ASCII values of the first and last character of the substring must be exactly D.

Your objective is to determine the length of the longest substring of s that:

Contains only distinct characters.

Has the absolute difference between the ASCII values of its first and last character equal to D.

If there are no such substrings, the output should be 0.

Input Format
The first line contains two integers N and D (1 ≤ N ≤ 1000, 1 ≤ D ≤ 100).

The second line contains the string S (consisting only of lowercase English letters).

 
Output Format
Output a single integer: the length of the longest substring that satisfies the given conditions, or -1 if no such substring exists.

Constraints
1 ≤ N ≤ 1000

1 ≤ D ≤ 100

The string S consists only of lowercase English letters.

Sample Testcase 0
Testcase Input
4 2
abcd
Testcase Output
3
Explanation
Substring "abc" → |a - c| = 2, length = 3 
Answer: 3

Sample Testcase 1
Testcase Input
6 3
abcdfg
Testcase Output
4
Explanation
Substring "abcd" → distinct, |a - d| = 3, length = 4 
Answer: 4

Companies
Topics
String Manipulation
Sliding Window
Substring
ASCII
Data Structure
Strings
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    string s;
    cin >> s;

    int maxLen = -1;

    // Try all substrings starting at i
    for (int i = 0; i < N; i++) {
        vector<bool> used(26, false);

        for (int j = i; j < N; j++) {
            int idx = s[j] - 'a';

            // If character repeats, stop expanding
            if (used[idx]) break;

            used[idx] = true;

            // Check ASCII difference between first and last character
            if (abs(s[i] - s[j]) == D) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    // Print result (-1 if no valid substring)
    cout << maxLen << endl;

    return 0;
}
