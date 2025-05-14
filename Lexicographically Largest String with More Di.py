'''
Problem Statement
You are given two strings s1 and s2 of equal lengths. Your task is to determine which of the two strings has more distinct subsequences. If both strings have the same number of distinct subsequences, return the lexicographically largest string.

A subsequence of a string is a sequence derived from the string by deleting some or no characters without changing the order of the remaining characters.

Input Format
The input consists of two strings s1 and s2 of equal lengths.

Output Format
Output the string which has more distinct subsequences.

If both strings have the same number of distinct subsequences, output the lexicographically larger string.

Constraints
1 <= len(s1), len(s2) <= 30

The strings s1 and s2 consist of lowercase English letters ('a' to 'z').

Sample Testcase 0
Testcase Input
abc
acb
Testcase Output
acb
Explanation
Both "abc" and "acb" have the same number of distinct subsequences. Let's illustrate:


For "abc":




Subsequence possibilities are: {"", "a", "b", "c", "ab", "ac", "bc", "abc"}




For "acb":




Subsequence possibilities are: {"", "a", "c", "b", "ac", "ab", "cb", "acb"}




These two sets of subsequences have the same number (8), so the next factor is lexicographical order.

Sample Testcase 1
Testcase Input
gfg
ggg
Testcase Output
gfg
Explanation


"gfg" has 6 distinct subsequences: {"", "g", "f", "g", "fg", "gf", "gfg"}.




"ggg" has 3 distinct subsequences: {"", "g", "gg", "ggg"}.




Therefore, "gfg" has more distinct subsequences, so the output is "gfg".



Companies
Meesho
Walmart
Zoho
Topics
String
Data Structure
Strings

'''
from itertools import combinations

def count_distinct_subsequences(s):
    subsequences = set()
    n = len(s)
    for i in range(n + 1):
        for combo in combinations(s, i):
            subsequences.add("".join(combo))
    return len(subsequences)

def compare_strings(s1, s2):
    count1 = count_distinct_subsequences(s1)
    count2 = count_distinct_subsequences(s2)

    if count1 > count2:
        return s1
    elif count2 > count1:
        return s2
    else:
        return max(s1, s2)  # Lexicographically larger string

# Taking input from user
s1 = input()
s2 = input()

# Printing the result
print(compare_strings(s1, s2))
