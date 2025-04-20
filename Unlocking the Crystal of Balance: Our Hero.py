'''PROBLEM STATEMENT==>>
In the kingdom of Numerica, there was an ancient relic known as the Crystal of Balance, hidden deep within the royal treasury. The relic was said to hold the power to bring prosperity or ruin, depending on the wisdom of the one who unlocked its secrets.

The relic's magic could only be activated by solving a unique puzzle engraved on its surface. The puzzle read:

"Divide the crystal’s four-digit magical code into two equal parts of two digits each, such that their combined energy—their product—is minimized. Only then will the crystal's true power reveal itself."

The task seemed simple, but every wrong attempt risked disaster. With no zeros in the code, you, the smartest guy in the kingdom took the challenge to activate the magic.

By the Companies==>
1) Karat
2) Accenture
3) Belzabar

Topis are Covered::=>
Number Theory
Permutation
Greedy Algorithm
Data Structures & Algorithms
'''
#CODE==>
from itertools import permutations

def min_energy(N):
    # Convert number to a string to extract digits
    digits = list(str(N))
    
    # Generate all possible rearrangements of digits
    min_product = float('inf')  # Set initial minimum to a very high value
    
    for perm in permutations(digits):
        # Form two-digit numbers from the permutation
        num1 = int("".join(perm[:2]))  # First two digits
        num2 = int("".join(perm[2:]))  # Last two digits
        
        # Compute product and update minimum
        min_product = min(min_product, num1 * num2)
    
    return min_product

# Input: Four-digit number without zeros
N = int(input().strip())

# Output the minimum energy (product)
print(min_energy(N))
