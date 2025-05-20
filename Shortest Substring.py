'''
Problem Statement
Alice, a spy, needs to decode a message that was intercepted from an enemy agent.  The message is encoded as a substring of a longer string S, and Alice knows that the substring contains all the characters of a secret code L.

She needs to find the shortest substring of S that contains all the characters of L in any order. If there is no such substring, output -1.

Input Format
The first line contains the longer string S (1 ≤ |S| ≤ 10^5), consisting of printable ASCII characters.
The second line contains the secret code L (1 ≤ |L| ≤ 10^5), consisting of printable ASCII characters.

Output Format
The length of the shortest substring of S that contains all the characters of L in any order. If there is no such substring, output -1.

Constraints
Each character of S and T is a printable ASCII character.
1 ≤ |L| ≤ |S| ≤ 10^5

Sample Testcase 0
Testcase Input
abbadcab 
abc
Testcase Output
3
Explanation
The shortest substring of S that contains all the characters of L is "bac", which has length 3.
Sample Testcase 1
Testcase Input
Hello, World! 
XYZ
Testcase Output
-1
Explanation
There is no substring of S that contains all the characters of T.
Companies
Cisco
Topics
Substring
String Manipulation
Strings

'''

#CODE:->
from collections import Counter

def shortest_substring(S: str, L: str) -> int:
    if not S or not L:
        return -1
    
    target_count = Counter(L)
    required_chars = len(target_count)
    left = 0
    min_length = float("inf")
    formed = 0
    window_count = {}

    for right in range(len(S)):
        char = S[right]
        window_count[char] = window_count.get(char, 0) + 1

        if char in target_count and window_count[char] == target_count[char]:
            formed += 1

        while formed == required_chars and left <= right:
            if right - left + 1 < min_length:
                min_length = right - left + 1

            left_char = S[left]
            window_count[left_char] -= 1

            if left_char in target_count and window_count[left_char] < target_count[left_char]:
                formed -= 1

            left += 1

    return min_length if min_length != float("inf") else -1

# Taking input from the user
S = input("Enter the longer string S: ")
L = input("Enter the secret code L: ")

# Finding and printing the result
result = shortest_substring(S, L)
print(result)
