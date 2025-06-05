'''
Problem Statement
You are the chief engineer for the city's electricity board in Pune. A recent thunderstorm has caused significant damage to the city’s power grid. While emergency teams have managed to identify and restore several working connections, many power cables are still down, leading to partial blackouts in various neighborhoods.

The city has n power stations (numbered from 1 to n), and only m power cables are currently operational. Each working cable connects exactly two power stations and ensures electricity can flow between them. Due to the damaged infrastructure, some stations are no longer connected to others, resulting in isolated groups.

Your job is to determine how many completely disconnected regions exist in the city. A region is defined as a group of power stations that are still connected directly or indirectly through working cables, but not connected to any station outside the group.

Help the city's recovery efforts by calculating the number of such disconnected power regions.

Input Format
First line: Two integers n and m — number of power stations and number of working cables.

Next m lines: Each line has two integers u and v denoting a cable connecting station u and station v.
Output Format
A single integer — the number of disconnected power regions.

Constraints
1 <= n <= 10^5

0 <= m <= 2*10^5

1 <= u, v <= n
Sample Testcase 0
Testcase Input
6 4
1 2
2 3
4 5
5 6
Testcase Output
2
Explanation
There are two groups of connected stations:



Group 1: 1-2-3


Group 2: 4-5-6



They are disconnected from each other, so the answer is 2.

Sample Testcase 1
Testcase Input
5 0
Testcase Output
5
Explanation
No cables work, so every station is its own region. Hence, 5 regions.

Companies
Topics
Graph Theory
BFS
Simulation
Graph
'''
def count_disconnected_regions(n, connections):
    from collections import defaultdict

    # Build adjacency list
    graph = defaultdict(list)
    for u, v in connections:
        graph[u].append(v)
        graph[v].append(u)

    # Function to perform DFS
    def dfs(node, visited):
        stack = [node]
        while stack:
            current = stack.pop()
            for neighbor in graph[current]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    stack.append(neighbor)

    visited = set()
    disconnected_regions = 0

    # Check all stations
    for station in range(1, n + 1):
        if station not in visited:
            visited.add(station)
            dfs(station, visited)
            disconnected_regions += 1

    return disconnected_regions

# Read input
n, m = map(int, input().split())
connections = [tuple(map(int, input().split())) for _ in range(m)]

# Output the result
print(count_disconnected_regions(n, connections))
