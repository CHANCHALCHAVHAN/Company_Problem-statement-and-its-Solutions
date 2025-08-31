'''
Problem Statement
You are given an array A of N integers. A Phantom Subset Mirror is a non-empty subset of indices S = {i₁, i₂, ..., iₖ}, such that:

The elements at those indices form a subset B = [A[i₁], A[i₂], ..., A[iₖ]]

You reverse B to get B' = reverse(B)

Compute an array D, where each element is D[j] = B[j] - B'[j]

The prefix sums of array D must be strictly increasing — i.e.,
prefix_sum[0] < prefix_sum[1] < ... < prefix_sum[k-1]

Two subsets are considered different if they consist of different indices, even if their values are the same.

Your task is to count how many such Phantom Subset Mirrors exist.

Input Format
The first line contains an integer N — the number of elements in the array.

The second line contains N space-separated integers — the elements of the array A.

Output Format
Print a single integer — the number of valid Phantom Subset Mirrors in the array.

Constraints
2 ≤ N ≤ 20

-1000 ≤ A[i] ≤ 1000

Each subset must contain at least two elements

Subsets are based on indices — so different positions with same values count as separate

Sample Testcase 0
Testcase Input
3  
5 5 5
Testcase Output
0
Explanation
All elements are the same. Any subset's difference array will be all zeros:
e.g., [5,5] → D = [0,0], Prefix = [0,0] → not strictly increasing 
No valid subsets exist.

Sample Testcase 1
Testcase Input
4  
1 3 2 6
Testcase Output
5
Explanation
We consider all subsets of size ≥ 2. These 5 subsets satisfy the condition where the prefix sum of B[i] - reverse(B)[i] is strictly increasing:


[1,3] → D = [-2,2] → Prefix = [-2, 0] 


[1,2] → D = [-1,1] → Prefix = [-1, 0] 


[1,6] → D = [-5,5] → Prefix = [-5, 0] 


[3,6] → D = [-3,3] → Prefix = [-3, 0] 


[2,6] → D = [-4,4] → Prefix = [-4, 0] 


All others fail the prefix condition.

Companies
Topics
Bit Manipulation
Prefix Sum
array manipulation
Data Structures
Bitwise Manipulation

'''

from itertools import combinations

def count_phantom_subset_mirrors(A):
    N = len(A)
    count = 0

    # Generate all subsets of indices of size >= 2
    for size in range(2, N + 1):
        for indices in combinations(range(N), size):
            B = [A[i] for i in indices]
            B_rev = B[::-1]
            D = [b - br for b, br in zip(B, B_rev)]

            # Compute prefix sums
            prefix_sum = []
            current = 0
            for d in D:
                current += d
                prefix_sum.append(current)

            # Check if prefix sums are strictly increasing
            if all(prefix_sum[i] < prefix_sum[i + 1] for i in range(len(prefix_sum) - 1)):
                count += 1

    return count

# Input reading
N = int(input())
A = list(map(int, input().split()))

# Output result
print(count_phantom_subset_mirrors(A))
