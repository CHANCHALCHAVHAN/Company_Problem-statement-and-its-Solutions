'''
Problem Statement
In the technologically advanced city of Neotera, a vast network of floating bridges connects its hovering stations across the sky. These bridges aren’t just architectural marvels — they are woven with encrypted codes that safeguard inter-station transport and communications.

The bridge codes, known as CipherStrings, are crafted from mysterious, ancient algorithms and are thought to be unbreakable. Each code is a string of lowercase English letters, deeply tied to the city's defense protocols.

Recently, the city’s master AI, ORION, detected strange disturbances — loops forming within the bridge network that reflect a symmetrical frequency signal, echoing back like a perfect palindrome. ORION suspects these loops are remnants of an ancient "Security Override Mechanism" known as Secure Loops — defensive circuits once used to reset and shield the city during invasions.

To activate this hidden defense mechanism, ORION must locate at least one of these Secure Loops, defined by a sacred triad of conditions:

The loop must connect three or more stations — forming a proper cycle.

The concatenated bridge codes along the loop must form a palindrome — an echo in the data stream.

That palindromic echo must also be a valid rotation of any single bridge code used in the entire network — revealing its origin and authenticity.

You, the city’s last living Bridgewalker, have been summoned to work alongside ORION. Scan the floating network, analyze the encrypted bridges, and uncover whether at least one such Secure Loop still exists in Neotera's ancient infrastructure.

If you find one, the city may once again awaken its ancient defenses. If not… the skies may fall silent forever.

Input Format
First line of input contains an integer N, representing the number of stations.

Second line of input contains an integer M, representing the number of bridges.

From third line, each containing a list of M bridges, where each bridge is defined as (u, v, s), representing a directed bridge from station u to v with encrypted code s.

Output Format
Print "YES" if there exists at least one secure loop. Otherwise, print "NO".

Constraints
1 ≤ N ≤ 10^5

1 ≤ M ≤ 10^5

1 ≤ |s| ≤ 10^3

Sample Testcase 0
Testcase Input
4
6
1 2 ab
2 3 b
3 1 a
1 4 abc
4 1 cba
2 4 aabb
Testcase Output
YES
Explanation
The cycle 1 → 2 → 3 → 1 forms "abba", which:
Is a palindrome; YES
Is a rotation of "aabb" ; YES
So now the output is "YES".

Sample Testcase 1
Testcase Input
5
7
1 2 abc
2 3 def
3 4 ed
4 1 cba
1 4 ghi
4 5 ihg
5 1 baabcdefecd
Testcase Output
NO
Explanation
The cycle 1 → 2 → 3 → 4 → 1 forms "abcdefedcba", which:


Is a palindrome; YES


Is a rotation of "baabcdefecd"; NO


So now the output is "NO"

Companies
Topics
DFS
Hashing
Traversals
String
Graph
'''

#Code:=>
from collections import defaultdict

def is_palindrome(s):
    """Check if a given string is a palindrome."""
    return s == s[::-1]

def get_rotations(s):
    """Generate all possible rotations of a string."""
    return {s[i:] + s[:i] for i in range(len(s))}

def detect_cycle(graph, node, stack, visited, edges, all_codes):
    """Perform DFS to detect cycles and validate Secure Loops."""
    if node in stack:
        # Cycle found, extract cycle path
        cycle_start = stack.index(node)
        cycle = stack[cycle_start:]
        cycle_string = "".join(edges[u][v] for u, v in zip(cycle, cycle[1:] + [cycle[0]]))
        
        # Check Secure Loop conditions
        if is_palindrome(cycle_string) and any(cycle_string in get_rotations(code) for code in all_codes):
            return True
        return False

    visited.add(node)
    stack.append(node)

    for neighbor in graph[node]:
        if detect_cycle(graph, neighbor, stack, visited, edges, all_codes):
            return True

    stack.pop()
    return False

def find_secure_loop(n, m, bridges):
    """Main function to check for the existence of Secure Loops."""
    graph = defaultdict(list)
    edges = defaultdict(dict)
    all_codes = set()

    for u, v, s in bridges:
        graph[u].append(v)
        edges[u][v] = s
        all_codes.add(s)

    visited = set()
    
    for node in range(1, n + 1):
        if node not in visited and detect_cycle(graph, node, [], visited, edges, all_codes):
            return "YES"

    return "NO"

# Reading input
n = int(input())
m = int(input())
bridges = [tuple(input().split()) for _ in range(m)]
bridges = [(int(u), int(v), s) for u, v, s in bridges]

# Output result
print(find_secure_loop(n, m, bridges))
