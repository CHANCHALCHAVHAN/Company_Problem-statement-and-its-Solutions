/*
Problem Statement
Implement a program that takes two linked lists as input and finds the value of the first common node between them, considering that all subsequent nodes are also the same.

If there is a common node, return its value; otherwise, return -1.

Input Format
The first line takes two space separated integers representing the size of linked list 1 and size of linked list 2 respectively.

The second line takes space separated integers representing elements of linked list 1.

The third line takes space separated integers representing elements of linked list 2.

Output Format
Print the value of the first common node between the two linked lists.

Constraints
1 ≤ length(linked list 1) + length(linked list 2) ≤ 10^5

-10^3 ≤ value ≤ 10^3.

Sample Testcase 0
Testcase Input
3 4
100 45 602
108 2 45 602
Testcase Output
45
Explanation
There are two linked lists. 
The first linked list has 3 nodes with values 100, 45, and 602.
The second linked list has 4 nodes with values 108, 2, 45, and 602. When we compare the two lists, we can see that the first common node is the node with a value of 45. And both lists have this value, and all subsequent nodes have the same values as well.

Sample Testcase 1
Testcase Input
4 5
1 2 3 4 
1 2 3 4 5
Testcase Output
-1
Explanation
Linked list 1: 1 -> 2 -> 3 -> 4 
Linked list 2: 1 -> 2 -> 3 -> 4 -> 5 
Since both linked lists have the same elements up to the fourth node, the first common node is the first node with a value of 1.
However, the condition for the common node in the code specifies that all subsequent elements should also be the same. 
In this case, the subsequent elements are 2, 3, 4(1st list) and 2, 3, 4, 5(2nd list) which are different. 
Therefore, there is no common node that satisfies the condition, and the output of the code is -1.

Companies
jp morgan
Infosys
Tinkitive
Topics
Pointers
Linked List

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the first common node with identical suffix
int findFirstCommonNode(const vector<int>& list1, const vector<int>& list2) {
    int n = list1.size();
    int m = list2.size();
    int i = n - 1;
    int j = m - 1;

    // Traverse from the end to find the longest common suffix
    while (i >= 0 && j >= 0 && list1[i] == list2[j]) {
        i--;
        j--;
    }

    // If any common suffix exists, return the first node of that suffix
    if (i < n - 1 && j < m - 1) {
        return list1[i + 1];
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> list1(n), list2(m);
    for (int i = 0; i < n; ++i) cin >> list1[i];
    for (int i = 0; i < m; ++i) cin >> list2[i];

    int result = findFirstCommonNode(list1, list2);
    cout << result << endl;

    return 0;
}
