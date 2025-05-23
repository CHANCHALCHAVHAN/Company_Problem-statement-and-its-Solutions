'''
Problem Statement
In the digital age, chat messages are filled with emotions expressed through smileys. The two most common emoticons are the happy smiley :) and the sad smiley :(. While these symbols are often scattered throughout messages, sometimes they appear in a pattern that shows emotional balance — where happy and sad emotions alternate.

You are given a string representing a user's chat message. This message may include normal text (alphabetic characters), spaces, and smileys (:) and :(). A smiley is always exactly two characters long and does not overlap with another smiley.

A balanced smiley pair is defined as a pair of smileys where:

One is a happy smiley :), and the other is a sad smiley :(,

They appear in alternating order (either :) :(, or :( :)), and

Each smiley can be part of only one balanced pair (i.e., no smiley is reused in more than one pair).

Your task is to analyze the chat message and return the maximum number of balanced smiley pairs that can be formed by alternately pairing happy and sad smileys.

This problem aims to simulate the emotional balance in a conversation and how evenly distributed emotions are represented through emoticons.

Input Format
A single line of input containing the chat message string s.

Output Format
Print a single integer — the maximum number of balanced smiley pairs that can be formed from the message.

Constraints
1 ≤ |s| ≤ 10^5

The string contains only:

Lowercase and uppercase English letters (a-z, A-Z)

Whitespace characters (spaces)

Non-overlapping smileys of the form :) and :(

Sample Testcase 0
Testcase Input
hello :) :( :)
Testcase Output
2
Explanation
Smiley Sequence Extracted:

:) :( :)

Explanation:


First :) and :( form a balanced pair → count = 1
The last :) has no :( left to pair with → unpaired
Resulting Balanced Pairs: 1
Total Smileys Used in Pairs: 1 pair * 2 smileys = 2

Sample Testcase 1
Testcase Input
this is sad :( :( but then :) :)
Testcase Output
4
Explanation
Smiley Sequence Extracted:

:( :( :) :)

Explanation:


First :( can pair with first :) → balanced pair #1
Second :( can pair with second :) → balanced pair #2
All smileys used in pairsResulting Balanced Pairs: 2
Total Smileys Used in Pairs: 2 pairs * 2 smileys = 4

Companies
Topics
String
Greedy
Stack
Parsing
Simulation
Data Structures
Strings
'''

def count_balanced_smiley_pairs(s):
    happy_count = 0
    sad_count = 0
    balanced_pairs = 0
    
    i = 0
    while i < len(s) - 1:
        if s[i:i+2] == ":)":
            happy_count += 1
        elif s[i:i+2] == ":(":
            sad_count += 1
        i += 1

    # The number of balanced pairs is the minimum of happy and sad smiley counts
    balanced_pairs = min(happy_count, sad_count)
    return balanced_pairs




s = input().strip()
print(count_balanced_smiley_pairs(s)*2) 
