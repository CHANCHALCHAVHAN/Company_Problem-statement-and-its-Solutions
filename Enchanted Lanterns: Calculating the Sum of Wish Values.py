'''PROBLME STATEMENT::==>>
In a village nestled at the foot of a mountain, skilled artisans crafted magical lanterns that glowed brighter the higher they were carried. To create the most powerful lantern, the village elder needed to calculate its "wish value (absolute difference between maximum and minimum brightness)" by comparing two factors for each mountain peak:

The maximum brightness from the current peak to the highest point.
The minimum brightness from the start to that peak.
The elder had to calculate the sum of these wish values to determine the lantern's power. The village eagerly awaited to see if the elder could craft the most powerful lantern ever made.

##BY THE COMPANIES::==>
1)TCS
2)CAPGEMINI
3)COGNIZANT

##TOPICS COVERED::=>
Array
Suffix Array
Prefix Array
Optimization
Data Structures & Algorithms

'''
##CODE::

def calculate_wish_value(N, A):
    # Step 1: Compute suffix maximums
    suffix_max = [0] * N
    suffix_max[N - 1] = A[N - 1]
    for i in range(N - 2, -1, -1):
        suffix_max[i] = max(suffix_max[i + 1], A[i])

    # Step 2: Compute prefix minimums and wish values
    prefix_min = [0] * N
    prefix_min[0] = A[0]
    total_wish_value = 0
    
    for i in range(1, N):
        prefix_min[i] = min(prefix_min[i - 1], A[i])

    # Step 3: Calculate wish values
    for i in range(N):
        total_wish_value += abs(suffix_max[i] - prefix_min[i])

    return total_wish_value

# Input reading
N = int(input())
A = list(map(int, input().split()))

# Compute and print result
print(calculate_wish_value(N, A))
