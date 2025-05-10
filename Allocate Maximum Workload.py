'''
Problem Statement
You are given an array tasks[] of integers, where each element tasks[i] represents the time (in minutes) required to complete the i-th task. You also have an integer W representing the number of workers available. The task is to allocate tasks to each worker such that:

Each worker gets at least one task.

Each worker is assigned a contiguous sequence of tasks.

No task is assigned to more than one worker.

The objective is to maximize the minimum workload among all workers. In other words, find the allocation where the worker with the least workload gets the maximum possible workload.

Input Format
An integer n denoting the number of tasks.

An array tasks[] of size N, where tasks[i] represents the time required for the i-th task.

An integer W representing the number of available workers.

Output Format
Print a single integer, which is the maximum possible minimum workload that a worker can have under an optimal task allocation.

Constraints
1 ≤ N ≤ 10^6

1 ≤ tasks[i] ≤ 10^3

1 ≤  W  ≤ 10^3

Sample Testcase 0
Testcase Input
4
20 30 40 50
2
Testcase Output
90
Explanation


Possible allocations:




[20, 30] & [40, 50] → Max pages = 90 ✅ (Optimal)




[20, 30, 40] & [50] → Max pages = 90






Minimum possible max pages = 90



Sample Testcase 1
Testcase Input
5
10 20 30 40 50
3
Testcase Output
60
Explanation


Possible allocations:




[10, 20] & [30] & [40, 50] → Max pages = 90




[10, 20, 30] & [40] & [50] → Max pages = 60 ✅ (Optimal)






Minimum possible max pages = 60



Companies
Topics
Searching
Divide and Conquer
Data structure and algorithm
Divide and Conquer
'''


#CODE:=>
def is_valid_allocation(tasks, workers, max_workload):
    allocated_workers = 1
    current_workload = 0

    for task in tasks:
        if current_workload + task > max_workload:
            allocated_workers += 1
            current_workload = task
            if allocated_workers > workers:
                return False
        else:
            current_workload += task

    return True

def maximize_minimum_workload(tasks, workers):
    left, right = max(tasks), sum(tasks)
    best_workload = left

    while left <= right:
        mid = (left + right) // 2
        if is_valid_allocation(tasks, workers, mid):
            best_workload = mid
            right = mid - 1
        else:
            left = mid + 1

    return best_workload

# Read input
N = int(input())
tasks = list(map(int, input().split()))
W = int(input())

# Compute and print the result
print(maximize_minimum_workload(tasks, W))
