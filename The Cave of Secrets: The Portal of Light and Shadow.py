'''
Problem Statement
Aric, the daring explorer, was deep inside a mysterious cave when he discovered a glowing portal. However, the portal was sealed by two powerful rods, one of Light and the other of Shadow. To unlock the portal and enter another world, Aric needed to arrange these rods in a specific way.

The rods were represented by two characters: ‘l’ for Light and ‘s’ for Shadow. The portal’s magic required that the rods be placed in an alternating sequence (l,s,l,s... or s,l,s,l...): no two Light rods or two Shadow rods could be next to each other.

If the rods were not in one of these alternating sequences, the portal would remain locked, and Aric would be unable to enter.

Aric has some of the rods with him, he can perform two types of operations to open the portal: Swap the positions of any two rods and Change the type of a rod, changing ‘l’ to ‘s’ or ‘s’ to ‘l’.

However, each operation took time, and Aric needed to minimize the number of changes to open the portal as quickly as possible.

Your task is to help Aric figure out the minimum number of operations required to rearrange the rods into one of the alternating patterns so that the portal will open.

Can you solve the puzzle and help Aric escape the cave to enter the new dimension?

 

Input Format
The first line contains an integer N, the number of rods in the sequence.

The second line contains a string S of length N consisting of characters ‘l’ (for Light) and ‘s’ (for Shadow), representing the rods.

Output Format
Output a single integer, the minimum number of operations required to transform the sequence into one of the alternating patterns.

Constraints
1 <= N <= 10^3

Sample Testcase 0
Testcase Input
6
lsslss
Testcase Output
2
Explanation
In this case, we can first achieve the desired alternating pattern of rods in 2 operation in this way:


In the first adjustment, swap the first and second rods. This will take 1 operation and the resultant sequence will be “slslss”.


In the second adjustment, change the type of the 6th rod i.e Shadow to Light. It will also take 1 opertion and the final sequence will be “slslsl” which is an alternating sequence as desired.

Sample Testcase 1
Testcase Input
3
lls
Testcase Output
1
Explanation
Either eric will swap, or change the 1st light rod to shadow, it will take only 1 operation to unlock the portal.

Companies
Amazon
Adobe
Goldman Sachs
Topics
String Manipulation
Greedy Algorithm
Data Structures & Algorithms
Suggested Questions
'''

#code::=>
def min_operations_to_alternate(n, s):
    def count_ops(expected_start):
        mismatch_even = mismatch_odd = 0
        for i in range(n):
            expected_char = expected_start if i % 2 == 0 else ('s' if expected_start == 'l' else 'l')
            if s[i] != expected_char:
                if i % 2 == 0:
                    mismatch_even += 1
                else:
                    mismatch_odd += 1
        swaps = min(mismatch_even, mismatch_odd)
        changes = abs(mismatch_even - mismatch_odd)
        return swaps + changes

    return min(count_ops('l'), count_ops('s'))

# Input reading
n = int(input())
s = input().strip()

# Output result
print(min_operations_to_alternate(n, s))
