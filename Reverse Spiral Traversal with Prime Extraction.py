'''
Problem Statement
You are given a rectangular matrix mat[][] of size M x N. Your task is to return three outputs while traversing the matrix in spiral order, starting from the bottom-right corner and moving towards the top-left corner.

Requirements:

First Output: The elements of the matrix in spiral order starting from bottom-right (M-1, N-1).
Second Output: An array containing only the prime numbers in the order they appear in the traversal. return 0 if no prime exist.
Third Output: The sum of all prime numbers found in the traversal.
Input Format
The first line contains two integers, M and N, representing the dimensions of the matrix.

The next M lines contain N space-separated integers, representing the matrix elements.

Output Format
Print:

A single line containing the elements in reverse spiral order.
A single line containing only the prime numbers from that sequence. return 0 in case of no primes.
A single integer representing the sum of the prime numbers.
Constraints
1 <= M, N <= 1000

1 <= mat[i][j] <= 10^6

Sample Testcase 0
Testcase Input
4 4
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16
Testcase Output
16 15 14 13 9 5 1 2 3 4 8 12 11 10 6 7
13 5 2 3 11 7
41
Explanation
Spiral order (reverse start): [16, 15, 14, 13, 9, 5, 1, 2, 3, 4, 8, 12, 11, 10, 6, 7]


Prime numbers extracted: [13, 5, 2, 3, 11, 7]


Sum of primes: 13 + 5 + 2 + 3 + 11 + 7 = 41

Sample Testcase 1
Testcase Input
3 5
29  30  31  32  33
23  24  25  26  27
19  17  13  11   7
Testcase Output
7 11 13 17 19 23 29 30 31 32 33 27 26 25 24
7 11 13 17 19 23 29 31
150
Explanation
Step-by-Step Spiral Order (Reverse)


Start from bottom-right (7) → move left: [7, 11, 13, 17, 19]
Move up (column 0): [7, 11, 13, 17, 19, 23]
Move right (row 0): [7, 11, 13, 17, 19, 23, 29, 30, 31, 32, 33]
Move down (column 4): [7, 11, 13, 17, 19, 23, 29, 30, 31, 32, 33, 27]
Move left (row 1): [7, 11, 13, 17, 19, 23, 29, 30, 31, 32, 33, 27, 26, 25, 24]

Prime Numbers in this Order
Extracting only prime numbers from the sequence: 7 11 13 17 19 23 29 31


 


 


Sum of Prime Numbers: 7 + 11 + 13 + 17 + 19 + 23 + 29 + 31 = 150
'''
'''
Companies
Amazon
Mastercard
Topics
Recursion
Mathematical Calculations
Matrix

'''
#CODE::=>
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def spiral_reverse(mat, M, N):
    result = []
    top, bottom, left, right = 0, M - 1, 0, N - 1

    while top <= bottom and left <= right:
        # Move left along the bottom row
        for i in range(right, left - 1, -1):
            result.append(mat[bottom][i])
        bottom -= 1
        
        # Move up along the left column
        for i in range(bottom, top - 1, -1):
            result.append(mat[i][left])
        left += 1
        
        if top <= bottom:
            # Move right along the top row
            for i in range(left, right + 1):
                result.append(mat[top][i])
            top += 1

        if left <= right:
            # Move down along the right column
            for i in range(top, bottom + 1):
                result.append(mat[i][right])
            right -= 1

    return result

def extract_primes(sequence):
    primes = [num for num in sequence if is_prime(num)]
    return primes if primes else [0]

def main():
    M, N = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(M)]

    spiral_order = spiral_reverse(mat, M, N)
    primes = extract_primes(spiral_order)
    prime_sum = sum(primes)

    print(" ".join(map(str, spiral_order)))
    print(" ".join(map(str, primes)))
    print(prime_sum)

if __name__ == "__main__":
    main()
