'''
Problem Statement
Two archaeologists, Alex and Ben, discovered an ancient treasure chest filled with relics in a hidden cave. The artifacts were grouped in bundles, each containing unique items like pottery, gems, or coins. Alex and Ben decided to divide the artifacts equally to ensure fairness, but there was a challenge: they had to keep the bundles intact.

If they successfully divided the bundles equally, the discovery would be shared, and they could showcase their findings as partners. However, if the division wasn’t perfect, the guardian spirit of the cave—an ancient phoenix—would swoop in and reclaim the artifacts, leaving the two archaeologists empty-handed.

Your mission is to determine whether Alex and Ben can share the bundles equally (“partners”) or if the phoenix claims the artifacts (“phoenix”).

Input Format
The first line contains an integer N representing the number of bundles.

The second line contains a list of N integers where each integer represents the number of items in each bundle.

Output Format
Print a string: "partners" if they can divide the bundles equally, or "phoenix" if they cannot.

Constraints
1 <= N <= 200

1 <= bundles[i] <= 100

Sample Testcase 0
Testcase Input
3
3 2 5
Testcase Output
partners
Explanation
Both of them can divide the bundles equally so output is partners.
[3,2], [5].

Sample Testcase 1
Testcase Input
5
2 4 5 1 3
Testcase Output
phoenix
Explanation
Both of them cannot divide the bundles equally, so the output is phoenix.
'''
'''
Companies
Dell
IBM
ZS
PwC
'''
'''
Topics
Dynamic Programming
Greedy Algorithm
Equal Subset Sum Problem
Data Structures & Algorithms
'''
#CODE::==>
def divide_bundles(N, bundles):
    total_items = sum(bundles)
    
    # If the total items are odd, they can't be divided equally
    if total_items % 2 != 0:
        return "phoenix"
    
    # Target for each archaeologist to have
    target = total_items // 2
    
    # Use dynamic programming to check if we can achieve the target sum
    dp = [False] * (target + 1)
    dp[0] = True
    
    for bundle in bundles:
        for j in range(target, bundle - 1, -1):
            dp[j] = dp[j] or dp[j - bundle]
    
    return "partners" if dp[target] else "phoenix"

# Input
N = int(input())
bundles = list(map(int, input().split()))

# Output
print(divide_bundles(N, bundles))
