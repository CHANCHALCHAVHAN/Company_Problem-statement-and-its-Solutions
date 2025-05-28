'''
Problem Statement
In a futuristic world, messages are encoded using a special encrypted chain, represented by a string S. This chain contains a sequence of lowercase English letters (a-z) and numeric digits (0-9). The encryption technique assigns an energy value to each character in the chain:

For lowercase letters, the energy is equal to the alphabetical position of the letter. That is:

'a' has energy 1

'b' has energy 2

...

'z' has energy 26

For numeric digits, the energy is 10 times the digit’s value:

'0' has energy 0

'1' has energy 10

...

'9' has energy 90

The chain is unstable, and it may collapse due to the interference of characters having the same energy. The collapse process works as follows:

Whenever two adjacent characters in the string have exactly equal energy, they undergo a destructive interference and both are removed from the chain.

This process is repeated as long as at least one such pair exists in the string.

If multiple adjacent pairs exist that meet the collapse condition, you must process them from left to right, in a single pass, before checking for more collapses in the next pass.

Your task is to simulate the entire collapse process and determine the final form of the chain after all possible collapses.

If the final chain is completely empty (i.e., all characters are removed), return -1.

Input Format
A single line containing the string S

Output Format
Print a single line containing the final chain after all valid collapses have been applied.

If the entire chain collapses and becomes empty, print -1.

Constraints
1 ≤ ∣S∣ ≤ 10^5

S contains only lowercase English letters (a to z) and digits (0 to 9)

Sample Testcase 0
Testcase Input
abc123cba
Testcase Output
abc123cba
Explanation
Energy Values:  a(1), b(2), c(3), 1(10), 2(20), 3(30), c(3), b(2), a(1)


First Pass:  No collapses in this pass as there are no adjacent characters with equal energy.


Remaining string: abc123cba

Sample Testcase 1
Testcase Input
abccba
Testcase Output
-1
Explanation
Energy Values:  a(1), b(2), c(3), c(3), b(2), a(1)


First Pass: c(3) and c(3) collapse (both removed).


Remaining string: ab  b  a


Second Pass:  b(2) and b(2) collapse (both removed).


Remaining string: a  a


Third Pass:  a(1) and a(1) collapse (both removed).


Remaining string: -1 (all characters are removed)

Companies
Topics
String Manipulation
Greedy Algorithm
Simulation
Stack
Data Structures
Two Pointers
Strings
'''
#Code:=>
def get_energy(ch):
    if 'a' <= ch <= 'z':
        return ord(ch) - ord('a') + 1
    elif '0' <= ch <= '9':
        return int(ch) * 10
    return None

def collapse_chain(s):
    stack = []
    
    for ch in s:
        energy = get_energy(ch)
        if stack and get_energy(stack[-1]) == energy:
            stack.pop()
        else:
            stack.append(ch)
    
    return "".join(stack) if stack else "-1"

# Example usage:
s = input().strip()
print(collapse_chain(s))
