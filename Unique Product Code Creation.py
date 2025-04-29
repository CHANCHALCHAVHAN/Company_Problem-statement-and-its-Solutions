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
from itertools import product

def generate_product_codes(N, char1, char2, char3):
    # Step 1: Generate all possible product codes
    chars = [char1, char2, char3]
    codes = [''.join(code) for code in product(chars, repeat=N)]
    
    # Step 2: Sort codes in lexicographically descending order
    codes.sort(reverse=True)
    
    # Step 3: Find the pair with the smallest ASCII difference
    min_diff = float('inf')
    smallest_pair = None
    
    for i in range(len(codes)):
        for j in range(i + 1, len(codes)):
            # Calculate ASCII difference between codes[i] and codes[j]
            diff = sum(abs(ord(a) - ord(b)) for a, b in zip(codes[i], codes[j]))
            
            # Update smallest_pair if a smaller difference is found
            if diff < min_diff:
                min_diff = diff
                smallest_pair = (codes[i], codes[j])
            elif diff == min_diff:  # Tie-breaking based on lexicographical order
                if (codes[i] < smallest_pair[0]) or (codes[i] == smallest_pair[0] and codes[j] < smallest_pair[1]):
                    smallest_pair = (codes[i], codes[j])
    
    # Step 4: Output results
    print(len(codes))
    print(' '.join(codes))
    print(' '.join(smallest_pair))

# Example input
N = int(input())  # Length of the product code
char1 = input().strip()
char2 = input().strip()
char3 = input().strip()

generate_product_codes(N, char1, char2, char3)
