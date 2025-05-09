'''
Problem Statement
The IPL 2025 semi-finals are here! Teams GT, SRH, KKR, and LSG have made it to the knockout stage. The second semi-final match is between Kolkata Knight Riders (KKR) and Lucknow Super Giants (LSG).

Shreyas Iyer, the captain of KKR, wants to send a secret encrypted message to his bowler without letting the batsmen overhear. The encrypted message consists of a sequence of numbers, and the bowler has a special decryption rule:

The bowler starts reading the message from right to left.

Whenever he finds a prime number, he removes it and replaces it with the sum of all previous numbers in the sequence.

This process continues until there are no prime numbers left in the sequence.

Given the original decrypted message as a list of integers, your task is to generate the shortest possible encrypted sequence using * in place of removed prime numbers.

Input Format
The first line contains a single integer N — the number of elements in the sequence .

The second line contains N space-separated integers as nums[i].

Output Format
Print N space-separated values representing the shortest possible encrypted sequence, where * denotes a removed prime number.

Constraints
1 ≤ N ≤ 10^3

1 ≤ nums[i] ≤ 10^5

The input sequence may contain both prime and non-prime numbers.

Sample Testcase 0
Testcase Input
5  
11 22 13 17 19  
Testcase Output
* 22 * * *
Explanation


Prime numbers (11, 13, 17, 19) are replaced with *.




Non-prime number (22) remains unchanged.



Sample Testcase 1
Testcase Input
7  
2 3 5 10 7 15 20  
Testcase Output
* * * 10 * 15 20
Explanation


Prime numbers (2, 3, 5, 7) are replaced with *.




Non-prime numbers (10, 15, 20) remain unchanged.



Companies
Topics
Data Structures
Stack
'''
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def encrypt_sequence(nums):
    encrypted = []
    sum_so_far = 0

    for num in reversed(nums):
        if is_prime(num):
            encrypted.append('*')
            sum_so_far += num
        else:
            encrypted.append(num)

    return encrypted[::-1]

# Read input
N = int(input())
nums = list(map(int, input().split()))

# Generate encrypted sequence
result = encrypt_sequence(nums)

# Print output
print(" ".join(map(str, result)))
