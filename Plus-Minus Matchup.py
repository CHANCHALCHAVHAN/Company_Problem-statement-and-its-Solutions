'''
Problem Statement
You are a software developer tasked with creating a video game for a new console that only has two buttons, each with a number written on it. The game is composed of n rounds, and for each round, a symbol appears on the screen, which is either + (plus) or - (minus). The player must press one of the two buttons on the controller once, and their score will increase by the number on the button they pressed if the symbol was +, and decrease by the number if the symbol was -

The goal of the game is for the player to reach a score of 0. For Each test case, You have to write a function that takes in the number of rounds, the symbols for each round, and the numbers on the buttons of a controller and determines whether the game is winnable using that controller.

Your function should take in the following inputs:

N: an integer, the number of rounds
s: a string of length n, where si is the symbol that will appear on the screen in the i-th round. It is guaranteed that s contains only the characters + and -.
Aj: an integer, the number on the first button of the controller
Bj: an integer, the number on the second button of the controller
For each test case, your function should return a boolean value: YES if the game is winnable using the controller, and NO otherwise.

Input Format
The first line contains a single integer N  — the number of rounds.

The second line contains a string s of length n— where si is the symbol that will appear on the screen in the i-th round. It is guaranteed that s contains only the characters + and -.

The third line contains an integer q (1≤q≤1e5) — the number of controllers.

The following q lines contain two space-separated integers Aj and Bj each (1≤Aj,Bj≤1e9) — the numbers on the buttons of controller j.

Output Format
Output q lines. On line j print YES if the game is winnable using controller j, otherwise print NO

Constraints
1<=N<=2*10^5

1<=q<=10^5

1<=Ai,Bi<=10^9

Sample Testcase 0
Testcase Input
8
+-+---+-
5
2 1
10 3
7 9
10 10
5 3
Testcase Output
YES
NO
NO
NO
YES
Explanation
For the first round there is a possible sequence on which we can get zero, one possible way to get score 0 using the first controller is by pressing the button with number 1  in rounds 1, 2, 4, 5, 6 and 8, and pressing the button with number 2 in rounds 3 and 7.
For the second round there is no possible sequence so that answer is zero.
For the third round there is no possible sequence so that answer is zero.
For the fourth round there is no possible sequence so that answer is zero.
For the fifth test case there is a possible solution.
Sample Testcase 1
Testcase Input
20
+-----+--+--------+-
2
1000000000 99999997
250000000 1000000000
Testcase Output
NO
YES
Explanation
For the first round there is no possible combination so the answer is No.
For the second round there is possible combination so the answer is Yes
Companies
Zoho
VMware
Topics
Array
Math
String Manipulation
Strings

'''
def is_winnable(N, s, A, B):
    possible_sums = {0}  # Start with an initial sum of 0
    for i in range(N):
        next_sums = set()
        for val in possible_sums:
            if s[i] == '+':
                next_sums.add(val + A)
                next_sums.add(val + B)
            else:
                next_sums.add(val - A)
                next_sums.add(val - B)
        possible_sums = next_sums  # Update possible sums
    return "YES" if 0 in possible_sums else "NO"

# Read input values
N = int(input().strip())
s = input().strip()
q = int(input().strip())

# Iterate over each controller and check if the game is winnable
for _ in range(q):
    A, B = map(int, input().strip().split())
    print(is_winnable(N, s, A, B))

