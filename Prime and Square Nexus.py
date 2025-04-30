'''
Problem Statement
In a kingdom ruled by numbers, a matrix of size N×N represented the heart of the land. The matrix, filled with positive integers, had special rules:

Prime Numbers: These guardians of wisdom were replaced by 0 but left no trace in their rows or columns.

Perfect Squares: These symbols of balance had the power to mark their entire row and column with -1.

The kingdom's rulers needed to organize the matrix by applying these transformations and count:

The number of rows fully transformed to -1.
The number of prime numbers replaced with 0.
After processing the matrix, the rulers sought to present the transformed matrix and showcase the results of this magical process.

Note: -1 will have high priority than 0.

Input Format
The first line contains a single integer N, the size of the matrix.

The next N lines contain N integers each, representing the elements of the matrix.

Output Format
Print two integers: the count of rows fully marked as -1 and the count of prime numbers replaced with 0.

Print the modified matrix with elements of the same row separated by a single space. Start the next row on a new line.

Constraints
2 <= N <= 100

2 <= grid[i][j] <= 10^6

Sample Testcase 0
Testcase Input
4
2 6 4 8
5 9 12 15
10 11 18 7
20 21 25 16
Testcase Output
3 0
-1 -1 -1 -1
-1 -1 -1 -1
10 -1 -1 -1
-1 -1 -1 -1
Explanation
In the given matrix,
The element 2, 5, 11, 7 are prime so replace them with 0.
0 6 4 8
0 9 12 15
10 0 18 0
20 21 25 16

Now, 4, 9, 25 and 16 are perfect square, so replace the entire row and column with -1.
-1 -1 -1 -1
-1 -1 -1 -1
10 -1 -1 -1
-1 -1 -1 -1
Since -1 have high priority than 0, so it has replace all 0s.
Number of rows entirely marked as -1 = 3
Number of zeroes : 0 (we have to considered the final matrix after replacements)

Sample Testcase 1
Testcase Input
3
4 5 6
2 11 13
12 18 10
Testcase Output
1 2
-1 -1 -1
-1 0 0
-1 18 10
Explanation
In the given matrix,
The element 2, 5, 11 and 13 are prime so replace them with 0.
4 0 6
0 0 0
12 18 10

Now, 4 is a perfect square, so replace the entire row and column with -1.
-1 -1 -1
-1 0 0
-1 18 10

Since -1 have high priority than 0, so it has replace the 0s present in (0,1) and (1,0).
Number of rows entirely marked as -1 = 1
Number of zeroes : 2 (we have to considered the final matrix after replacements)
'''

#CODE:=>
import math

def is_prime(num):
    """Check if a number is prime."""
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def is_perfect_square(num):
    """Check if a number is a perfect square."""
    root = math.isqrt(num)
    return root * root == num

def transform_matrix(matrix):
    n = len(matrix)
    rows_to_mark = set()
    cols_to_mark = set()
    prime_count = 0
    prime_positions = []

    # First pass: Identify primes and perfect squares
    for i in range(n):
        for j in range(n):
            if is_prime(matrix[i][j]):
                prime_positions.append((i, j))  # Store position of primes
            elif is_perfect_square(matrix[i][j]):
                rows_to_mark.add(i)
                cols_to_mark.add(j)

    # Mark rows and columns with -1 first
    for row in rows_to_mark:
        for j in range(n):
            matrix[row][j] = -1
    for col in cols_to_mark:
        for i in range(n):
            matrix[i][col] = -1

    # Second pass: Replace prime numbers with 0 (only if not already -1)
    for i, j in prime_positions:
        if matrix[i][j] != -1:
            matrix[i][j] = 0
            prime_count += 1

    # Count rows fully transformed to -1
    full_transformed_rows = sum(all(cell == -1 for cell in matrix[i]) for i in range(n))

    return full_transformed_rows, prime_count, matrix

# Input handling
n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

# Process the matrix
rows_transformed, primes_replaced, final_matrix = transform_matrix(matrix)

# Output results
print(rows_transformed, primes_replaced)
for row in final_matrix:
    print(" ".join(map(str, row)))
