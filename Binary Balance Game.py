'''
Problem Statement
Alex and Carrie have introduced a new twist to their binary game. This time, Alex gives Carrie a number N. Carrie's task is to start from 0 and incrementally go up to N. For each number in this range, Carrie must:

Count the number of 1s in its binary representation.
Check if the number is even or odd.
If the number is even, Carrie adds the count of 1s to a running total. If it's odd, she subtracts the count of 1s from the previous total.
Input Format
The first line of input contains a single integer N.

Output Format
Print a sequence of space-separated numbers representing the running total after applying the above logic from 0 to N.

Constraints
0 <= N <= 10^4

Sample Testcase 0
Testcase Input
8
Testcase Output
0 -1 0 -2 -1 -3 -1 -4 -3
Explanation
0 → Binary: 0 (even) → Add 0 → Running Total: 0
1 → Binary: 1 (odd) → Subtract 1 → Running Total: 0 - 1 = -1
2 → Binary: 10 (even) → Add 1 → Running Total: -1 + 1 = 0
3 → Binary: 11 (odd) → Subtract 2 → Running Total: 0 - 2 = -2
4 → Binary: 100 (even) → Add 1 → Running Total: -2 + 1 = -1
5 → Binary: 101 (odd) → Subtract 2 → Running Total: -1 - 2 = -3
6 → Binary: 110 (even) → Add 2 → Running Total: -3 + 2 = -1
7 → Binary: 111 (odd) → Subtract 3 → Running Total: -1 - 3 = -4
8 → Binary: 1000 (even) → Add 1 → Running Total: -4 + 1 = -3

Sample Testcase 1
Testcase Input
5
Testcase Output
0 -1 0 -2 -1 -3
Explanation
0 -> 0 (even) -> 0 
1 -> 1 (odd) -> 0 - 1 = -1 
2 -> 10 (even) -> -1 + 1 = 0 
3 -> 11 (odd) -> 0 - 2 = -2 
4 -> 100 (even) -> -2 + 1 = -1 
5 -> 101 (odd) -> -1 - 2 = -3 
So final otput will be: [0, -1, 0, -2, -1, -3]
'''
'''
Topics
Bit Manipulation
Number Theory
Binary Conversion
Simulation
Math
'''

#CODE::==>
def binary_game(N):
    running_total = 0
    result = []
    
    for num in range(N + 1):
        count_ones = bin(num).count('1')  # Count the number of 1s in binary representation
        if num % 2 == 0:  # Even number
            running_total += count_ones
        else:  # Odd number
            running_total -= count_ones
        result.append(running_total)
    
    print(" ".join(map(str, result)))

# Example usage:
N = int(input().strip())  # Read input
binary_game(N)
