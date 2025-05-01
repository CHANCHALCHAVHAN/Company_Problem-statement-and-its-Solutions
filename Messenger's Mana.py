'''
PROBLEM STATEMENT::==>
In Unstop's  magical kingdom, a messenger must navigate a treacherous enchanted grid to deliver an urgent message to the royal palace. The grid is an ancient map, where each cell contains a rune that dictates the direction of movement:

a: Move 1 unit right; b: Move 1 unit left; c: Move 1 unit down; d: Move 1 unit up.

The messenger starts at the top-left corner of the map (0, 0) and must reach the palace at the bottom-right corner (m−1,n−1). However, the map's runes have been corrupted over time, and not all paths lead to the destination.

The messenger can use his magical power  to alter any rune, but each alteration consumes precious mana, costing 1 unit per change. The messenger must find the minimum mana required to adjust the map so that at least one path leads to the palace.

Will the messenger succeed in delivering the message in time? Your task is to determine the minimum mana required to ensure they reach their destination!

Input Format
The first line contains two space separated integers M and N, representing the rows and columns of the grid.

The next N line each containing M values, a, b c, d.

Output Format
Print an integer representing the minimum cost (mana) required to ensure there is at least one valid path from the top-left corner to the bottom-right corner.

Constraints
1 <= M, N <= 10^3

Sample Testcase 0
Testcase Input
3 3
a a b
c a d
b b c
Testcase Output
2
Explanation
Starting from the top-left cell (0, 0):
Cell (0, 0): a (right), no cost to move to (0, 1).
Cell (0, 1): a (right), no cost to move to (0, 2).
Cell (0, 2): b (left), modify to move down to (1, 2) at a cost of 1.
Cell (1, 2): d (up), modify to move down to (2, 2) at a cost of 1.
Cell (2, 2): Destination reached.

Sample Testcase 1
Testcase Input
4 4
a b c d
b b a c
c c d b
d a a a
Testcase Output
2
Explanation
Cell (0, 0): a (right), no cost to move to (0, 1).
Cell (0, 1): b (left), modify to move down to (1, 1) at a cost of 1.
Cell (1, 1): b (left), modify to move down to (2, 1) at a cost of 1.
Cell (2, 1): c (down), no cost to move to (3, 1).
Cell (3, 1): a (right), no cost to move to (3, 2).
Cell (3, 2): a (right), no cost to move to (3, 3).
Cell (3, 3): Destination reached.
'''
'''
Companies
Google
Barclays
Facebook
nvidia
Goldman Sachs
Amazon
'''
'''
Topics
Grid Traversal
Dynamic Programming
BFS
Graph Theory
Matrix
'''


#CODE=>
from collections import deque

def min_mana_to_reach_destination(grid, m, n):
    directions = {'a': (0, 1), 'b': (0, -1), 'c': (1, 0), 'd': (-1, 0)}
    cost = [[float('inf')] * n for _ in range(m)]
    cost[0][0] = 0
    queue = deque([(0, 0, 0)])  # (row, col, current_cost)
    
    while queue:
        x, y, current_cost = queue.popleft()
        
        for dir_key, (dx, dy) in directions.items():
            nx, ny = x + dx, y + dy
            
            # Check bounds
            if 0 <= nx < m and 0 <= ny < n:
                # Calculate the cost of moving to (nx, ny)
                new_cost = current_cost + (grid[x][y] != dir_key)
                if new_cost < cost[nx][ny]:
                    cost[nx][ny] = new_cost
                    queue.append((nx, ny, new_cost))
                    
    return cost[m-1][n-1]

# Input handling
m, n = map(int, input().split())
grid = [input().split() for _ in range(m)]

# Find the minimum mana required
result = min_mana_to_reach_destination(grid, m, n)
print(result)
