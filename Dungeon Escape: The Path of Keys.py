'''
Problem Statement
In a mysterious dungeon, a brave adventurer is trapped and must escape through a tunnel filled with N locked gates. Each gate must be unlocked before proceeding further. The adventurer has two types of magical keys:

A single-use key that can unlock one gate at a time.
A master key that can unlock two consecutive gates at once.
To escape, the adventurer must unlock all N gates using any combination of these keys. Since the dungeon is ancient and filled with traps, the adventurer must determine the number of distinct ways to escape before making a move.

Your task is to find the number of different ways the adventurer can reach the end of the tunnel using these two types of keys. Since the answer can be large, compute the result modulo 10^9 + 7.

Input Format
The first line of input contains a single number N, representing the number of locked gates.

Output Format
Print a single number representing the number of distinct ways the adventurer can escape the dungeon.

Constraints
1 ≤ N < 92

Sample Testcase 0
Testcase Input
4
Testcase Output
5
Explanation
The adventurer can escape using the following sequences:
(1 → 1 → 1 → 1)
(1 → 1 → 2)
(1 → 2 → 1)
(2 → 1 → 1)
(2 → 2)


Total ways = 5

Sample Testcase 1
Testcase Input
6
Testcase Output
13
Explanation
There will be 13 possible way to unlock all the doors to escape.
'''

'''
Topics
Recursion
Fibonacci series
Dynamic Programming
'''
#CODE:::=>
def countWays(N):
    MOD = 10**9 + 7
    
    if N == 1:
        return 1
    elif N == 2:
        return 2
    
    # Initialize base cases
    dp = [0] * (N + 1)
    dp[1], dp[2] = 1, 2
    
    # Compute number of ways for each gate up to N
    for i in range(3, N + 1):
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD
    
    return dp[N]

# Example usage
N = int(input())  # Read input from user
print(countWays(N))  # Print the result
