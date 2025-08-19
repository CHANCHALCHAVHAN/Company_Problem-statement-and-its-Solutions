/*
Problem Statement
In an assembly line at St. Mary School, N students stand in ascending order of their heights.
Nidhi Sharma, a teacher, has k queries, where she asks about the height H of a particular student.

Your task is to determine the position (0-based index) of the student in the line if they are present.
If the student is absent, your task is to determine the correct position where that student should be placed to maintain the ascending order.

Input Format
The first line contains an integer N, the total number of students.

The second line contains N space-separated integers representing the heights of the students (in ascending order).

The third line contains an integer k, the number of queries.

The next k lines each contain a single integer H, representing the height of the student being enquired.

Output Format
For each query, print the appropriate 0-based index on a new line:

If the student is present, print their index.

If absent, print the index at which they should be inserted to maintain the order.

Constraints
1<=k<=103

1<=N<=108

1<=hi<=104

1<=H<=104

Sample Testcase 0
Testcase Input
5
12 34 45 89 110
5
23
45
11
90
150
Testcase Output
1
2
0
4
5
Explanation
23: The height 23 is not present in the list, but it should be placed between 12 and 34 to maintain ascending order. So, its correct position (0-based index) is 1.

45: The height 45 is present in the list at position 2 (0-based index), so the correct position (0-based index) is 2.

11: The height 11 is not present, and it would be placed before 12. So, its correct position (0-based index) is 0.

90: The height 90 is not present, but it should be placed after 89 and before 110. So, its correct position (0-based index) is 4.

150: The height 150 is not present and would be placed after 110. So, its correct position (0-based index) is 5.

Sample Testcase 1
Testcase Input
4
1 3 5 6
2
5
7
Testcase Output
2
4
Explanation
The first query asks for the position of the student with a height 5. Since 5 is present in the list at position 2 (0-based index).

The second query asks for the position of the student with height 7. Since 7 is not present, but it would be placed after 6 to maintain ascending order, its correct position (0-based index) is 4.

Companies
Coursera
MakeMyTrip
Topics
Sorting
Searching
Binary Search
*/
//CODE::=>

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) cin >> heights[i];

    int k;
    cin >> k;

    while (k--) {
        int H;
        cin >> H;

        // find the first index where heights[idx] >= H
        int idx = lower_bound(heights.begin(), heights.end(), H) - heights.begin();

        // check if found exact
        if (idx < N && heights[idx] == H) 
            cout << idx << "\n";
        else 
            cout << idx << "\n";  // insertion index
    }

    return 0;
}
