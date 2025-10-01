/*************************************************************************************************************************************************************************************************************************************************************************************

Problem Statement
You are given a linked list and two integers, N1 and N2. Your task is to determine if any node in the linked list contains a value that is a perfect square of an integer within the range from N1 to N2 (both inclusive).

If there is at least one node in the linked list that holds such a value, the program should output 1. Otherwise, it should output 0.

Input Format
The first line contains two integers separated by a space, N1 and N2, representing the range of values.

The second line contains a single integer, N, indicating the number of elements in the linked list.

The third lines contain N space separated integer, representing values to be inserted into the linked list.

Output Format
Print 1 if any node in the linked list contains a value that is a perfect square of an integer between N1 and N2 (inclusive).

Print 0 if no such value is found in the linked list.

Constraints
1 <= N <= 10^4

1<=N1<=10^2

1<=N2<=10^2

0 <= element <= 10^5

Sample Testcase 0
Testcase Input
2 4
5
1 2 3 4 5
Testcase Output
1
Explanation
For the given test case, the range is from 2 to 4. The linked list has five elements: 1, 2, 3, 4, and 5. When checking for perfect square values within the range, we find that 4 is a perfect square. Therefore, the output is 1, indicating that a perfect square exists in the linked list.
Sample Testcase 1
Testcase Input
4 6
3
100 200 300
Testcase Output
0
Explanation
In the given test case, the range is from 4 to 6 (inclusive). The linked list contains three elements: 100, 200, and 300. However, none of these values are perfect squares within the range, so the output is 0.
Companies
Topics
Unordered Set
Pointers
Linked List
*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <iostream>
#include <unordered_set>
using namespace std;

// Define the structure for a linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end of the linked list
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

// Function to check if any node contains a perfect square in the given range
int containsPerfectSquare(Node* head, int N1, int N2) {
    unordered_set<int> perfectSquares;
    for (int i = N1; i <= N2; ++i) {
        perfectSquares.insert(i * i);
    }

    Node* temp = head;
    while (temp) {
        if (perfectSquares.count(temp->data))
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int N1, N2;
    cin >> N1 >> N2;

    int N;
    cin >> N;

    Node* head = nullptr;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        insert(head, val);
    }

    cout << containsPerfectSquare(head, N1, N2) << endl;

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
