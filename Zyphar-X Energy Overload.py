'''
Problem Statement
The distant planet Zyphar-X is home to an advanced civilization that thrives on a unique form of cosmic energy. This energy is captured by massive energy pillars, towering structures designed to absorb and store cosmic radiation. However, due to irregular planetary rotations and solar flares, energy doesn’t distribute evenly across the pillars, leading to gaps where excess energy pools between them. These pools, if properly harnessed, can supply unlimited power to Zyphar-X’s cities.

But there's a problem…

If the energy accumulation at any location exceeds a critical threshold, an energy overload could occur, triggering an explosion that could wipe out entire regions! The Zypharian scientists have tasked you, their top energy engineer, with solving this problem.

Your Mission:

You are given an array energyPillars[], where each element represents the height of an energy pillar in energy units. Each pillar has a width of 1 unit.

You must determine:

Total energy trapped between the pillars, representing the amount of cosmic energy that can be safely harvested.
The tallest single column of energy accumulation, which signifies the highest unstable energy concentration.
If any single column of energy reaches or exceeds a danger threshold D, return -1 immediately to prevent a catastrophic energy meltdown.
Input Format
The first line of input contains a single integer N, representing the number of energy pillar.

The secod line contains N space separated integers representing the height of each pillar in energy units.

The third line contains a single integer D, representing the danger threshold for energy overload.

Output Format
In first line, print an integer representing the maximum energy trapped.

In second line, print the tallest single column of energy accumulation

Constraints
1 ≤ N ≤ 10^6

0 ≤ energyPillars[i] ≤ 10^7

1 ≤ D ≤ 10^6

Sample Testcase 0
Testcase Input
6
4 1 0 2 1 5
3
Testcase Output
-1
Explanation

Pillar (Blue); 1 unit Energy(Pattern).

Total Energy Trapped: -1
Max Single Column Accumulation: 4 units (since the tallest trapped energy column is 4)
Since 4 > D (3), it is not safe to proceed.

Sample Testcase 1
Testcase Input
6
6 2 1 3 1 5
6
Testcase Output
13
4
Explanation



Pillar (Blue); 1 unit Energy(Pattern).


Total Energy trapped: 13
The energy gets trapped between pillars, the tallest trapped energy column reaches 4, which does not exceeds the danger threshold D = 6.


 

Companies
Amazon
Mastercard
Meesho
Topics
Two Pointers
Prefix Array
Suffix Array
Monotonic Stack
Greedy
Sliding Window
Array

'''

#python code 
def calculate_trapped_energy(N, energyPillars, D):
    if N < 3:
        return 0, 0  # No space to trap energy

    left, right = 0, N - 1
    left_max, right_max = energyPillars[left], energyPillars[right]
    trapped_energy = 0
    max_accumulation = 0

    while left < right:
        if energyPillars[left] < energyPillars[right]:
            left_max = max(left_max, energyPillars[left])
            accumulation = left_max - energyPillars[left]
            trapped_energy += accumulation
            max_accumulation = max(max_accumulation, accumulation)
            left += 1
        else:
            right_max = max(right_max, energyPillars[right])
            accumulation = right_max - energyPillars[right]
            trapped_energy += accumulation
            max_accumulation = max(max_accumulation, accumulation)
            right -= 1

        if max_accumulation >= D:
            return -1, None  # Immediate danger detected

    return trapped_energy, max_accumulation

# Input handling
N = int(input().strip())
energyPillars = list(map(int, input().strip().split()))
D = int(input().strip())

# Compute results
result_trapped, result_max_accumulation = calculate_trapped_energy(N, energyPillars, D)

# Output results
print(result_trapped)
if result_trapped != -1:
    print(result_max_accumulation)
