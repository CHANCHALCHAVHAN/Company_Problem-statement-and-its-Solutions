'''
Problem Statement
You are given a sequence consisting of N^2 integers, with the first N integers provided as input. This sequence exhibits periodic behavior such that the value at each index i repeats every N position, meaning A(i)=A(i+N).

Your task is to determine the smallest positive integer x such that for any sequence of positive integers that adds up to a specified sum S (also provided in the input), the integer x can be included as a subsequence.

Input Format
In the first line you are give two integers denoting N and S. 

In the second line you are given N numbers separated by space ( A1 A2 … An)

Output Format
Print the the minimum integer possible as per the question.

Constraints
1≤N≤2*10^5
1<=S<=min(N,2*10^5)
1<=Ai<=S
For every positive integer x (1<=x<=S),(A1,A2,…,An) contains at least one occurrence of x

Sample Testcase 0
Testcase Input
1 1
1
Testcase Output
1
Explanation
Only 1 sequence possible
Sample Testcase 1
Testcase Input
6 4
1 1 2 1 4 3
Testcase Output
9
Explanation
There are eight sequences SEQ to consider SEQ=(1,1,1,1),(1,1,2),(1,2,1),(1,3),(2,1,1),(2,2),(3,1),4
For L=8 ,SEQ=(2,2) is not a subsequence of (A1,A2,….,A8)=(1,1,2,1,4,3,1,1)
For L=9 every SEQ is a subsequence so 9 will be the output
Companies
Amazon
Microsoft
Google
Topics
Sorting
Binary Search
Dynamic Programming
Array

'''

def find_min_integer(N, S, A):
    # Initialize a set to track reachable sums
    reachable_sums = {0}
    
    for num in A:
        new_sums = set()
        for s in reachable_sums:
            new_sum = s + num
            if new_sum <= S:
                new_sums.add(new_sum)
        reachable_sums.update(new_sums)

    # Find the smallest positive integer x that cannot be formed
    for x in range(1, S + 1):
        if x not in reachable_sums:
            return x
    
    return S + 1

# Input reading
N, S = map(int, input().split())
A = list(map(int, input().split()))

# Output the result
print(find_min_integer(N, S, A))
