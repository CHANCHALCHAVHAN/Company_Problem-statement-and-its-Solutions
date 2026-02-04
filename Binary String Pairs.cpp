/*
Problem Statement
Meet Alice, a brilliant computer scientist who loves to solve coding challenges. She's currently working on a problem related to binary strings.

Alice has a binary string "S" of length N, where N is a power of 2. She wants to find the number of pairs (i, j) such that 0 ≤ i, j < N and:

S[ i ] | S[ j ] = S[ i ] & S[ j ]
Alice is struggling to develop an efficient algorithm to solve this problem. Can you help Alice find the number of pairs that satisfy the given conditions?

Note: The sum of N over all test cases does not exceed 2^20.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The second line of each test case contains an integer N denoting the length of the string S. N is a power of 2.

The third line of each test case contains a binary string S of length N.

Output Format
For each test case, output the number of pairs that satisfy the given conditions.

Constraints
1 ≤ T ≤ 10^3

2 ≤ N ≤ 10^6

Sample Testcase 0
Testcase Input
1
4
1101
Testcase Output
10
Explanation
For the given input:
T = 1 (1 test case)
N = 4 (length of the string S)
S = "1101" (binary string)
To find pairs (i,j)(i, j)(i,j) such that S[i] | S[j] = S[i] & S[j], both S[i] and S[j] must be the same.


Valid pairs:
'1' pairs: (0,0), (0,1), (1,0), (1,1), (0,3), (1,3), (3,0), (3,1), (3,3)
'0' pairs: (2,2)


Total valid pairs: 10
Thus, the output is 10.

Sample Testcase 1
Testcase Input
3
2
01
4
1001
8
00010001
Testcase Output
2
8
40
Explanation
Input:
2

01
N = 2 (length of the string S)
S = "01"
Valid pairs:
For '0': (0, 0)
For '1': (1, 1)
Only pairs where S[i] = S[j] satisfy the condition.
Total valid pairs: 2 (i.e., (0, 0) and (1, 1))
Output: 2


Input:
4
1001
N = 4 (length of the string S)
S = "1001"
Valid pairs:
For '1': (0, 0), (0, 3), (3, 0), (3, 3)
For '0': (1, 1), (1, 2), (2, 1), (2, 2)
Total valid pairs: 8 (i.e., (0, 0), (0, 3), (3, 0), (3, 3), (1, 1), (1, 2), (2, 1), (2, 2))
Output: 8


Input:
8

00010001
N = 8 (length of the string S)
S = "00010001"
Valid pairs:
For '0': (0, 0), (0, 1), (0, 2), (0, 4), (0, 5), (0, 6), (1, 0), (1, 1), (1, 2), (1, 4), (1, 5), (1, 6), ... (total 36 pairs involving '0')
For '1': (3, 3), (3, 7), (7, 3), (7, 7) (total 4 pairs involving '1')
Total valid pairs: 40 (36 pairs for '0' and 4 pairs for '1')
Output: 40


Test Case 1 Output: 2
Test Case 2 Output: 8
Test Case 3 Output: 40

Companies
Snapchat
Intuit
Microsoft
Paypal
Topics
String
Bit Manipulation
Dynamic Programming

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int user_logic(int n, string s) {
    long long count0 = 0, count1 = 0;
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }
    // Total valid pairs = count0^2 + count1^2
    return count0 * count0 + count1 * count1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> results(T);

    for (int i = 0; i < T; ++i) {
        int n;
        string s;
        cin >> n >> s;
        results[i] = user_logic(n, s);
    }

    for (auto res : results) {
        cout << res << "\n";
    }

    return 0;
}
