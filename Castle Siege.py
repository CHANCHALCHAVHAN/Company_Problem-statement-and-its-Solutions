'''
Problem Statement
In an ancient kingdom, there are several castles arranged in a grid, and each castle has an associated defense level, representing how difficult it is to siege. The king wants to conquer all castles, but there are special rules that must be followed. The kingdom is in danger, and the king must strategically plan the siege.

You are given a N x M matrix grid where each cell represents a castle with a defense level. The king starts at the top-left corner of the grid (castle (0, 0)) and needs to reach the bottom-right corner (castle (N-1, M-1)).

However, there are constraints:

Movement Rules: You can only move down or right.

Siege Rule: In order to conquer a castle, the king must increase the siege power by a specific amount. The siege power required for each castle is calculated as the maximum defense level encountered along the path from (0, 0) to that castle. The king starts with an initial siege power of 0 and must accumulate siege power by the maximum defense value along the way.

Resource Constraint: The king has a limited amount of resources. At any point, if the king’s siege power exceeds X, he cannot move further. If the siege power is not sufficient to conquer a castle, the king cannot step on that castle.

Input Format
An integer n and m representing the size of the grid (1 ≤ N,M ≤ 1000).

A 2D list grid of size n x m where each element grid[i][j] is an integer representing the defense level of the castle at (i, j) (1 ≤ grid[i][j] ≤ 1000).

An integer X representing the maximum siege power the king can accumulate before running out of resources.

Output Format
The minimum siege power required to conquer the bottom-right corner castle (N-1, M-1) while following the movement and siege rules, or -1 if it is not possible to reach (N-1, M-1) due to resource constraints.

Constraints
1 ≤ N,M ≤ 1000

1 ≤ matrix[i][j] ≤ 10^3 

1 ≤ X ≤ 10^4

Sample Testcase 0
Testcase Input
3 3
1 3 2
4 5 6
7 8 9
10
Testcase Output
9
Explanation
The king starts at (0, 0) with a siege power of 1.


To reach the bottom-right corner (2, 2) with the minimum siege power that does not exceed 10, the optimal path is as follows:


Move right from (0, 0) to (0, 1) with siege power max(1, 3) = 3


Move down from (0, 1) to (1, 1) with siege power max(3, 5) = 5


Move down from (1, 1) to (2, 1) with siege power max(5, 8) = 8


Move right from (2, 1) to (2, 2) with siege power max(8, 9) = 9


The total siege power at (2, 2) is 9, which is the minimum siege power required to reach the bottom-right corner. Since 9 <= X = 10, this path is valid.

Sample Testcase 1
Testcase Input
3 3
1 3 2
4 5 6
7 8 9
8
Testcase Output
-1
Explanation
The king starts at (0, 0) with a siege power of 1.


To reach the bottom-right corner (2, 2) with the minimum siege power that does not exceed 8, the optimal path is as follows:


Move right from (0, 0) to (0, 1) with siege power max(1, 3) = 3


Move right from (0, 1) to (0, 2) with siege power max(3, 2) = 3


Move down from (0, 2) to (1, 2) with siege power max(3, 6) = 6


Move down from (1, 2) to (2, 2) with siege power max(6, 9) = 9


The siege power at (2, 2) is 9, which exceeds the resource limit X = 8. Thus, there is no valid path where the siege power does not exceed X.

Companies
Topics
Binary Search
Graph
BFS
Matrix
Shortest Path
Graph
'''




#Code:=> 

import heapq

def min_siege_power(grid, x):
    n, m = len(grid), len(grid[0])
    directions = [(1, 0), (0, 1)]  # Down and Right movements
    min_heap = [(grid[0][0], 0, 0)]  # (siege power, row, col)
    visited = set()

    while min_heap:
        siege_power, r, c = heapq.heappop(min_heap)

        if (r, c) in visited:
            continue
        visited.add((r, c))

        if r == n - 1 and c == m - 1:
            return siege_power if siege_power <= x else -1

        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m:
                new_siege_power = max(siege_power, grid[nr][nc])
                if new_siege_power <= x:
                    heapq.heappush(min_heap, (new_siege_power, nr, nc))

    return -1

# Example usage:
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
x = int(input().strip())

print(min_siege_power(grid, x))
