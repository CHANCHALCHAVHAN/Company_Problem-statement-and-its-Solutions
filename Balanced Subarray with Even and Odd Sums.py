'''
Problem Statement
In the futuristic city of Bitropolis, data flows like water, and everything runs on binary energy. The city’s Central Intelligence Grid (CIG) is maintained by a stream of encrypted integers, where each number represents a unit of power with a unique binary fingerprint.

However, a sudden anomaly disrupts the power harmony. The system's core algorithm—Binary Balancer—has detected an imbalance in binary parity between the even and odd zones of the power pipeline. The even indices and odd indices are managed by separate AI modules, and they operate optimally only when the number of 1s in their binary representations is balanced.

To stabilize the system and prevent a city-wide blackout, you, the lead Data Architect of Bitropolis, are given the mission:

Identify the longest continuous segment in the pipeline where the binary 1s from the even-indexed energy cells match exactly with the binary 1s from the odd-indexed cells.

Find the largest such segment and report its length back to CIG. The fate of Bitropolis depends on your ability to restore the binary equilibrium.

Input Format
The first line of input contains array of integers each separated by space.

Output Format
Print the length of the largest contiguous subarray such that the sum of elements at even indices is equal to the sum of elements at odd indices.

Constraints
1 <= len(arr) <= 10^5

1 <= arr[i] <= 5*10^5

Sample Testcase 0
Testcase Input
8 3 15 1 6 10 5 2
Testcase Output
5
Explanation
Count of 1s in the binary representation:
[1, 2, 4, 1, 2, 2, 2, 1]
If we look at the subarray from index 3 to 7
Count of 1s at odd indices: 1 + 2 + 1 = 4.
Count of 1s at even indices: 2 + 2 = 4.
Therefore, the longest subarray length is 5.

Sample Testcase 1
Testcase Input
12 23 34 45 56 67 78 89 90
Testcase Output
9
Explanation
Count of 1s in the binary representation:
[2, 4, 2, 4, 3, 3, 4, 4, 4]
If we look at the subarray from index 0 to 8
Count of 1s at odd indices: 4 + 4 + 3 + 4 = 15.
Count of 1s at even indices: 2 + 2 + 3 + 4 + 4 = 15.
Therefore, the longest subarray length is 9.

Companies
Topics
Prefix Sum
Sliding Window
Dynamic Programming
Arrays
'''


#CODE
def longest_balanced_subarray(arr):
    # Convert numbers to count of binary 1s
    binary_ones = [bin(num).count('1') for num in arr]
    
    # Dictionary to store first occurrences of cumulative differences
    index_map = {0: -1}
    max_length = 0
    even_sum, odd_sum = 0, 0

    for i in range(len(binary_ones)):
        if i % 2 == 0:
            even_sum += binary_ones[i]
        else:
            odd_sum += binary_ones[i]

        # Compute the difference
        diff = even_sum - odd_sum

        # If this difference has been seen before, calculate subarray length
        if diff in index_map:
            max_length = max(max_length, i - index_map[diff])
        else:
            index_map[diff] = i

    return max_length

# Example usage
arr1 = [8, 3, 15, 1, 6, 10, 5, 2]
arr2 = [12, 23, 34, 45, 56, 67, 78, 89, 90]

print(longest_balanced_subarray(arr1))  # Output: 5
print(longest_balanced_subarray(arr2))  # Output: 9
