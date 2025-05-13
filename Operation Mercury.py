'''
Problem Statement
Agent Smith is in a chamber that's like a grid (H X W), and each cell in this grid has a certain height. The chamber is currently filled with a toxic substance, mercury. The mercury is leaking from a specific cell and spreads horizontally and vertically until it encounters cells with heights greater than or equal to its own potency .  If the height of the cell is greater than or equal to the potency then mercury will not leak.

The task is to find out, for each combination of potency and origin cell provided, how many cells in the chamber are affected by the mercury leak.

For instance, given a specific potency and origin cell, the task is to determine how far the mercury spreads horizontally and vertically until it encounters cells with heights greater than or equal to its own potency.

Here, H and W are denoting height and width of the grid, where in each row the height of the cell is given.

Input Format
The first line of each test case contains three integers: H, W, and Q. These represent the height, width, and number of queries (combinations of potency and origin cell) respectively.

The next line contains H lines, each containing W space-separated integers denoting the heights of cells in the grid.

Following that, each of the Q lines contains three integers: r[i], c[i], and p[i], representing the  origin cell(row, column) and potency of the mercury leak for each query.

Output Format
Display Q space separated integers representing the number of hazardous cells reached by the mercury leak for the corresponding combination.

Constraints
1 ≤ H, W ≤ 1000
1 ≤ Q ≤ 2*10^5
1 ≤ r[i] ≤ H
1 ≤ c[i] ≤ W
0 ≤ A[i][j] ≤ 10^9 (height of cells)
0 ≤ p[i] ≤ 10^9 (potency of mercury leak)
Sample Testcase 0
Testcase Input
5 5 3 
4 3 9 7 2
8 6 5 2 8
1 7 3 4 3
2 2 4 5 6
9 9 9 9 9 
3 4 6 
3 2 5 
1 4 9
Testcase Output
10 0 19
Explanation
There are 3 queries provided.


Query 1: Starting from cell (3, 4) with a potency of 6.


The cell (3,4) has a height of 4, which is smaller than the potency (6). Therefore, the mercury spread horizontly and vertically until it reaches cells with heights less than the potency before dissipating.





 


It reaches 10 cells (origin cell included) before dissipating.


Query 2: Starting from cell (3,2) with a potency of 5.
The cell (3, 2) has a height of 7, which is greater than the potency (5). Therefore, the mercury dissipates immediately, and no other cells are affected. Thus, the output for this query is 0.

Similarly, we can calculate for Qyery 3.

Sample Testcase 1
Testcase Input
3 3 2
2 4 3
1 5 6
3 1 7
1 2 3
2 3 4
Testcase Output
0 0
Explanation
We have a grid with dimensions 3x3, where each cell has a corresponding height:


There are 2 queries in this test case:


Mercury leak originates from cell (1, 2) with a potency of 3.


Mercury leak originates from cell (2, 3) with a potency of 4.


Starting with the first query:


The cell (1, 2) has a height of 4, which is greater than the potency (3). Therefore, the mercury dissipates immediately, and no other cells are affected. Thus, the output for this query is 0.


Moving on to the second query:


The cell (2, 3) has a height of 6, which is greater than the potency (4). Again, the mercury dissipates immediately, and no other cells are affected. Thus, the output for this query is also 0.

Companies
Topics
BFS
Graph
Graph
'''


#CODE::=>
from collections import deque

def mercury_spread(grid, h, w, queries):
    results = []
    
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Right, Down, Left, Up
    
    for r, c, p in queries:
        r -= 1  # Convert to 0-based index
        c -= 1
        
        if grid[r][c] >= p:
            results.append(0)
            continue
        
        visited = set()
        queue = deque([(r, c)])
        visited.add((r, c))
        affected_cells = 0
        
        while queue:
            x, y = queue.popleft()
            affected_cells += 1
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < h and 0 <= ny < w and (nx, ny) not in visited and grid[nx][ny] < p:
                    visited.add((nx, ny))
                    queue.append((nx, ny))
        
        results.append(affected_cells)
    
    return results

# Reading input
h, w, q = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(h)]
queries = [tuple(map(int, input().split())) for _ in range(q)]

# Processing queries
output = mercury_spread(grid, h, w, queries)

# Printing results
print(" ".join(map(str, output)))
