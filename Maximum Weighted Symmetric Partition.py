'''
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
Topics
palindrome
Memoization
Partitioning
String
Palindromic Structure
Dynamic Programming
'''
def is_palindrome(s):
    return s == s[::-1]

def max_palindromic_partition_score(N, S, weights):
    from functools import lru_cache

    # Precompute character weights
    char_weights = {chr(i + ord('a')): weights[i] for i in range(26)}

    # Compute prefix sums for weight calculations
    prefix_weight = [0] * (N + 1)
    for i in range(N):
        prefix_weight[i + 1] = prefix_weight[i] + char_weights[S[i]]

    @lru_cache(None)
    def dp(start):
        if start >= N:
            return 0
        
        max_score = 0
        for end in range(start, N):
            substr = S[start:end + 1]
            if is_palindrome(substr):
                length = end - start + 1
                weight_sum = prefix_weight[end + 1] - prefix_weight[start]
                score = length * weight_sum
                max_score = max(max_score, score + dp(end + 1))
        
        return max_score
    
    return dp(0)

# Input example
N = int(input())
S = input().strip()
weights = list(map(int, input().split()))

# Output result
print(max_palindromic_partition_score(N, S, weights))
