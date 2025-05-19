'''
Problem Statement
You are appointed as a manager in a school, and you are asked to design a school attendance system that requires the following requirements:
Each student is given a roll number from 1 to N, as N students study there. Now each of the students performs the following action a single time in this order:
If the student’s i’s roll number has not been called out yet, then he calls out student A[i]’s roll number.
Your system should return all the roll numbers of all the students whose roll numbers are never called out until the end in sequential order.

Input Format
The first Line contains two integers N representing the size of the array.
The second line contains N integers representing elements of the array.

Output Format
Return all the roll numbers of all the students whose roll numbers are never called out until the end in sequential order.

Constraints
2 <= N <= 10^5.
1 <= A[i] <= N.

Sample Testcase 0
Testcase Input
2
2 1
Testcase Output
1
Explanation
Student 1 ID is not called out until the end.
Sample Testcase 1
Testcase Input
5
3 1 4 5 4
Testcase Output
2 4
Explanation
The five students’ actions are as follows.

Student 1's ID has not been called out yet, so student 1 calls out student 3's ID.

Student 2's ID has not been called out yet, so student 2 calls out student 1's ID.

Student 3's ID has already been called out by student 1, so nothing happens.

Student 4's ID has not been called out yet, so student 4 calls out student 5's ID.

Student 5's ID has already been called out by student 4, so nothing happens.

Therefore, student 2 and 4's IDs are not called out until the end.
Companies
Uber
Topics
Array
Boolean Operations
Design

'''
#CODE:->
def find_uncalled_students(N, A):
    called_out = set()
    
    # Mark all called-out roll numbers
    for roll_number in A:
        called_out.add(roll_number)
    
    # Find students whose roll numbers were never called out
    uncalled_students = [i for i in range(1, N + 1) if i not in called_out]
    
    return uncalled_students

# Input handling
N = int(input())  # Read the number of students
A = list(map(int, input().split()))  # Read the list of roll numbers called out

# Function call and result output
result = find_uncalled_students(N, A)
print(*result)  # Print the result in space-separated format
