'''
PROBLEM STATEMENT::==>
In a futuristic space station, a garden of genetically engineered plants generates energy pods, represented as an array E of size N, where E[i] is the number of energy pods produced by the i-th plant. Commander Zeta must divide the garden into three continuous zones: Alpha, Beta and Gamma where the zone size of alpha must be same as the zone size of gamma.

Alpha and Gamma for the Energy Council, and Beta for the Defense Alliance. Since Zone Beta is inefficient and wastes energy, Zeta decides to ensure its energy is always less than the combined energy of Zones Alpha and Gamma.
Determine the total number of ways this division can be accomplished while adhering to this condition.

Input Format
The first line contains an integer N representing the number of plants.

The second line contains N space separated integers, where the i-th integer represents the energy pods produced by the i-th plant.

Output Format
Print a single integer representing the total number of ways to divide the garden into the three zones such that the sum of energy pods in Alpha and Gamma combined is greater than the energy pods in Beta.

Constraints
1 <= N <= 10^5

1 <= E[i] <= 10^5

Sample Testcase 0
Testcase Input
4
3 3 3 3
Testcase Output
0
Explanation
For the array [3, 3, 3, 3], there are no valid divisions possible.

Sample Testcase 1
Testcase Input
5
1 2 3 4 5
Testcase Output
1
Explanation
For the array [1, 2, 3, 4, 5], there will be only one possible division.
Alpha: [1, 2], Beta: [3], Gamma: [4, 5] → (3 + 9 > 3)
'''

'''
COMPANIES::=>
Cognizant
Capgemini
Accenture
'''
'''
Topics
Array
Data Structures & Algorithms
'''
#CODE :=>
def count_divisions(N, E):
    # Calculate prefix sums
    prefix_sum = [0] * (N + 1)
    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + E[i - 1]

    total_ways = 0
    for alpha_size in range(1, N // 2 + 1):
        gamma_start = N - alpha_size + 1
        if gamma_start <= alpha_size + 1:
            break

        alpha_energy = prefix_sum[alpha_size]  # Sum of Alpha zone
        gamma_energy = prefix_sum[N] - prefix_sum[N - alpha_size]  # Sum of Gamma zone

        beta_energy = prefix_sum[gamma_start - 1] - prefix_sum[alpha_size]

        if alpha_energy + gamma_energy > beta_energy:
            total_ways += 1

    return total_ways


# Input reading
N = int(input())
E = list(map(int, input().split()))

# Output the result
print(count_divisions(N, E))
