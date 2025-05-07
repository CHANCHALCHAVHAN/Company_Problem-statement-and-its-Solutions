'''
Problem Statement
A secret research facility is built underground in the form of a massive rectangular labyrinth. The labyrinth is made up of N rows and M columns. Each cell in the labyrinth contains a mirror that can rotate every hour to point in one of four directions — up (U), down (D), left (L), or right (R). The mirrors have a special property: they reflect light only in the direction they're currently pointing, and can redirect a light beam to the next cell in that direction.

Every hour, some mirrors shift their direction clockwise — U → R → D → L → U... — but the exact pattern of this rotation is unknown to you. However, you are given a snapshot of the labyrinth at hour 0 as a 2D grid of size N x M with each cell showing its current direction (U, D, L, or R).

You are also given a list of laser positions, where a laser starts at a certain cell and attempts to escape the labyrinth by following the reflections. The laser continues moving in the direction of the current mirror until:

It either exits the grid, OR

It enters a loop (i.e., visits the same cell again), in which case it is trapped forever.

Your job is to determine, for each laser starting position, whether it escapes or gets trapped, assuming the mirrors never rotate after the initial state (hour 0 snapshot).

Input Format
First line congtains two space separated integer N and M, representing the dimensions of the labyrinth.

From 2nd line to Nth line contains a 2D character matrix of size N x M where each cell is one of {'U', 'D', 'L', 'R'}.

Next line contains an integer Q, representing the number of laser start positions.

Next Q lines, each contains pairs of integers (x, y) (0-indexed), representing the start cell of each laser.

Output Format
For each of the Q laser queries, output "ESCAPED" if the laser exits the labyrinth and "TRAPPED" if it gets stuck in a loop.

Constraints
1 ≤ N, M ≤ 1000

1 ≤ Q ≤ 10^5

Sample Testcase 0
Testcase Input
4 4
R R D L
U L D D
R U L R
U D U U
3
0 0
1 1
3 3
Testcase Output
TRAPPED
TRAPPED
ESCAPED
Explanation
Query 1: (0,0)


Path:
(0,0) → (0,1) → (0,2) → (1,2) → (2,2) → (2,1) → (1,1) → (1,0) → (0,0) (Repeat)
Result: TRAPPED


Query 2: (1,1)


Path:
(1,1) → (1,0) → (0,0) → (0,1) → (0,2) → (1,2) → (2,2) → (2,1) → (1,1) Repeat
Result: TRAPPED


Query 3: (3,3)


Path:
(3,3) → (2,3) → (2,4) (out of bounds)
Result: ESCAPED

Sample Testcase 1
Testcase Input
5 6
R R D D L L
U U R D R D
R L D L U R
U R L U R U
D D U R L U
4
0 0
1 4
3 1
4 5
Testcase Output
TRAPPED
ESCAPED
TRAPPED
ESCAPED
Explanation
Query 1: Start at (0,0)


Path:
(0,0) → (0,1) → (0,2) → (1,2) → (1,3) → (2,3) → (2,2) → (3,2) → (3,1) → (3,2) Repeat
Cycle Detected
Result: TRAPPED


Query 2: Start at (1,4)


Path:
(1,4) → (1,5) → (2,5) → (2,6) (out of bounds)
Result: ESCAPED


Query 3: Start at (3,1)


Path:
(3,1) → (3,2) → (3,1) Repeat
Immediate loop
Result: TRAPPED


Query 4: Start at (4,5)


Path:
(4,5) → (3,5) → (2,5) → (2,6) 
Result: ESCAPED

Companies
Meesho
Goldman Sachs
Paypal
Topics
DFS
Memoization
Hashing
Cycle Detection
Simulation
Grid Traversal
Greedy
Graph

'''
def is_escaped_or_trapped(grid, start_x, start_y):
    directions = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
    visited = set()
    
    x, y = start_x, start_y
    
    while (x, y) not in visited:
        if not (0 <= x < len(grid) and 0 <= y < len(grid[0])):
            return "ESCAPED"
        
        visited.add((x, y))
        dx, dy = directions[grid[x][y]]
        x += dx
        y += dy
        
    return "TRAPPED"

# Read input
n, m = map(int, input().split())
grid = [input().split() for _ in range(n)]

q = int(input())
queries = [tuple(map(int, input().split())) for _ in range(q)]

# Process queries
for x, y in queries:
    print(is_escaped_or_trapped(grid, x, y))
