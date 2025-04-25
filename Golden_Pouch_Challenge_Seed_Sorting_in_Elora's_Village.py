'''
PROBLEM STATEMENT
Problem Statement
In a quiet village, a wise elder named Elora tasked the young villagers with an unusual challenge to test their teamwork and mathematical skills. Here's the challenge:

The villagers were divided into groups of k, where k is a number chosen at random. Each group had to calculate the average number of seeds in the apples they get. However, the task had an odd twist:

If the average number of seeds per group was an even number, they would place the average into a golden pouch(linked list) for the village's ceremonial tree planting.
If the average was an odd number, the seeds were discarded, and the group moved on.
If there were fewer apples left than the group size k, they were to simply collect all the remaining apples and add their seeds to the pouch as they were, without calculating any average.
Can you determine the final list (linked list) of seeds in the golden pouch based on this challenge?

Note: To add more structure to the challenge, the groups were required to move in a straight line. This meant the first group would take the first k apples, complete their task, and place their result in the pouch before the second group started with the next k apples, and so on.

Note: You have to take the floor of average

Input Format
The first line contains an integer K, the group size.

The second line contains an integer N the number of apples.

The third line contains N space separated integers, the number of seeds in each apple.

Output Format
Print the linked list of seeds collected in the golden pouch. Each node in the linked list represents a seed value, with the last node pointing to null.

Don't print any trailing space after the "null".

Constraints
1 <= N <= 10^5

1 <= K <= 10^5

1 <= seeds in each apple <= 10^5

Sample Testcase 0
Testcase Input
2
5
1 2 3 4 5
Testcase Output
5 null
Explanation
The groups are formed as:
Group 1: [1, 2] (average is 1, odd, so discarded)
Group 2: [3, 4] (average is 3, odd, so discarded)
Group 3: [5] (less than k, so all seeds are collected without averaging)
The result is that the seeds in the last group (5) are added to the golden pouch. The output will be: 5 null

Sample Testcase 1
Testcase Input
3
10
2 4 6 8 10 3 5 7 9 11
Testcase Output
4 11 null
Explanation
The groups are formed as:
Group 1: [2, 4, 6] (average is 4, even, so added to the pouch)
Group 2: [8, 10, 3] (average is 7, odd, so discarded)
Group 3: [5, 7, 9] (average is 7, odd, so discarded)
Group 4: [11] (less than k, so all seeds are collected without averaging)
The seeds in the groups with even averages (Group 1) and the last group (Group 4) are added to the golden pouch. 
The output will be: 4 11 null
'''
'''
Companies
Paypal
Accenture
MAQ Software
'''
'''
Topics
Linked List
Singly Linked List
Average
Data Structures & Algorithms
'''

##CODE :=>
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" ")
        current = current.next
    print("null")

def process_apples(k, n, seeds):
    result = []
    i = 0
    while i < n:
        group = seeds[i:i + k]
        if len(group) < k:  # If remaining apples are less than group size
            result.extend(group)
        else:
            average = sum(group) // k  # Floor division
            if average % 2 == 0:  # Even average
                result.append(average)
        i += k

    linked_list_head = create_linked_list(result)
    return linked_list_head

# Input
k = int(input())
n = int(input())
seeds = list(map(int, input().split()))

# Processing
head = process_apples(k, n, seeds)

# Output
print_linked_list(head)
