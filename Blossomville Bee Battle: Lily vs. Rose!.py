'''PROBLEM STATEMENT BY GOLDMAN SACHS , AMAZON ,JP MARGAN , INTEL::=>>
Problem Statement
In the serene village of Blossomville, two dedicated gardeners, Lily and Rose, took pride in their flourishing gardens. Lily's garden was adorned with vibrant flowers, while Rose's garden was filled with aromatic herbs. On a beautiful sunny day, they decided to have a friendly competition to determine whose garden attracted more bees.

Lily created a list1 of N1 elements of the types of flowers she had and their quantities. Rose did the same with her herbs and created a list2 of N2 elements. They then compared their lists.

For each type of flower in Lily's garden, they compared its quantity with the quantity of the same type of herb in Rose's garden. If Lily had more of a particular flower than Rose had herbs, Lily noted down that flower in her notebook.

Lily ensured that her final list of flowers maintained the same order as they bloomed in her garden, showcasing her beautiful array of flowers.

Given two lists of integers representing the flower quantities in Lily's garden and the herb quantities in Rose's garden, you need to determine which flowers Lily should note down in her notebook based on the above criteria.

Input Format
The first line contains an integer N1, the number of flowers in Lily's garden.

The second line contains N1 space-separated integers representing the quantities of each flower in Lily's garden.

The third line contains an integer N2, the number of herbs in Rose's garden.

The fourth line contains N2 space-separated integers representing the quantities of each herb in Rose's garden.

Output Format
Print the list of space-separated flowers that Lily should note down in her notebook, preserving the order as they appear in Lily's garden.

If there are no such flowers, print -1.

Constraints
1 <= N1 <= 10^3

1 <= elementsoflist1 <= 10^4

1 <= N2 <= 10^3

1 <= elementsoflist2 <= 10^4

Sample Testcase 0
Testcase Input
5
1 2 3 2 1
5
2 3 4 3 2
Testcase Output
1 1
Explanation
Flower 1 appears twice in Lily's garden but not at all in Rose's garden. Soit is included.
Flower 2 appears twice in Lily's garden and twice in Rose's garden, so it is not included.
Flower 3 appears once in Lily's garden and twice in Rose's garden, so it is not included.
Flower 1 appears twice in Lily's garden but not at all in Rose's garden. Soit is included.
The final list of flowers maintained the same order as they bloomed in Lily's garden

Sample Testcase 1
Testcase Input
3
4 5 6
3
1 2 3
Testcase Output
4 5 6
Explanation
All flowers in Lily's garden are more frequent than any herb in Rose's garden.
'''

#################################################################################################################################################################################################################3
#CODE::==>>
from collections import Counter

def find_noted_flowers(lily_quantities, rose_quantities):
    # Count the frequency of each flower in Lily's and Rose's lists
    lily_counter = Counter(lily_quantities)
    rose_counter = Counter(rose_quantities)
    
    # Initialize the result list
    noted_flowers = []
    
    # Check each flower in Lily's garden
    for flower in lily_quantities:
        if lily_counter[flower] > rose_counter[flower]:
            noted_flowers.append(flower)
    
    # Return the result or -1 if no flowers meet the criteria
    return noted_flowers if noted_flowers else [-1]

# Input
n1 = int(input())
lily_list = list(map(int, input().split()))
n2 = int(input())
rose_list = list(map(int, input().split()))

# Output the result
result = find_noted_flowers(lily_list, rose_list)
print(" ".join(map(str, result)))
