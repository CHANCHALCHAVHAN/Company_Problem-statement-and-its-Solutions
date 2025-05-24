'''
Problem Statement
In a city, there are N towers arranged in a straight line. Each tower has a certain height. You are allowed to process the towers in order, considering each pair of adjacent towers.

There is a threshold value K, and you can perform the following two types of operations:

Link Operation (Forced Merge): You must merge two adjacent towers (i and i+1) if the GCD of their heights is greater than K, unless you choose to skip this merge using a "skip operation" (see below).
When you merge them, they become one tower with a new height equal to the sum of their original heights.

After merging, this pair is treated as a single tower in future operations.

Skip Operation (Limited Usage): You can skip a merge, even if the GCD is greater than K — but only M times in total across the entire process.

Choose a sequence of merge and skip operations such that:

You follow the rules above.

You end up with the maximum possible number of towers remaining after processing all pairs.

Input Format
The first line contains three integers: N, K, and M

The second line contains N integers — H[0], H[1], ..., H[N-1]

Output Format
Print the maximum number of towers that can remain after performing the operations optimally.

Constraints
2 ≤ N ≤ 10^5

1 ≤ K ≤ 10^4

0 ≤ M ≤ N-2

1 ≤ H[i] ≤ 10^5

Sample Testcase 0
Testcase Input
4 10 2
20 30 40 50
Testcase Output
4
Explanation
Tower heights: 20, 30, 40, 50


k = 10, m = 2 (allowed skips)


Process:


20 and 30 → GCD(20,30) = 10 (allowed, no forced merge)


30 and 40 → GCD(30,40) = 10 (allowed, no forced merge)


40 and 50 → GCD(40,50) = 10 (allowed, no forced merge)


Since every GCD is ≤ k, no merges needed, no skips used.

Answer: 4

Sample Testcase 1
Testcase Input
4 2 0
6 9 10 15
Testcase Output
1
Explanation
We are allowed 0 skips, so every adjacent pair with GCD > 2 must be merged.
GCD(6, 9) = 3 → Greater than K → Must merge (no skip available)
New tower height: 6 + 9 = 15


Array becomes: [15, 10, 15]
Now check GCD(15, 10) = 5 → Greater than K → Must merge
New tower height: 15 + 10 = 25


Array becomes: [25, 15]
Now check GCD(25, 15) = 5 → Greater than K → Must merge
New tower height: 25 + 15 = 40


Array becomes: [40]

Topics
GCD
Greedy
array manipulation
Optimization
Simulation
Mathematics, Algorithms
'''

#CODE:->
from math import gcd

def max_towers_remaining(N, K, M, heights):
    merged = []  # Stores the resulting towers after merge operations
    skips_left = M  # Number of available skip operations

    i = 0
    while i < N:
        if not merged:
            merged.append(heights[i])
        else:
            current_gcd = gcd(merged[-1], heights[i])
            if current_gcd > K:
                if skips_left > 0:
                    skips_left -= 1
                    merged.append(heights[i])  # Skip merge
                else:
                    merged[-1] += heights[i]  # Forced merge
            else:
                merged.append(heights[i])
        i += 1

    return len(merged)  # Maximum number of towers remaining


N, K, M =map(int, input().split())
heights =list(map(int , input().split()))
print(max_towers_remaining(N, K, M, heights))  
