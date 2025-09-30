/*************************************************************************************************************************************************************************************************************************************************************************************
Problem Statement You are given a string str of size N made up of lowercase English letters.
Your task is to find if the maximum length of a subsequence (where the difference between the ASCII values of consecutive characters is exactly 2) is a prime number. If it is, print 1. Otherwise, print 0.
Note: If the maximum length of the subsequence is 1 , print 0.
Input Format The first line of input contains a single string str consisting of lowercase English letters.
Output Format Display 1 if the maximum length of a valid subsequence is a prime number, otherwise Display 0.
Constraints 1 <= |N| <= 10^6
Sample Testcase 0 Testcase Input aad Testcase Output 0 Explanation Only a single length subsequence and the difference of their ASCII value is not exactly 2. Hence the answer is 0.
Sample Testcase 1 Testcase Input ac Testcase Output 1 Explanation The subsequence “ac” follows the condition, i.e., the difference between the two characters is 2.
And the length of the subsequence = 2 is a prime number. Hence 1 is printed.
Companies nvidia roblox Juspay Topics Hashing Hash Map Unordered map Strings
full code in c++


*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * 1LL * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    // dp[c] = max length of subsequence ending with character c
    vector<int> dp(26, 0);
    int maxLen = 1;

    for (char ch : str) {
        int idx = ch - 'a';
        int best = 1;

        // Check neighbors with ASCII difference of 2
        if (idx >= 2) best = max(best, dp[idx - 2] + 1);
        if (idx <= 23) best = max(best, dp[idx + 2] + 1);

        dp[idx] = max(dp[idx], best);
        maxLen = max(maxLen, dp[idx]);
    }

    cout << ((maxLen > 1 && isPrime(maxLen)) ? 1 : 0) << endl;
    return 0;
}
