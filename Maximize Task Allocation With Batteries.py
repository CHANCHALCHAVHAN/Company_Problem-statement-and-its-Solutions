'''
Problem Statement
You are given a set of tasks with specific energy requirements and a set of batteries with varying power capacities.

Each task can only be allocated to one battery, and each battery can only be used for one task.
Find the maximum number of tasks that can be completed by assigning each task to a compatible battery such that the task's energy requirement does not exceed the battery's power supply.

Input Format
The first line contains two space-separated integers N and M representing a number of tasks and the batteries respectively.
The second line contains N space-separated integers representing the energy requirements of the tasks.
The third line contains M space-separated integers representing the power supplies of the batteries

Output Format
Print an integer representing the maximum number of tasks that can be completed.

 
Constraints
1 <= N, M <= 20

Values in both arrays can be range from 1 to 1000.

Sample Testcase 0
Testcase Input
3 3
5 3 7
4 6 2
Testcase Output
2
Explanation
We have 3 tasks and 3 batteries. Given the enegy requirements of each task and power supply of each batteries : 
Only Task 1 and task 2 can be completed using batteries of power 6 and 4 respectively. 
Task 3 needed 7 power of energy which can not be fulfilled by available batteries.

Sample Testcase 1
Testcase Input
3 3
8 6 9
5 3 7
Testcase Output
1
Explanation
We have 3 tasks and 3 batteries. Given the enegy requirements of each task and power supply of each batteries : 
Only Task 2 can be completed using battery of power 7 
Task 1 and task 3 needed 8 and 9 power of energy which can not be fulfilled by available batteries .
'''
def max_tasks_completed(n, m, tasks, batteries):
    tasks.sort()      # Sort tasks by required energy
    batteries.sort()  # Sort batteries by power capacity

    task_index = 0  # Pointer for tasks
    battery_index = 0  # Pointer for batteries
    completed_tasks = 0  # Count of completed tasks

    while task_index < n and battery_index < m:
        if tasks[task_index] <= batteries[battery_index]:  
            completed_tasks += 1  # Task can be completed
            task_index += 1  # Move to next task
            battery_index += 1  # Move to next battery
        else:
            battery_index += 1  # Find a suitable battery

    return completed_tasks

# Read input
n, m = map(int, input().split())
tasks = list(map(int, input().split()))
batteries = list(map(int, input().split()))

# Compute and print result
print(max_tasks_completed(n, m, tasks, batteries))

