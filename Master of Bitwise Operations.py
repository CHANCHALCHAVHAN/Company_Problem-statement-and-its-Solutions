'''
Problem Statement
Arjun wants to master bitwise operations, and he needs your help to solve queries on an array A of N elements. The queries that Arjun had to solve were as follows:
Each query contained 5 integers k, X1, Y1, X2, Y2. It was guaranteed that 1 ≤ X1 ≤ Y1 ≤ N and 1 ≤ X2 ≤ Y2 ≤ N. The answer to a query was the number of pairs (i, j) such that:
X1 ≤ i ≤ Y1 and X2 ≤ j ≤ Y2
The result of the bitwise XOR operation between Ai and Aj (Ai ⊕ Aj) has its k-th bit set.

Can you help Arjun solve this challenging problem?

 

Input Format
You are given T test cases and each test cases as follows.
The first line contains two space-separated integers N and Q, the size of array A and the number of queries respectively.
The second line contains N space-separated integers representing the elements of the array A.
Each of the next Q lines contains 5 space-separated integers k, X1, Y1, X2, Y2 representing the parameters of the query.

Output Format
For each query, print a single integer representing the answer on a new line.

Constraints
1<=T<=10
1 ≤ N ≤ 10^5 
1 ≤ Q ≤ 10^5 
0 ≤ Ai ≤ 2^30-1 (0 ≤ i < N)
1 ≤ k ≤ 30 
1 ≤ X1 ≤ Y1 ≤ N 
1 ≤ X2 ≤ Y2 ≤ N

Sample Testcase 0
Testcase Input
1
5 2
1 2 3 4 5
2 2 4 1 3
1 1 5 2 4
Testcase Output
3
8
Explanation
In the first query, we need to find the number of pairs (i, j) such that i belongs to the range [2,4] and j belongs to the range [1,3] and the k-th bit of (Ai ⊕ Aj) is set. Here, k=2. We can see that there are only 3 of their 2nd bit sets.
In the second query, we need to find the number of pairs (i, j) such that i belongs to the range [1,5] and j belongs to the range [2,4] and the k-th bit of (Ai ⊕ Aj) is set. Here, k=1. We can see that there are 8 such pairs in their 1st bit set.
Sample Testcase 1
Testcase Input
1
4 3
8 4 12 6
1 3 3 4 4
2 2 4 2 4
1 1 4 2 3 
Testcase Output
1
0
2
Explanation
In the first query, we need to find the number of pairs (i, j) such that i belongs to the range [3,4] and j belongs to the range [4,4] and the k-th bit of (Ai ⊕ Aj) is set. Here, k=3. We can see that there 1  such pairs
In the second query, we need to find the number of pairs (i, j) such that i belongs to the range [2,2] and j belongs to the range [2,4] and the k-th bit of (Ai ⊕ Aj) is set. Here, k=2. We can see that there is only No pair
In the third query, we need to find the number of pairs (i, j) such that i belongs to the range [1,4] and j belongs to the range [2,3] and the k-th bit of (Ai ⊕ Aj) is set. Here, k=1. We can see that there are only 2 such pairs that have its 1st bit set.
Companies
Amazon
Adobe
Topics
Prefix Sum
Dynamic Programming

'''


#CODE::=>
import sys

def main():
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        N, Q = int(input[ptr]), int(input[ptr + 1])
        ptr += 2
        A = list(map(int, input[ptr:ptr + N]))
        ptr += N
        
        # Precompute prefix sums for each bit
        prefixes = []
        for bit in range(31):
            prefix = [0] * (N + 1)
            for i in range(1, N + 1):
                prefix[i] = prefix[i - 1] + ((A[i - 1] >> bit) & 1)
            prefixes.append(prefix)
        
        for __ in range(Q):
            k = int(input[ptr])
            X1 = int(input[ptr + 1])
            Y1 = int(input[ptr + 2])
            X2 = int(input[ptr + 3])
            Y2 = int(input[ptr + 4])
            ptr += 5
            
            bit = k - 1  # Convert to 0-based
            
            # Calculate for range1 [X1, Y1]
            sum1_1 = prefixes[bit][Y1] - prefixes[bit][X1 - 1]
            sum0_1 = (Y1 - X1 + 1) - sum1_1
            
            # Calculate for range2 [X2, Y2]
            sum1_2 = prefixes[bit][Y2] - prefixes[bit][X2 - 1]
            sum0_2 = (Y2 - X2 + 1) - sum1_2
            
            ans = sum1_1 * sum0_2 + sum0_1 * sum1_2
            print(ans)

if __name__ == "__main__":
    main()
