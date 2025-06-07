'''
Problem Statement
You are trapped in a cursed maze represented as an N x M grid. Each cell (i, j) has:

0: An empty path.

-1: A cursed wall (cannot pass).

X > 0: A magical rune that grants X points but curses you for X steps (you cannot pick up another rune until X steps have passed).

You start at (0, 0) and must reach (N-1, M-1) while maximizing your total rune points. Movement is allowed in 4 directions (up, down, left, right).

Challenge: Find the maximum points you can collect without violating the curse constraints.

Input Format
The first line contain two integers N & M (dimensions of the maze).

Next N lines each containing M space-separated integers representing the maze grid.

Output Format
1 ≤ N, M ≤ 100

0 ≤ X ≤ 10 (rune values)

It is guaranteed that (0, 0) and (N-1, M-1) are not cursed walls.

Constraints
Print a single integer: Maximum points collected, or -1 if the exit is unreachable.

Sample Testcase 0
Testcase Input
3 3
0  2 -1
0 -1  3
0  0  0
Testcase Output
5
Explanation
Take rune 2 at (0,1). Curse lasts 2 steps.
Move to (0,0) → (1,0) → (2,0) (2 steps passed).
Now take rune 3 at (2,1). Total points = 2 + 3 = 5.
Reach (2,2).

Sample Testcase 1
Testcase Input
4 4
0 1 0 0
0 -1 0 0
2 0 -1 0
0 0 0 3
Testcase Output
6
Explanation
Start at (0,0), cooldown=0, points=0.
Move right to (0,1), pick rune 1 → points=1, cooldown=1.
Need to wait 1 step before next rune.
Move down to (1,1) blocked, so instead move down to (1,0), cooldown=0, points=1.
Move down to (2,0), cooldown=0, pick rune 2 → points=3, cooldown=2.


Need to wait 2 steps:
Move right to (2,1), cooldown=1.
Move down to (3,1), cooldown=0.
Move right to (3,2), cooldown=0.
Move right to (3,3), cooldown=0, pick rune 3 → points=6, cooldown=3.


End reached with total points 6.

Topics
BFS
Dynamic Programming
Grid
Graph
'''



from collections import deque

def max_rune_points(maze, N, M):
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    queue = deque([(0, 0, 0, 0)])  # (row, col, points_collected, cooldown_steps)
    visited = {(0, 0, 0)}
    max_points = -1

    while queue:
        row, col, points, cooldown = queue.popleft()

        if (row, col) == (N - 1, M - 1):
            max_points = max(max_points, points)
            continue

        for dr, dc in directions:
            new_row, new_col = row + dr, col + dc

            if 0 <= new_row < N and 0 <= new_col < M and maze[new_row][new_col] != -1:
                new_cooldown = max(0, cooldown - 1)

                if maze[new_row][new_col] > 0 and new_cooldown == 0:
                    new_points = points + maze[new_row][new_col]
                    new_cooldown = maze[new_row][new_col]
                else:
                    new_points = points

                if (new_row, new_col, new_cooldown) not in visited:
                    visited.add((new_row, new_col, new_cooldown))
                    queue.append((new_row, new_col, new_points, new_cooldown))

    return max_points

# Taking user input
N, M = map(int, input("Enter N and M: ").split())
maze = []
print("Enter the grid values row-wise:")
for _ in range(N):
    maze.append(list(map(int, input().split())))

# Executing the function
result = max_rune_points(maze, N, M)
print("Maximum points collected:", result)
