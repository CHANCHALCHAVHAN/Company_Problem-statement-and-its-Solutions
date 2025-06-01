'''
Problem Statement
Sid is analyzing the selling prices in different cities and wants to identify a longest contiguous subsequence of consecutive cities where prices are strictly increasing. However, he has a unique way of calculating profits:

He is only interested in prime numbers that are also "double prime numbers" (A double prime number is a prime number p such that p+2 is also prime).

Find the longest strictly increasing subsequence of prices.

Calculate the maximum sum of double prime numbers in that subsequence.

If multiple subsequences have the same length, choose the one with the highest sum of double primes.

If no double prime numbers are found, return 0 for the prime sum.

Input Format
The first line contains a single integer n, representing the number of cities (length of the array).

The second line contains n space-separated integers, representing the selling prices in different cities.

Output Format
Print two space-separated integers:

The length of the longest strictly increasing subsequence.

The sum of double prime numbers in that subsequence.

Constraints
1 ≤ arr.length ≤ 10^5

1 ≤ arr[i] ≤ 10^5

Expected Time Complexity: O(n sqrt(n))

Expected Space Complexity: O(n)

Sample Testcase 0
Testcase Input
5
3 5 7 11 3
Testcase Output
4 19
Explanation
We have 5 cities with prices: 3, 5, 7, 11, 3
The longest strictly increasing subsequence is [3, 5, 7, 11] with length 4
Among these numbers, the double primes are:
- 3 (because 3 and 5 are both prime)
- 5 (because 5 and 7 are both prime)
- 11 (because 11 and 13 are both prime)
Sum of double primes: 3 + 5 + 11 = 19
Therefore, output is "4 19"

Sample Testcase 1
Testcase Input
5
4 6 8 10 12
Testcase Output
5 0
Explanation
We have 5 cities with prices: 4, 6, 8, 10, 12
The entire sequence [4, 6, 8, 10, 12] is strictly increasing with length 5
None of these numbers are double primes:
- 4 is not prime
- 6 is not prime
- 8 is not prime
- 10 is not prime
- 12 is not prime
Sum of double primes: 0 (since there are no double primes)
Therefore, output is "5 0"

Companies
Topics
Data Structures
Mathematics, Algorithms
Array
Arrays
'''

import math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def is_double_prime(n):
    return is_prime(n) and is_prime(n + 2)

def longest_increasing_subsequence(arr):
    n = len(arr)
    max_length = 1
    max_sum = 0
    length = 1
    sum_double_primes = is_double_prime(arr[0]) * arr[0]

    start = 0
    for i in range(1, n):
        if arr[i] > arr[i - 1]:
            length += 1
            sum_double_primes += arr[i] if is_double_prime(arr[i]) else 0
        else:
            if length > max_length or (length == max_length and sum_double_primes > max_sum):
                max_length = length
                max_sum = sum_double_primes

            length = 1
            sum_double_primes = arr[i] if is_double_prime(arr[i]) else 0

    if length > max_length or (length == max_length and sum_double_primes > max_sum):
        max_length = length
        max_sum = sum_double_primes

    return max_length, max_sum

# Input handling
n = int(input())
arr = list(map(int, input().split()))

length, prime_sum = longest_increasing_subsequence(arr)
print(length, prime_sum)
