/********************************************************************************************************************************************************************************************************************************************
Problem Statement
You have an array of size N, and your task is to count the number of pairs (A[i], A[j]) where i < j.

For each pair, you need to check if the bitwise XOR of A[i] and A[j] is less than or equal to the bitwise AND of A[i] and A[j]. In other words, find how many pairs satisfy the condition A[i]⊕A[j] <= A[i]&A[j].

 
Input Format
First Line contains a single integer N representing size of the array 

Second line contains N space-separated integers representing elements of the array.

Output Format
A single integer representing a total number of counts.

Constraints
1 >= N <= 10^5.

0 >= A[i] <= 10^5.

Sample Testcase 0
Testcase Input
4
2 4 32 8
Testcase Output
0
Explanation
There is no pair satisfying the condition.
Sample Testcase 1
Testcase Input
5
7 12 16 10 6
Testcase Output
2
Explanation
Only two pairs is satisfying the above condition:
(1,5) its respective element are (7,6), (7&6) = 6 and (7^6) = 1
 Here (7&6) ≥ (7^6)
(2,4) its respective element are (12,10), (12&10) = 8 and (12^10) = 6
 Here (12&10) ≥ (12^10)
Companies
Zoho
Intel
Facebook
Topics
Math
Bit-Manipulation

********************************************************************************************************************************************************************************************************************************************/

#code

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int count = 0;

    // Brute-force check for all pairs (i < j)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xor_val = A[i] ^ A[j];
            int and_val = A[i] & A[j];
            if (xor_val <= and_val)
                ++count;
        }
    }

    cout << count << '\n';
    return 0;
}





