'''
Problem Statement
You are tasked with creating and displaying a list of unique product codes for a newly introduced line of gadgets. The product codes should follow specific criteria:

Each code must consist of exactly N characters.
There are exactly 3 characters allowed in the codes i.e char1, char2 and char3.
The strings must be arranged in lexicographically descending order.
Additionally, you need to determine and print the two product codes that have the smallest ASCII difference.

Note: AB and BA are considered unique and the smallest difference should not be considered 0.

Input Format
The first line of input consists of a single integer N representing the length of the product code.

The next three lines each containing a single character representing the allowed character in the code.

Output Format
The first line should contain the total number of unique product codes.

The second line should contain all the product codes in lexicographically descending order, separated by spaces.

The third line should contain the two product codes that have the smallest ASCII difference, separated by a space. If multiple pairs are tied with the smallest difference, you could choose the first lexicographically sorted pair.

Constraints
1 <= N <= 10

Sample Testcase 0
Testcase Input
1
X
Y
Z
Testcase Output
3
Z Y X
Z Y
Explanation
N = 1: Codes of length 1 using characters X, Y, and Z.
Generated codes: X, Y, Z
Sorted in descending order: Z, Y, X
Smallest ASCII difference is between Z, Y.

Sample Testcase 1
Testcase Input
2
A
B
C
Testcase Output
9
CC CB CA BC BB BA AC AB AA
CC CB
Explanation
n = 2: Codes of length 2 using characters A, B, and C.
Generated codes: AA, AB, AC, BA, BB, BC, CA, CB, CC.
Sorted in descending order: CC, CB, CA, BB, BA, BC, AC, AB, AA.
Smallest ASCII difference is between CC and CB.
'''
#CODE
import itertools

def solve():
    N = int(input())
    chars = [input().strip() for _ in range(3)]
    chars_sorted = sorted(chars, reverse=True)
    
    # Generate all possible product codes of length N
    product_codes = [''.join(p) for p in itertools.product(chars_sorted, repeat=N)]
    
    # Remove duplicates (though with same chars, no duplicates in product if chars are unique)
    unique_codes = list(product_codes)
    unique_codes_sorted = sorted(unique_codes, reverse=True)
    
    print(len(unique_codes_sorted))
    print(' '.join(unique_codes_sorted))
    
    min_diff = float('inf')
    pair = (None, None)
    
    for i in range(len(unique_codes_sorted) - 1):
        code1 = unique_codes_sorted[i]
        code2 = unique_codes_sorted[i + 1]
        current_diff = 0
        for c1, c2 in zip(code1, code2):
            current_diff += abs(ord(c1) - ord(c2))
        if current_diff < min_diff:
            min_diff = current_diff
            pair = (code1, code2)
    
    print(' '.join(pair))

solve()
