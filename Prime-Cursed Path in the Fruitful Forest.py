'''Prime-Cursed Path in the Fruitful Forest
Problem Statement
In the Fruitful Forest, there is a grid of trees bearing the most delicious sweet fruits. These trees are arranged neatly in rows, and each row is carefully enclosed by a wire fence. 

The entrance to the forest is located at the top-left corner, and it's the only way to enter. To move deeper into the forest, one must follow a strict path:

From the entrance, you must begin at the first tree in the top-left corner and travel to the end of the first row in right direction.
Once you reach the end of the row, you must move down to the second row and continue your journey in left direction.
This process repeats for every row in the forest, following a zig-zag pattern: top-left -> right-end -> down to second row -> left-end -> down to 3rd row and so on...
As you move through the grid, you need to check the number of fruits on each tree. If the number of fruits on a tree is a prime number, you must skip that tree and continue your journey, as those fruits are cursed. Only the trees with non-prime numbers of fruits are worth stopping for and collecting.

After completing the collection, print the list of non-prime numbers of fruits you encounter. If all numbers encountered are prime, print -1 to indicate that no non-prime fruits were found.
'''
#Samsung adobe goldman sachs
#arra manupulation grid traversal dsa
#CODE::==>>
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def collect_fruits(matrix, M, N):
    result = []
    direction = 1  # 1 for left-to-right, -1 for right-to-left
    
    for i in range(M):
        if direction == 1:
            row = matrix[i]
        else:
            row = matrix[i][::-1]  # Reverse the row for leftward traversal
        
        for num in row:
            if not is_prime(num):  # Collect only non-prime numbers
                result.append(num)
        
        direction *= -1  # Switch direction
    
    return result if result else [-1]  # Return -1 if all are prime

# Read input
M, N = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(M)]

# Compute and output the result
print(" ".join(map(str, collect_fruits(matrix, M, N))))
