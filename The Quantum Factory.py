'''
Problem Statement
In a Quantum Factory, a series of N machines are connected in a directed network. Each machine performs a quantum operation and has an associated internal value. These operations can scale down the energy before passing it on to the next connected machine. The goal is to compute the maximum energy that can be transferred from the starting machine (machine 1) to the ending machine (machine N), while applying the scaling effects defined by each machine.

The factory consists of N machines (nodes), numbered from 1 to N.

Each machine i has:

A value V[i] (quantum operation intensity)

A scaling factor multiplier K[i]

The factory starts with an initial energy of E at machine 1.

Each machine applies a scaling factor to the incoming energy before passing it to the next machine(s). The scaling factor for machine i is calculated as:

scale[i] = 1 - ((K[i] * V[i]) % 100) / 100
This ensures that some energy is lost (or retained) based on the machine's quantum behavior.

If there's a directed edge from machine u to machine v, the energy transferred to v is:

energy[v] = energy[u] * scale[u]
There is no transmission cost for edges—only scaling at the nodes affects energy.

Your task is to compute the maximum energy that can reach machine N starting from machine 1, by following any valid path and applying the scaling rule at each machine.

Input Format
First line contains two integers N and M — the number of machines (nodes) and connections (edges), respectively.

Second line contains N space-separated integers — the values V[1], V[2], ..., V[N] for each machine.

Third line contains N space-separated integers — the K[1], K[2], ..., K[N] values used for energy scaling.

Fourth line contains a single integer E — the initial energy at machine 1.

Next M lines: Each line contains two integers u and v — representing a directed connection from machine u to machine v.

Output Format
Print a single floating-point number representing the maximum energy that can reach the final machine (N) from the starting machine (1), up to 6 decimal places.

Constraints
1 ≤ N ≤ 500

1 ≤ M ≤ 1000

1 ≤ E ≤ 10^8

1 ≤ u, v ≤ N

1 ≤ V[i] ≤ 10^4

1 ≤ K[i] ≤ 100

Sample Testcase 0
Testcase Input
3 2
50 60 70
1 2 3
500
1 2
2 3
Testcase Output
200.000000
Explanation
N = 3 machines, M = 2 edges
Node values = [50, 60, 70]
K values = [1, 2, 3]
Initial energy at machine 1 = 500


Let's calculate the scaling factors:
For machine 1: scale[1] = 1 - (1 * 50 % 100) / 100 = 0.5
For machine 2: scale[2] = 1 - (2 * 60 % 100) / 100 = 0.8
For machine 3: scale[3] = 1 - (3 * 70 % 100) / 100 = -0.9


After calculating the energy flow at each machines considering the scaling factor, the maximum amount of energy reaching to machine 3 is 200.000000 via path 1 -> 2 -> 3.

Sample Testcase 1
Testcase Input
4 5
10 20 30 40
2 3 4 5
1000
1 2
1 3
2 3
2 4
3 4
Testcase Output
640.000000
Explanation
N = 3 machines, M = 2 edges
Node values = [50, 60, 70]
K values = [1, 2, 3]
Initial energy at machine 1 = 500


Let's calculate the scaling factors:
For machine 1: scale[1] = 1 - (2 * 10 % 100) / 100 = 0.8
For machine 2: scale[2] = 1 - (3 * 20 % 100) / 100 = 0.4
For machine 3: scale[3] = 1 - (4 * 30 % 100) / 100 = 0.8
For machine 4: scale[4] = 1 - (5 * 40 % 100) / 100 = 1.0


After calculating the energy flow at each machines considering the scaling factor, the maximum amount of energy reaching to machine 4 is 6400.000000 via path 1 -> 3 -> 4.

Companies
Meesho
Adobe
Goldman Sachs
Topics
Graph
DFS
BFS
Algorithms, Implementation
Data Structure
Graph Theory
'''

#CODE::=>
import sys
import heapq

def calculate_scale(V, K):
    return [1 - (K[i] * V[i] % 100) / 100 for i in range(len(V))]

def max_energy(N, M, V, K, E, edges):
    # Calculate scaling factors
    scale = calculate_scale(V, K)
    
    # Create adjacency list for the graph
    graph = [[] for _ in range(N)]
    for u, v in edges:
        graph[u - 1].append(v - 1)  # Convert to 0-based index

    # Max energy array
    max_energy = [-float('inf')] * N
    max_energy[0] = E  # Initial energy at machine 1

    # Priority queue for Dijkstra's algorithm
    pq = [(-E, 0)]  # Store negative energy for max-heap behavior

    while pq:
        current_energy, u = heapq.heappop(pq)
        current_energy = -current_energy  # Convert back to positive

        # If the current energy is less than the recorded max energy, skip
        if current_energy < max_energy[u]:
            continue

        # Traverse neighbors
        for v in graph[u]:
            # Calculate the energy transferred to machine v
            transferred_energy = current_energy * scale[u]
            if transferred_energy > max_energy[v]:
                max_energy[v] = transferred_energy
                heapq.heappush(pq, (-transferred_energy, v))

    # The maximum energy that can reach machine N (index N-1)
    return max_energy[N - 1]

# Input reading
if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    
    N, M = map(int, data[0].split())
    V = list(map(int, data[1].split()))
    K = list(map(int, data[2].split()))
    E = int(data[3])
    
    edges = [tuple(map(int, line.split())) for line in data[4:4 + M]]

    # Calculate the maximum energy
    result = max_energy(N, M, V, K, E, edges)
    
    # Print the result with 6 decimal places
    print(f"{result:.6f}")
