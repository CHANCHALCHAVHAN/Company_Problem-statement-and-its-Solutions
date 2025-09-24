'''
Problem Statement
You are in charge of an island where a rare species of turtle resides. The turtles live in colonies, and their locations are marked on a 2D grid. The grid has three types of cells:

'T' → A turtle colony that must be rescued.

'.' → Walkable land.

'#' → Inaccessible terrain.

You are provided with a starting point (Sx, Sy) — your rescue vehicle’s current position. The rescue vehicle can move up, down, left, or right, but cannot move through #.

However, to reduce environmental disturbance, each turtle colony can only be visited once and must be rescued in a single connected path — you must not return to the base after rescuing one and then go to the next. Your task is to find the minimum total number of steps required to rescue all the turtles in a single traversal path, starting from your vehicle.

If it's not possible to reach and rescue all colonies, return -1.

Input Format
First line contains two integers N and M

Next N lines: A string of length M representing the grid (only contains 'T', '.', and '#').

Last line contains two integers Sx and Sy.

 

Output Format
Print the minimum number of steps to rescue all turtles, or -1 if not possible.

Constraints
1 ≤ N, M ≤ 20

Grid contains at most 10 turtle colonies.

0 ≤ Sx < N, 0 ≤ Sy < M

Sample Testcase 0
Testcase Input
4 5
.T..T
..#.#
#.T..
.#...
0 0
Testcase Output
8
Explanation
Turtle positions:


(0,1), (0,4), (2,2)
Start position: (0,0)


Grid layout:
.T..T
..#.#
#.T..
.#...


Path (minimum steps):


(0,0) → (0,1) [1] → (1,1) [2] → (2,1) [3] → (2,2) [4]


→ (2,3) [5] → (1,3) [6] → (0,3) [7] → (0,4) [8]


All 3 turtles collected in 8 steps.

Sample Testcase 1
Testcase Input
3 3
T#T
.#.
T#T
1 1
Testcase Output
-1
Explanation
Turtle positions: (0,0), (0,2), (2,0), (2,2)
Start: (1,1)


Grid layout:
T # T
. # .
T # T



There’s no path to any of the turtle colonies — they are all isolated by # walls.


Hence, not all turtles can be rescued. Output: -1





Companies
Topics
Graphs
Breadth-First Search
Bitmask
Shortest Path
Backtracking
Data Structure
Graph Theory


''''
from collections import deque
import sys

def bfs(grid, start, N, M):
    """Returns shortest distances from start to all other cells"""
    dist = [[-1]*M for _ in range(N)]
    q = deque()
    q.append(start)
    dist[start[0]][start[1]] = 0

    while q:
        x, y = q.popleft()
        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < N and 0 <= ny < M and grid[nx][ny] != '#' and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx, ny))
    return dist

def turtle_rescue(N, M, grid, Sx, Sy):
    turtles = []
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 'T':
                turtles.append((i,j))

    K = len(turtles)
    if K == 0:
        return 0

    # Index mapping: 0 = start, 1..K = turtles
    points = [(Sx, Sy)] + turtles
    dist_matrix = [[-1]*(K+1) for _ in range(K+1)]

    # Precompute distances between all points
    for i in range(K+1):
        d = bfs(grid, points[i], N, M)
        for j in range(K+1):
            dist_matrix[i][j] = d[points[j][0]][points[j][1]]

    # Check if all turtles are reachable
    for i in range(1, K+1):
        if dist_matrix[0][i] == -1:
            return -1

    # DP[mask][i] = min steps to visit mask ending at turtle i
    dp = [[sys.maxsize]*(K+1) for _ in range(1<<K)]
    for i in range(1, K+1):
        if dist_matrix[0][i] != -1:
            dp[1<<(i-1)][i] = dist_matrix[0][i]

    for mask in range(1<<K):
        for u in range(1, K+1):
            if not (mask & (1<<(u-1))):
                continue
            for v in range(1, K+1):
                if mask & (1<<(v-1)) or dist_matrix[u][v] == -1:
                    continue
                next_mask = mask | (1<<(v-1))
                dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + dist_matrix[u][v])

    full_mask = (1<<K) - 1
    return min(dp[full_mask][i] for i in range(1, K+1))

# Input parsing
if __name__ == "__main__":
    N, M = map(int, input().split())
    grid = [input().strip() for _ in range(N)]
    Sx, Sy = map(int, input().split())
    print(turtle_rescue(N, M, grid, Sx, Sy))
