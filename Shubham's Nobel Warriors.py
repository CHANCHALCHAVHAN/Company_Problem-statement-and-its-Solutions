'''Problem Statement
In the legendary kingdom of Camelot, the wise King Shubham gathered a brave group of knights to prepare for a fierce battle against a menacing dragon. Each knight possesses a unique strength, symbolized by positive integers that glimmer like stars in the night sky. As they assembled, Shubham faced a critical decision: how to form a team of knights strong enough to defeat the dragon without creating conflicts among them.

The king laid down a crucial rule: no two knights in the same team could have a strength difference of exactly ( K ). This condition ensured harmony among the knights, preventing any quarrels that might weaken their resolve in the face of danger. 

As the knights stood ready, Shubham sought your assistance in counting how many different "Warrior" teams could be formed from the strengths of his knights. With their unique strengths at your disposal, your task is to explore all possible combinations and find the number of valid teams that maintain the king's rule.'''

########################################################################################################################################################################################################################
#CODE
# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import combinations

def count_valid_teams(n, k, strengths):
    def is_valid_team(team):
        # Check if no two knights in the team have a difference of exactly K
        for i in range(len(team)):
            for j in range(i + 1, len(team)):
                if abs(team[i] - team[j]) == k:
                    return False
        return True
    
    valid_team_count = 0
    # Generate all subsets of knights' strengths
    for r in range(1, n + 1):  # From subsets of size 1 to n
        for team in combinations(strengths, r):
            if is_valid_team(team):
                valid_team_count += 1
    
    return valid_team_count

# Input
n, k = map(int, input("Enter N and K: ").split())
strengths = list(map(int, input("Enter knight strengths: ").split()))

# Output
result = count_valid_teams(n, k, strengths)
print("Number of valid teams:", result)
