/*
Problem Statement
You work in a cloth-making factory where large fabric rolls are used to manufacture N clothing items. Each item requires a specific length of fabric. You have M rolls, each with a fixed length of fabric.

You need to assign exactly one roll per clothing item such that:

The roll must not be reused.

The roll assigned to an item must have at least the length required for that item.

The wasted fabric (unused fabric from assigned rolls) is minimized.

Write a program to calculate the minimum total waste after optimally assigning the rolls to the items. If it is not possible to assign all items a suitable roll, return -1.

Input Format
First line contains two integers N and M.

Second line contains N space-separated integers: Lengths of fabric required for each clothing item.

Third line contains M space-separated integers: Lengths of available fabric rolls.

Output Format
Print the minimum total waste after assignment, or -1 if not possible.

Constraints
1 ≤ N ≤ 10^3

N ≤ M ≤ 10^4

1 ≤ Required fabric per item ≤ 10^4

1 ≤ Roll lengths ≤ 10^4

Sample Testcase 0
Testcase Input
3 5  
4 8 6  
5 10 7 8 6
Testcase Output
1
Explanation
Required fabric for items: [4, 8, 6]
Available rolls: [5, 10, 7, 8, 6]


Sorted:


Items = [4, 6, 8]


Rolls = [5, 6, 7, 8, 10]


Assignments:


4 → 5 (waste = 1)


6 → 6 (waste = 0)


8 → 8 or 10 (choose 8, waste = 0)


Total waste = 1 + 0 + 0 = 1

Sample Testcase 1
Testcase Input
4 4  
7 5 6 4  
3 6 6 5
Testcase Output
-1
Explanation
Required items: [7, 5, 6, 4]
Rolls: [3, 6, 6, 5]


Sorted:


Items = [4, 5, 6, 7]


Rolls = [3, 5, 6, 6]


Assignments:


4 → 5 (waste = 1)


5 → 6 (waste = 1)


6 → 6 (waste = 0)


7 → No roll is ≥ 7


So, it's impossible to fulfill all requirements.

Companies
Topics
Greedy
Sorting
Binary Search
Array
Resource Allocation
Optimization
Implement
Greedy Algorithms, Implementation
*/
